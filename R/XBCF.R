XBCF <- function(y, X, X_tau, z,
                num_sweeps, burnin = 1L,
                max_depth, Nmin,
                num_cutpoints,
                no_split_penality = "Auto", mtry_pr = 0L, mtry_trt = 0L,
                p_categorical_pr = 0L,
                p_categorical_trt = 0L,
                num_trees_pr,
                alpha_pr = 0.95, beta_pr = 1.25, tau_pr,
                kap_pr = 16, s_pr = 4,
                pr_scale = FALSE,
                num_trees_trt,
                alpha_trt = 0.25, beta_trt = 3, tau_trt,
                kap_trt = 16, s_trt = 4,
                trt_scale = FALSE,
                verbose = FALSE, parallel = TRUE,
                random_seed = NULL, sample_weights_flag = TRUE,
                a_scaling = TRUE, b_scaling = TRUE) {

    #index = order(z, decreasing=TRUE)

    #y = y[index]
    #X = matrix(c(x[,1][index],x[,2][index],x[,3][index]),nrow=length(x[,1]))
    #z = z[index]

    if(class(X) != "matrix"){
        cat("Input X is not a matrix, try to convert type.\n")
        X = as.matrix(X)
    }
    if(class(X_tau) != "matrix"){
        cat("Input X_tau is not a matrix, try to convert type.\n")
        X_tau = as.matrix(X_tau)
    }
    if(class(z) != "matrix"){
        cat("Input z is not a matrix, try to convert type.\n")
        z = as.matrix(z)
    }
    if(class(y) != "matrix"){
        cat("Input y is not a matrix, try to convert type.\n")
        y = as.matrix(y)
    }

    if(is.null(random_seed)){
        set_random_seed = FALSE
        random_seed = 0;
    }else{
        cat("Set random seed as ", random_seed, "\n")
        set_random_seed = TRUE
    }

    if(burnin >= num_sweeps){
        cat("Burnin samples should be smaller than number of sweeps.\n")
        return();
    }
    if(no_split_penality == "Auto"){
        no_split_penality = log(num_cutpoints)
    }

    obj = XBCF_cpp(y, X, X_tau, z,
                         num_sweeps, burnin,
                         max_depth, Nmin,
                         num_cutpoints,
                         no_split_penality, mtry_pr, mtry_trt,
                         p_categorical_pr,
                         p_categorical_trt,
                         num_trees_pr,
                         alpha_pr, beta_pr, tau_pr,
                         kap_pr, s_pr,
                         pr_scale,
                         num_trees_trt,
                         alpha_trt, beta_trt, tau_trt,
                         kap_trt, s_trt,
                         trt_scale,
                         verbose, parallel, set_random_seed,
                         random_seed, sample_weights_flag,
                         a_scaling, b_scaling)
    class(obj) = "XBCF"
    return(obj)
}
