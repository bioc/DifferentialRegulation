# Generated by using Rcpp::compileAttributes() -> do not edit by hand
# Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

Rcpp_MCMC <- function(n_samples, n_genes, n_groups, n_genes_keep, keep_genes_id, numeric_groups, sample_ids_per_group, n_samples_per_group, N_MCMC, burn_in, PI_gene_times_SU, PI_SU, list_X_unique, list_EC_gene_id, counts, MCMC_bar_pi_1, MCMC_bar_pi_2, MCMC_bar_pi_3, delta_SU, mean_log_delta, sd_log_delta, sample_EC, X_list, sample_SU_TF, c_prop) {
    .Call(`_DifferentialRegulation_Rcpp_MCMC`, n_samples, n_genes, n_groups, n_genes_keep, keep_genes_id, numeric_groups, sample_ids_per_group, n_samples_per_group, N_MCMC, burn_in, PI_gene_times_SU, PI_SU, list_X_unique, list_EC_gene_id, counts, MCMC_bar_pi_1, MCMC_bar_pi_2, MCMC_bar_pi_3, delta_SU, mean_log_delta, sd_log_delta, sample_EC, X_list, sample_SU_TF, c_prop)
}

Rcpp_MCMC_EC_US <- function(n_samples, n_genes, n_groups, n_genes_keep, keep_genes_id, numeric_groups, sample_ids_per_group, n_samples_per_group, N_MCMC, burn_in, PI_gene, PI_SU, list_X_unique, list_EC_gene_id, counts, MCMC_bar_pi_1, MCMC_bar_pi_2, delta_SU, prior_log_disp, prior_log_S, sample_EC, sample_SU_TF, eff_len_S, eff_len_U, c_prop) {
    .Call(`_DifferentialRegulation_Rcpp_MCMC_EC_US`, n_samples, n_genes, n_groups, n_genes_keep, keep_genes_id, numeric_groups, sample_ids_per_group, n_samples_per_group, N_MCMC, burn_in, PI_gene, PI_SU, list_X_unique, list_EC_gene_id, counts, MCMC_bar_pi_1, MCMC_bar_pi_2, delta_SU, prior_log_disp, prior_log_S, sample_EC, sample_SU_TF, eff_len_S, eff_len_U, c_prop)
}

