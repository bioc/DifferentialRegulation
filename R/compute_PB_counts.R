#' Discover differentially regulated genes
#'
#' \code{compute_PB_counts} computese the pseudo-bulk (PB) counts, 
#' needed to perform differential testing by \code{\link{DifferentialRegulation}}.
#' 
#' @param sce a \code{SingleCellExperiment} object, computed via \code{\link{load_USA}}.
#' @param EC_list a \code{list}, computed via \code{\link{load_EC}}.
#' @param design a \code{\linkS4class{data.frame}} indicating the design of the experiment with one row for each sample;
#' 'design' must contain a column with the sample id and one with the group id.
#' @param sample_col_name a character ("sample" by default), indicating the column name of the 'design' element which stores the sample id.
#' @param group_col_name a character ("group" by default), indicating the column name of the 'design' element which stores the group id.
#' @param sce_cluster_name a character ("cell_type" by default), indicating the name of the 'colData(sce)' element, 
#' which stores the cluster id of each cell (i.e., colData(sce)$name_cluster).
#' @param min_cells_per_cluster cell cluster (e.g., cell-type) filter.
#' 'min_cells_per_cluster' is the minimum number of cells, across all samples and groups, for a cell cluster to be considered.
#' Cell clusters with less than 'min_cells_per_cluster' cells will not be analyzed.  
#' @param min_counts_per_gene_per_group minimum number of counts per gene, in each cell, across all samples of every group.
#' In each cell cluster, only genes with at least 'min_counts_per_gene_per_group' counts in both groups of samples will be analyzed.  
#' @param min_counts_ECs equivalence classes (ECs) filter.
#' 'min_counts_ECs' indicates the minimum number of counts (across all cells in a cell cluster) for each equivalence class;
#' by default all ECs are considered (min_counts_ECs = 0).
#' ECs with less or equal than 'min_counts_ECs' will be discarded.
#' Increasing 'min_counts_ECs' will marginally decrease computational cost computational at the cost of a marginal loss in performance.
#' 
#' @return A \code{list} of objects required perform differential testing by \code{\link{DifferentialRegulation}}.
#' 
#' @examples
#' # load internal data to the package:
#' data_dir = system.file("extdata", package = "DifferentialRegulation")
#' 
#' # specify samples ids:
#' sample_ids = paste0("organoid", c(1:3, 16:18))
#' # set directories of each sample input data (obtained via alevin-fry):
#' base_dir = file.path(data_dir, "alevin-fry", sample_ids)
#' file.exists(base_dir)
#' 
#' # set paths to USA counts, cell id and gene id:
#' # Note that alevin-fry needs to be run with '--use-mtx' option
#' # to store counts in a 'quants_mat.mtx' file.
#' path_to_counts = file.path(base_dir,"/alevin/quants_mat.mtx")
#' path_to_cell_id = file.path(base_dir,"/alevin/quants_mat_rows.txt")
#' path_to_gene_id = file.path(base_dir,"/alevin/quants_mat_cols.txt")
#'
#' # load USA counts:
#' sce = load_USA(path_to_counts,
#'                path_to_cell_id,
#'                path_to_gene_id,
#'                sample_ids)
#'  
#' # define the design of the study:
#' design = data.frame(sample = sample_ids,
#'                     group = c( rep("3 mon", 3), rep("6 mon", 3) ))
#' design
#' 
#' # cell types should be assigned to each cell;
#' # here we load pre-computed cell types:
#' path_to_DF = file.path(data_dir,"DF_cell_types.txt")
#' DF_cell_types = read.csv(path_to_DF, sep = "\t", header = TRUE)
#' matches = match(colnames(sce), DF_cell_types$cell_id)
#' sce$cell_type = DF_cell_types$cell_type[matches]
#' 
#' # set paths to EC counts and ECs:
#' path_to_EC_counts = file.path(base_dir,"/alevin/geqc_counts.mtx")
#' path_to_EC = file.path(base_dir,"/alevin/gene_eqclass.txt.gz")
#' 
#' # load EC counts:
#' EC_list = load_EC(path_to_EC_counts,
#'                   path_to_EC,
#'                   path_to_cell_id,
#'                   path_to_gene_id,
#'                   sample_ids)
#' 
#' PB_counts = compute_PB_counts(sce = sce,
#'                               EC_list = EC_list,
#'                               design =  design,
#'                               sample_col_name = "sample",
#'                               group_col_name = "group",
#'                               sce_cluster_name = "cell_type",
#'                               min_cells_per_cluster = 100, 
#'                               min_counts_per_gene_per_group = 20)
#'
#' @author Simone Tiberi \email{simone.tiberi@unibo.it}
#' 
#' @seealso \code{\link{load_EC}}, \code{\link{load_USA}}, \code{\link{DifferentialRegulation}}, \code{\link{plot_pi}}
#' 
#' @export
compute_PB_counts = function(sce,
                             EC_list,
                             design,
                             sample_col_name = "sample",
                             group_col_name = "group",
                             sce_cluster_name = "cell_type",
                             min_cells_per_cluster = 100, 
                             min_counts_per_gene_per_group = 20,
                             min_counts_ECs = 0){
  if(!is.numeric(min_counts_per_gene_per_group)){
    message("'min_counts_per_gene_per_group' must be numeric.")
  }
  if(min_counts_per_gene_per_group < 10){
    message("'min_counts_per_gene_per_group' must be at least 10.")
  }
  if(!is.numeric(min_counts_ECs)){
    message("'min_counts_ECs' must be numeric.")
  }
  
  if( !is.data.frame(design) ){
    message("'design' must be a data.frame object")
    return(NULL)
  }
  # select the column of design which is called 'group_col_name'
  if( !(group_col_name %in% colnames(design)) ){
    message("Column ", group_col_name, " missing in 'design'")
    message("'group_col_name' should specify the column name of 'design' containing the group id of each sample")
    return(NULL)
  }
  sel_col = which(group_col_name == colnames(design))
  if( length(sel_col) > 1.5 ){
    message( length(sel_col) , " columns from 'design' are called ", group_col_name)
    message("Remove duplicated columns from 'design' and provide a unique column for the group id")
    return(NULL)
  }
  
  groups = factor(design[, sel_col ])
  levels_groups = levels(groups)
  n_groups = length(levels_groups)
  numeric_groups = as.numeric(groups)
  
  if(n_groups > 2.5){
    message("We detected ", n_groups, " groups in the design")
    message("At present, only 2 group comparisons are implemented")
    return(NULL)
  }
  
  sample_ids_per_group = lapply(seq_len(n_groups), function(gr){
    which(numeric_groups == gr) - 1 # -1 !
  })
  n_samples_per_group = vapply(sample_ids_per_group, length, FUN.VALUE = integer(1) )
  
  # select the column of design which is called 'sample_col_name'
  if( !(sample_col_name %in% colnames(design)) ){
    message("Column ", sample_col_name, " missing in 'design'")
    message("'sample_col_name' should specify the column name of 'design' containing the group id of each sample")
    return(NULL)
  }
  sel_col = which(sample_col_name == colnames(design))
  if( length(sel_col) > 1.5 ){
    message( length(sel_col) , " columns from 'design' are called ", sample_col_name)
    message("Remove duplicated columns from 'design' and provide a unique column for the group id")
    return(NULL)
  }
  samples = design[, sel_col ]
  n_samples = length(samples)
  
  # cluster ids:
  sel = which(names(colData(sce)) == sce_cluster_name)
  if( length(sel) == 0 ){
    message("'sce_cluster_name' not found in names(colData(sce))")
    return(NULL)
  }
  if( length(sel) > 1 ){
    message("'sce_cluster_name' found multiple times in names(colData(sce))")
    return(NULL)
  }
  clusters = factor(colData(sce)[[sel]])
  n_clusters = nlevels(clusters)
  # clusters = as.integer(as.numeric(clusters)-1)
  
  # select cell types with at least xx cells across all samples
  table_clusters = table(clusters)
  cluster_ids_kept = names(table_clusters[table_clusters >= min_cells_per_cluster])
  
  message("the following cell clusters (e.g., cell types) have more than ", min_cells_per_cluster, " cells and will be analyzed:")
  message(paste(cluster_ids_kept, collapse = " --- "))
  
  n_cell_types = length(cluster_ids_kept)
  if( n_cell_types == 0 ){
    return(NULL)
  }
  
  #### #### #### #### #### #### #### #### #### #### #### #### #### #### #### #### #### #### #### 
  # remove empty ECs and ECs with < min_counts_ECs counts
  #### #### #### #### #### #### #### #### #### #### #### #### #### #### #### #### #### #### #### 
  # get cells with selected cell types in sce
  cells_sel = colnames(sce[,clusters %in% cluster_ids_kept])
  
  # compute pseudo-bulk counts aggregating counts across cells:
  counts = lapply(EC_list[[1]], function(x){
    sel = rownames(x) %in% cells_sel
    colSums(x[sel,])
  })
  
  # select non-zero ECs and ECs with > min_counts_ECs counts
  sel_non_zero_EC = lapply(counts, function(x){
    x > min_counts_ECs 
  })
  # usually, ~ 1/3 of EC counts are 0 and should be removed.
  rm(cells_sel); rm(counts)
  
  # filter EC_list object:
  EC_list[[1]] = lapply( seq_len(n_samples), function(i){
    EC_list[[1]][[i]][,sel_non_zero_EC[[i]] ]
  })
  # filter counts:
  EC_list[[2]] = lapply( seq_len(n_samples), function(i){
    EC_list[[2]][[i]][sel_non_zero_EC[[i]] ]
  })
  # filter counts:
  EC_list[[3]] = lapply( seq_len(n_samples), function(i){
    EC_list[[3]][[i]][sel_non_zero_EC[[i]] ]
  })
  
  rm(sel_non_zero_EC)
  #### #### #### #### #### #### #### #### #### #### #### #### #### #### #### #### #### #### #### 
  # get pseudo-bulk EC counts and USA counts from sce:
  #### #### #### #### #### #### #### #### #### #### #### #### #### #### #### #### #### #### #### 
  PB_data_prepared = lapply(cluster_ids_kept,
                            prepare_PB_counts,
                            sce = sce, clusters = clusters,
                            n_samples = n_samples, EC_list = EC_list)
  
  gene_ids_sce = rownames(sce)
  
  res = list(PB_data_prepared,
             min_counts_per_gene_per_group,
             n_samples,
             n_samples_per_group,
             numeric_groups,
             cluster_ids_kept,
             sample_ids_per_group,
             n_groups,
             gene_ids_sce,
             n_cell_types,
             levels_groups,
             min_counts_ECs,
             EC_list[[2]],
             EC_list[[3]],
             EC_list[[4]],
             length(EC_list[[4]]))
  
  res
}