// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// predict_tree
Rcpp::List predict_tree(Rcpp::List trees, arma::mat Xnew);
RcppExport SEXP _SpikySmoothTrees_predict_tree(SEXP treesSEXP, SEXP XnewSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type trees(treesSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type Xnew(XnewSEXP);
    rcpp_result_gen = Rcpp::wrap(predict_tree(trees, Xnew));
    return rcpp_result_gen;
END_RCPP
}
// singletree_2
Rcpp::List singletree_2(arma::vec y, arma::mat X, size_t depth, size_t max_depth, size_t Nmin, double tau, double sigma, double alpha, double beta);
RcppExport SEXP _SpikySmoothTrees_singletree_2(SEXP ySEXP, SEXP XSEXP, SEXP depthSEXP, SEXP max_depthSEXP, SEXP NminSEXP, SEXP tauSEXP, SEXP sigmaSEXP, SEXP alphaSEXP, SEXP betaSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type y(ySEXP);
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< size_t >::type depth(depthSEXP);
    Rcpp::traits::input_parameter< size_t >::type max_depth(max_depthSEXP);
    Rcpp::traits::input_parameter< size_t >::type Nmin(NminSEXP);
    Rcpp::traits::input_parameter< double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< double >::type sigma(sigmaSEXP);
    Rcpp::traits::input_parameter< double >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< double >::type beta(betaSEXP);
    rcpp_result_gen = Rcpp::wrap(singletree_2(y, X, depth, max_depth, Nmin, tau, sigma, alpha, beta));
    return rcpp_result_gen;
END_RCPP
}
// singletree_3
Rcpp::List singletree_3(arma::vec y, arma::mat X, size_t depth, size_t max_depth, size_t Nmin, double tau, double sigma, double alpha, double beta);
RcppExport SEXP _SpikySmoothTrees_singletree_3(SEXP ySEXP, SEXP XSEXP, SEXP depthSEXP, SEXP max_depthSEXP, SEXP NminSEXP, SEXP tauSEXP, SEXP sigmaSEXP, SEXP alphaSEXP, SEXP betaSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type y(ySEXP);
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< size_t >::type depth(depthSEXP);
    Rcpp::traits::input_parameter< size_t >::type max_depth(max_depthSEXP);
    Rcpp::traits::input_parameter< size_t >::type Nmin(NminSEXP);
    Rcpp::traits::input_parameter< double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< double >::type sigma(sigmaSEXP);
    Rcpp::traits::input_parameter< double >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< double >::type beta(betaSEXP);
    rcpp_result_gen = Rcpp::wrap(singletree_3(y, X, depth, max_depth, Nmin, tau, sigma, alpha, beta));
    return rcpp_result_gen;
END_RCPP
}
// singletree
Rcpp::List singletree(arma::vec y, arma::mat X, size_t depth, size_t max_depth, size_t Nmin, double tau, double sigma, double alpha, double beta);
RcppExport SEXP _SpikySmoothTrees_singletree(SEXP ySEXP, SEXP XSEXP, SEXP depthSEXP, SEXP max_depthSEXP, SEXP NminSEXP, SEXP tauSEXP, SEXP sigmaSEXP, SEXP alphaSEXP, SEXP betaSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type y(ySEXP);
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< size_t >::type depth(depthSEXP);
    Rcpp::traits::input_parameter< size_t >::type max_depth(max_depthSEXP);
    Rcpp::traits::input_parameter< size_t >::type Nmin(NminSEXP);
    Rcpp::traits::input_parameter< double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< double >::type sigma(sigmaSEXP);
    Rcpp::traits::input_parameter< double >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< double >::type beta(betaSEXP);
    rcpp_result_gen = Rcpp::wrap(singletree(y, X, depth, max_depth, Nmin, tau, sigma, alpha, beta));
    return rcpp_result_gen;
END_RCPP
}
// train_forest_2
Rcpp::List train_forest_2(arma::mat y, arma::mat X, arma::mat Xtest, size_t M, size_t L, size_t N_sweeps, arma::mat max_depth, size_t Nmin, double alpha, double beta, double tau, bool draw_sigma, double kap, double s, bool verbose, bool m_update_sigma, bool draw_mu);
RcppExport SEXP _SpikySmoothTrees_train_forest_2(SEXP ySEXP, SEXP XSEXP, SEXP XtestSEXP, SEXP MSEXP, SEXP LSEXP, SEXP N_sweepsSEXP, SEXP max_depthSEXP, SEXP NminSEXP, SEXP alphaSEXP, SEXP betaSEXP, SEXP tauSEXP, SEXP draw_sigmaSEXP, SEXP kapSEXP, SEXP sSEXP, SEXP verboseSEXP, SEXP m_update_sigmaSEXP, SEXP draw_muSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type y(ySEXP);
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type Xtest(XtestSEXP);
    Rcpp::traits::input_parameter< size_t >::type M(MSEXP);
    Rcpp::traits::input_parameter< size_t >::type L(LSEXP);
    Rcpp::traits::input_parameter< size_t >::type N_sweeps(N_sweepsSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type max_depth(max_depthSEXP);
    Rcpp::traits::input_parameter< size_t >::type Nmin(NminSEXP);
    Rcpp::traits::input_parameter< double >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< double >::type beta(betaSEXP);
    Rcpp::traits::input_parameter< double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< bool >::type draw_sigma(draw_sigmaSEXP);
    Rcpp::traits::input_parameter< double >::type kap(kapSEXP);
    Rcpp::traits::input_parameter< double >::type s(sSEXP);
    Rcpp::traits::input_parameter< bool >::type verbose(verboseSEXP);
    Rcpp::traits::input_parameter< bool >::type m_update_sigma(m_update_sigmaSEXP);
    Rcpp::traits::input_parameter< bool >::type draw_mu(draw_muSEXP);
    rcpp_result_gen = Rcpp::wrap(train_forest_2(y, X, Xtest, M, L, N_sweeps, max_depth, Nmin, alpha, beta, tau, draw_sigma, kap, s, verbose, m_update_sigma, draw_mu));
    return rcpp_result_gen;
END_RCPP
}
// train_forest
Rcpp::List train_forest(arma::mat y, arma::mat X, arma::mat Xtest, size_t M, size_t L, size_t N_sweeps, arma::vec max_depth, size_t Nmin, double alpha, double beta, double tau, bool draw_sigma);
RcppExport SEXP _SpikySmoothTrees_train_forest(SEXP ySEXP, SEXP XSEXP, SEXP XtestSEXP, SEXP MSEXP, SEXP LSEXP, SEXP N_sweepsSEXP, SEXP max_depthSEXP, SEXP NminSEXP, SEXP alphaSEXP, SEXP betaSEXP, SEXP tauSEXP, SEXP draw_sigmaSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type y(ySEXP);
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type Xtest(XtestSEXP);
    Rcpp::traits::input_parameter< size_t >::type M(MSEXP);
    Rcpp::traits::input_parameter< size_t >::type L(LSEXP);
    Rcpp::traits::input_parameter< size_t >::type N_sweeps(N_sweepsSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type max_depth(max_depthSEXP);
    Rcpp::traits::input_parameter< size_t >::type Nmin(NminSEXP);
    Rcpp::traits::input_parameter< double >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< double >::type beta(betaSEXP);
    Rcpp::traits::input_parameter< double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< bool >::type draw_sigma(draw_sigmaSEXP);
    rcpp_result_gen = Rcpp::wrap(train_forest(y, X, Xtest, M, L, N_sweeps, max_depth, Nmin, alpha, beta, tau, draw_sigma));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_SpikySmoothTrees_predict_tree", (DL_FUNC) &_SpikySmoothTrees_predict_tree, 2},
    {"_SpikySmoothTrees_singletree_2", (DL_FUNC) &_SpikySmoothTrees_singletree_2, 9},
    {"_SpikySmoothTrees_singletree_3", (DL_FUNC) &_SpikySmoothTrees_singletree_3, 9},
    {"_SpikySmoothTrees_singletree", (DL_FUNC) &_SpikySmoothTrees_singletree, 9},
    {"_SpikySmoothTrees_train_forest_2", (DL_FUNC) &_SpikySmoothTrees_train_forest_2, 17},
    {"_SpikySmoothTrees_train_forest", (DL_FUNC) &_SpikySmoothTrees_train_forest, 12},
    {NULL, NULL, 0}
};

RcppExport void R_init_SpikySmoothTrees(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
