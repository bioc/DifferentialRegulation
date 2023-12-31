// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// Rcpp_MCMC
Rcpp::NumericVector Rcpp_MCMC(unsigned int const& n_samples, unsigned int const& n_genes, unsigned int const& n_groups, unsigned int const& n_genes_keep, Rcpp::IntegerVector const& keep_genes_id, Rcpp::IntegerVector const& numeric_groups, Rcpp::ListOf<Rcpp::IntegerVector> const& sample_ids_per_group, Rcpp::IntegerVector const& n_samples_per_group, unsigned int const& N_MCMC, unsigned int const& burn_in, Rcpp::NumericMatrix& PI_gene_times_SU, Rcpp::ListOf<Rcpp::NumericMatrix>& PI_SU, Rcpp::NumericMatrix const& list_X_unique, Rcpp::ListOf<Rcpp::ListOf<Rcpp::IntegerVector>> const& list_EC_gene_id, Rcpp::ListOf<Rcpp::IntegerVector> const& counts, Rcpp::ListOf<Rcpp::NumericMatrix>& MCMC_bar_pi_1, Rcpp::ListOf<Rcpp::NumericMatrix>& MCMC_bar_pi_2, Rcpp::ListOf<Rcpp::NumericMatrix>& MCMC_bar_pi_3, Rcpp::ListOf<Rcpp::NumericMatrix>& delta_SU, Rcpp::NumericVector const& mean_log_delta, Rcpp::NumericVector const& sd_log_delta, Rcpp::IntegerVector const& sample_EC, Rcpp::ListOf<Rcpp::NumericMatrix>& X_list, Rcpp::IntegerVector const& sample_SU_TF, double const& c_prop);
RcppExport SEXP _DifferentialRegulation_Rcpp_MCMC(SEXP n_samplesSEXP, SEXP n_genesSEXP, SEXP n_groupsSEXP, SEXP n_genes_keepSEXP, SEXP keep_genes_idSEXP, SEXP numeric_groupsSEXP, SEXP sample_ids_per_groupSEXP, SEXP n_samples_per_groupSEXP, SEXP N_MCMCSEXP, SEXP burn_inSEXP, SEXP PI_gene_times_SUSEXP, SEXP PI_SUSEXP, SEXP list_X_uniqueSEXP, SEXP list_EC_gene_idSEXP, SEXP countsSEXP, SEXP MCMC_bar_pi_1SEXP, SEXP MCMC_bar_pi_2SEXP, SEXP MCMC_bar_pi_3SEXP, SEXP delta_SUSEXP, SEXP mean_log_deltaSEXP, SEXP sd_log_deltaSEXP, SEXP sample_ECSEXP, SEXP X_listSEXP, SEXP sample_SU_TFSEXP, SEXP c_propSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< unsigned int const& >::type n_samples(n_samplesSEXP);
    Rcpp::traits::input_parameter< unsigned int const& >::type n_genes(n_genesSEXP);
    Rcpp::traits::input_parameter< unsigned int const& >::type n_groups(n_groupsSEXP);
    Rcpp::traits::input_parameter< unsigned int const& >::type n_genes_keep(n_genes_keepSEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerVector const& >::type keep_genes_id(keep_genes_idSEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerVector const& >::type numeric_groups(numeric_groupsSEXP);
    Rcpp::traits::input_parameter< Rcpp::ListOf<Rcpp::IntegerVector> const& >::type sample_ids_per_group(sample_ids_per_groupSEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerVector const& >::type n_samples_per_group(n_samples_per_groupSEXP);
    Rcpp::traits::input_parameter< unsigned int const& >::type N_MCMC(N_MCMCSEXP);
    Rcpp::traits::input_parameter< unsigned int const& >::type burn_in(burn_inSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericMatrix& >::type PI_gene_times_SU(PI_gene_times_SUSEXP);
    Rcpp::traits::input_parameter< Rcpp::ListOf<Rcpp::NumericMatrix>& >::type PI_SU(PI_SUSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericMatrix const& >::type list_X_unique(list_X_uniqueSEXP);
    Rcpp::traits::input_parameter< Rcpp::ListOf<Rcpp::ListOf<Rcpp::IntegerVector>> const& >::type list_EC_gene_id(list_EC_gene_idSEXP);
    Rcpp::traits::input_parameter< Rcpp::ListOf<Rcpp::IntegerVector> const& >::type counts(countsSEXP);
    Rcpp::traits::input_parameter< Rcpp::ListOf<Rcpp::NumericMatrix>& >::type MCMC_bar_pi_1(MCMC_bar_pi_1SEXP);
    Rcpp::traits::input_parameter< Rcpp::ListOf<Rcpp::NumericMatrix>& >::type MCMC_bar_pi_2(MCMC_bar_pi_2SEXP);
    Rcpp::traits::input_parameter< Rcpp::ListOf<Rcpp::NumericMatrix>& >::type MCMC_bar_pi_3(MCMC_bar_pi_3SEXP);
    Rcpp::traits::input_parameter< Rcpp::ListOf<Rcpp::NumericMatrix>& >::type delta_SU(delta_SUSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector const& >::type mean_log_delta(mean_log_deltaSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector const& >::type sd_log_delta(sd_log_deltaSEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerVector const& >::type sample_EC(sample_ECSEXP);
    Rcpp::traits::input_parameter< Rcpp::ListOf<Rcpp::NumericMatrix>& >::type X_list(X_listSEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerVector const& >::type sample_SU_TF(sample_SU_TFSEXP);
    Rcpp::traits::input_parameter< double const& >::type c_prop(c_propSEXP);
    rcpp_result_gen = Rcpp::wrap(Rcpp_MCMC(n_samples, n_genes, n_groups, n_genes_keep, keep_genes_id, numeric_groups, sample_ids_per_group, n_samples_per_group, N_MCMC, burn_in, PI_gene_times_SU, PI_SU, list_X_unique, list_EC_gene_id, counts, MCMC_bar_pi_1, MCMC_bar_pi_2, MCMC_bar_pi_3, delta_SU, mean_log_delta, sd_log_delta, sample_EC, X_list, sample_SU_TF, c_prop));
    return rcpp_result_gen;
END_RCPP
}
// Rcpp_MCMC_EC_US
Rcpp::NumericVector Rcpp_MCMC_EC_US(unsigned int const& n_samples, unsigned int const& n_genes, unsigned int const& n_groups, unsigned int const& n_genes_keep, Rcpp::IntegerVector const& keep_genes_id, Rcpp::IntegerVector const& numeric_groups, Rcpp::ListOf<Rcpp::IntegerVector> const& sample_ids_per_group, Rcpp::IntegerVector const& n_samples_per_group, unsigned int const& N_MCMC, unsigned int const& burn_in, Rcpp::NumericMatrix& PI_gene, Rcpp::ListOf<Rcpp::NumericMatrix>& PI_SU, Rcpp::NumericMatrix const& list_X_unique, Rcpp::ListOf<Rcpp::ListOf<Rcpp::IntegerVector>> const& list_EC_gene_id, Rcpp::ListOf<Rcpp::IntegerVector> const& counts, Rcpp::ListOf<Rcpp::NumericMatrix>& MCMC_bar_pi_1, Rcpp::ListOf<Rcpp::NumericMatrix>& MCMC_bar_pi_2, Rcpp::ListOf<Rcpp::NumericMatrix>& delta_SU, Rcpp::NumericVector const& prior_log_disp, Rcpp::NumericVector const& prior_log_S, Rcpp::IntegerVector const& sample_EC, Rcpp::IntegerVector const& sample_SU_TF, Rcpp::NumericVector const& eff_len_S, Rcpp::NumericVector const& eff_len_U, double const& c_prop);
RcppExport SEXP _DifferentialRegulation_Rcpp_MCMC_EC_US(SEXP n_samplesSEXP, SEXP n_genesSEXP, SEXP n_groupsSEXP, SEXP n_genes_keepSEXP, SEXP keep_genes_idSEXP, SEXP numeric_groupsSEXP, SEXP sample_ids_per_groupSEXP, SEXP n_samples_per_groupSEXP, SEXP N_MCMCSEXP, SEXP burn_inSEXP, SEXP PI_geneSEXP, SEXP PI_SUSEXP, SEXP list_X_uniqueSEXP, SEXP list_EC_gene_idSEXP, SEXP countsSEXP, SEXP MCMC_bar_pi_1SEXP, SEXP MCMC_bar_pi_2SEXP, SEXP delta_SUSEXP, SEXP prior_log_dispSEXP, SEXP prior_log_SSEXP, SEXP sample_ECSEXP, SEXP sample_SU_TFSEXP, SEXP eff_len_SSEXP, SEXP eff_len_USEXP, SEXP c_propSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< unsigned int const& >::type n_samples(n_samplesSEXP);
    Rcpp::traits::input_parameter< unsigned int const& >::type n_genes(n_genesSEXP);
    Rcpp::traits::input_parameter< unsigned int const& >::type n_groups(n_groupsSEXP);
    Rcpp::traits::input_parameter< unsigned int const& >::type n_genes_keep(n_genes_keepSEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerVector const& >::type keep_genes_id(keep_genes_idSEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerVector const& >::type numeric_groups(numeric_groupsSEXP);
    Rcpp::traits::input_parameter< Rcpp::ListOf<Rcpp::IntegerVector> const& >::type sample_ids_per_group(sample_ids_per_groupSEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerVector const& >::type n_samples_per_group(n_samples_per_groupSEXP);
    Rcpp::traits::input_parameter< unsigned int const& >::type N_MCMC(N_MCMCSEXP);
    Rcpp::traits::input_parameter< unsigned int const& >::type burn_in(burn_inSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericMatrix& >::type PI_gene(PI_geneSEXP);
    Rcpp::traits::input_parameter< Rcpp::ListOf<Rcpp::NumericMatrix>& >::type PI_SU(PI_SUSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericMatrix const& >::type list_X_unique(list_X_uniqueSEXP);
    Rcpp::traits::input_parameter< Rcpp::ListOf<Rcpp::ListOf<Rcpp::IntegerVector>> const& >::type list_EC_gene_id(list_EC_gene_idSEXP);
    Rcpp::traits::input_parameter< Rcpp::ListOf<Rcpp::IntegerVector> const& >::type counts(countsSEXP);
    Rcpp::traits::input_parameter< Rcpp::ListOf<Rcpp::NumericMatrix>& >::type MCMC_bar_pi_1(MCMC_bar_pi_1SEXP);
    Rcpp::traits::input_parameter< Rcpp::ListOf<Rcpp::NumericMatrix>& >::type MCMC_bar_pi_2(MCMC_bar_pi_2SEXP);
    Rcpp::traits::input_parameter< Rcpp::ListOf<Rcpp::NumericMatrix>& >::type delta_SU(delta_SUSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector const& >::type prior_log_disp(prior_log_dispSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector const& >::type prior_log_S(prior_log_SSEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerVector const& >::type sample_EC(sample_ECSEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerVector const& >::type sample_SU_TF(sample_SU_TFSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector const& >::type eff_len_S(eff_len_SSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector const& >::type eff_len_U(eff_len_USEXP);
    Rcpp::traits::input_parameter< double const& >::type c_prop(c_propSEXP);
    rcpp_result_gen = Rcpp::wrap(Rcpp_MCMC_EC_US(n_samples, n_genes, n_groups, n_genes_keep, keep_genes_id, numeric_groups, sample_ids_per_group, n_samples_per_group, N_MCMC, burn_in, PI_gene, PI_SU, list_X_unique, list_EC_gene_id, counts, MCMC_bar_pi_1, MCMC_bar_pi_2, delta_SU, prior_log_disp, prior_log_S, sample_EC, sample_SU_TF, eff_len_S, eff_len_U, c_prop));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_DifferentialRegulation_Rcpp_MCMC", (DL_FUNC) &_DifferentialRegulation_Rcpp_MCMC, 25},
    {"_DifferentialRegulation_Rcpp_MCMC_EC_US", (DL_FUNC) &_DifferentialRegulation_Rcpp_MCMC_EC_US, 25},
    {NULL, NULL, 0}
};

RcppExport void R_init_DifferentialRegulation(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
