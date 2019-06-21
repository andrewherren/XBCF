#ifndef GUARD_fit_info_h
#define GUARD_fit_info_h

#include <ctime>
#include "common.h"
#include "utility.h"
#include <chrono>

struct State
{
public:
    // Result containers
    xinfo predictions_std;
    xinfo predictions_std_copy;
    std::vector<double> yhat_std;
    std::vector<double> residual_std;
    std::vector<double> residual_std_full;

    // Random
    std::vector<double> prob;
    std::random_device rd;
    std::mt19937 gen;
    std::discrete_distribution<> d;

    // Splits
    xinfo split_count_all_tree;
    std::vector<double> split_count_current_tree;
    std::vector<double> mtry_weight_current_tree;

    // mtry
    bool use_all = true;

    // fitinfo
    size_t n_min;
    size_t n_cutpoints;
    bool parallel;
    size_t p_categorical;
    size_t p_continuous;
    size_t p; // total number of variables = p_categorical + p_continuous
    size_t mtry;
    size_t n_y;                       // number of total data points in root node
    const double *X_std;              // pointer to original data
    const std::vector<double> *y_std; // pointer to y data
    const xinfo_sizet *max_depth_std;
    bool draw_mu;
    size_t num_trees;
    size_t num_sweeps;
    bool sample_weights_flag;

    // residual standard deviation
    double sigma;
    double sigma2; // sigma squared


    void update_sigma(double sigma)
    {
        this->sigma = sigma;
        this->sigma2 = pow(sigma, 2);
        return;
    }

    State(const double *Xpointer, xinfo_sizet &Xorder_std, size_t N, size_t p, size_t num_trees, size_t p_categorical, size_t p_continuous, bool set_random_seed, size_t random_seed, size_t n_min, size_t n_cutpoints, bool parallel, size_t mtry, const double *X_std, bool draw_mu, size_t num_sweeps, bool sample_weights_flag, std::vector<double> *y_std, double sigma, xinfo_sizet *max_depth_std, double ini_var_yhat)
    {

        // Init containers
        // initialize predictions_std at given value / number of trees
        ini_xinfo(this->predictions_std, N, num_trees, ini_var_yhat / (double)num_trees);

        // initialize yhat at given value
        yhat_std = std::vector<double>(N, ini_var_yhat);

        this->residual_std = std::vector<double>(N);

        // Random
        this->prob = std::vector<double>(2, 0.5);
        this->gen = std::mt19937(rd());
        if (set_random_seed)
        {
            gen.seed(random_seed);
        }
        this->d = std::discrete_distribution<>(prob.begin(), prob.end());

        // Splits
        ini_xinfo(this->split_count_all_tree, p, num_trees);
        this->split_count_current_tree = std::vector<double>(p, 0);
        this->mtry_weight_current_tree = std::vector<double>(p, 0);


        this->n_min = n_min;
        this->n_cutpoints = n_cutpoints;
        this->parallel = parallel;
        this->p_categorical = p_categorical;
        this->p_continuous = p_continuous;
        this->mtry = mtry;
        this->X_std = X_std;
        this->p = p_categorical + p_continuous;
        this->n_y = N;
        this->draw_mu = draw_mu;
        this->num_trees = num_trees;
        this->num_sweeps = num_sweeps;
        this->sample_weights_flag = sample_weights_flag;
        this->y_std = y_std;
        this->sigma = sigma;
        this->sigma2 = pow(sigma, 2);
        this->max_depth_std = max_depth_std;

        return;
    }

    void update_split_counts(size_t tree_ind)
    {
        mtry_weight_current_tree = mtry_weight_current_tree + split_count_current_tree;
        split_count_all_tree[tree_ind] = split_count_current_tree;
        return;
    }
};

#endif