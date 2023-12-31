% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/load_bulk_EC.R
\name{load_bulk_EC}
\alias{load_bulk_EC}
\title{Create a list containing the equivalence classes objects for the bulk RNA-seq data}
\usage{
load_bulk_EC(path_to_eq_classes = NULL, n_cores = NULL)
}
\arguments{
\item{path_to_eq_classes}{a vector of length equals to the number of samples: 
each element indicates the path to the equivalence classes counts of the respective sample
(i.e., aux_info/eq_classes.txt.gz file).}

\item{n_cores}{the number of cores to parallelize the tasks on.
Since parallelization is at the sample level (each sample is parallelized on a thread), 
we suggest setting n_cores to the number of sample, as set by default if 'n_cores' is not specified.}
}
\value{
A \code{list} object.
}
\description{
\code{load_bulk_EC} imports the bulk equivalence classes (computed by salmon), and stores them into a list.
}
\examples{
# load internal data to the package:
data_dir = system.file("extdata", package = "DifferentialRegulation")

# specify samples ids:
sample_ids = paste0("sample", seq_len(6))

# Equivalence classes:
equiv_classes_files = file.path(data_dir, "salmon", sample_ids, "aux_info/eq_classes.txt.gz")
file.exists(equiv_classes_files)

# load EC:
EC_list = load_bulk_EC(path_to_eq_classes = equiv_classes_files,
                       n_cores = 2)

}
\seealso{
\code{\link{load_bulk_US}}, \code{\link{DifferentialRegulation_bulk}}
}
\author{
Simone Tiberi \email{simone.tiberi@unibo.it}
}
