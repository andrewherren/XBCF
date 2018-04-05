/*
 *  BART: Bayesian Additive Regression Trees
 *  Copyright (C) 2017 Robert McCulloch and Rodney Sparapani
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, a copy is available at
 *  https://www.R-project.org/Licenses/GPL-2
 */

#ifndef GUARD_tree_h
#define GUARD_tree_h

#include <map>
#include <cmath>
#include <cstddef>
#include "common.h"

// [[Rcpp::plugins(cpp11)]]


//--------------------------------------------------
//find best split variable and value, CART
void split_error(const arma::umat& Xorder, arma::vec& y, arma::uvec& best_split, arma::vec& least_error);
void split_error_2(const arma::umat& Xorder, arma::vec& y, arma::uvec& best_split, arma::vec& least_error, double tau, double sigma, double depth, double alpha, double beta);
void split_error_3(const arma::umat& Xorder, arma::vec& y, arma::umat& best_split, arma::mat& loglike, double tau, double sigma, double depth, double alpha, double beta);
//--------------------------------------------------
//split Xorder matrix for two subnodes 
void split_xorder(arma::umat& Xorder_left, arma::umat& Xorder_right, arma::umat& Xorder, arma::mat& X, int split_var, int split_point);
//--------------------------------------------------
//BART likelihood function
arma::vec BART_likelihood(arma::vec& n1, arma::vec& n2, arma::vec& s1, arma::vec& s2, double& tau, double& sigma, double& alpha, double& penalty);
//--------------------------------------------------
//generate a vector of integers
arma::uvec range(int start, int end);

//--------------------------------------------------
//xinfo xi, then xi[v][c] is the c^{th} cutpoint for variable v.
//left if x[v] < xi[v][c]
typedef std::vector<double> vec_d; //double vector
typedef std::vector<vec_d> xinfo; //vector of vectors, will be split rules

//--------------------------------------------------
//info contained in a node, used by input operator
struct node_info {
   std::size_t id; //node id
   std::size_t v;  //variable
   double c;  //cut point // different from BART
   double theta;   //theta
};

//--------------------------------------------------
class tree {
public:
   //friends--------------------
   friend std::istream& operator>>(std::istream&, tree&);
   //typedefs--------------------
   typedef tree* tree_p;
   typedef const tree* tree_cp;
   typedef std::vector<tree_p> npv; 
   typedef std::vector<tree_cp> cnpv;
   //contructors,destructors--------------------
   tree(): theta(0.0),v(0),c(0),p(0),l(0),r(0) {}
   tree(const tree& n): theta(0.0),v(0),c(0),p(0),l(0),r(0) {cp(this,&n);}
   tree(double itheta): theta(itheta),v(0),c(0),p(0),l(0),r(0) {}
   void tonull(); //like a "clear", null tree has just one node
   ~tree() {tonull();}
   //operators----------
   tree& operator=(const tree&);
   //interface--------------------
   //set
   void settheta(double theta) {this->theta=theta;}
   void setv(size_t v) {this->v = v;}
   void setc(size_t c) {this->c = c;}
   //get
   double gettheta() const {return theta;}
   size_t getv() const {return v;}
   double getc() const {return c;}
   tree_p getp() {return p;}  
   tree_p getl() {return l;}
   tree_p getr() {return r;}
   //tree functions--------------------
   tree_p getptr(size_t nid); //get node pointer from node id, 0 if not there
   void pr(bool pc=true); //to screen, pc is "print children"
   size_t treesize(); //number of nodes in tree
   size_t nnogs();    //number of nog nodes (no grandchildren nodes)
   size_t nbots();    //number of bottom nodes
   bool birth(size_t nid, size_t v, size_t c, double thetal, double thetar);
   bool death(size_t nid, double theta);
   void birthp(tree_p np,size_t v, size_t c, double thetal, double thetar);
   void deathp(tree_p nb, double theta);
   void getbots(npv& bv);         //get bottom nodes
   void getnogs(npv& nv);         //get nog nodes (no granchildren)
   void getnodes(npv& v);         //get vector of all nodes
   void getnodes(cnpv& v) const;  //get vector of all nodes (const)
   void grow_tree(arma::vec& y, double y_mean, arma::umat& Xorder, arma::mat& X, int depth, int max_depth, int Nmin, double tau, double sigma, double alpha, double beta);
   void grow_tree_2(arma::vec& y, double y_mean, arma::umat& Xorder, arma::mat& X, int depth, int max_depth, int Nmin, double tau, double sigma, double alpha, double beta);
   tree_p bn(double *x,xinfo& xi); //find Bottom Node
   tree_p search_bottom(arma::mat& Xnew);
   void rg(size_t v, int* L, int* U); //recursively find region [L,U] for var v
   //node functions--------------------
   size_t nid() const; //nid of a node
   size_t depth();  //depth of a node
   char ntype(); //node type t:top, b:bot, n:no grandchildren i:interior (t can be b)
   bool isnog();
#ifndef NoRcpp   
  Rcpp::List tree2list(xinfo& xi, double center=0., double scale=1.); // create an efficient list from a single tree
  //tree list2tree(Rcpp::List&, xinfo& xi); // create a tree from a list and an xinfo  
  Rcpp::IntegerVector tree2count(size_t nvar); // for one tree, count the number of branches for each variable
#endif
private:
   double theta; //univariate double parameter
   //rule: left if x[v] < xinfo[v][c]
   size_t v;  //index of variable to split
        double c;   

   //////////////////////////
   // size_t c;  // split point
   //////////////////////////
  // different from BART package, they use index, we save raw split value

   //tree structure
   tree_p p; //parent
   tree_p l; //left child
   tree_p r; //right child
   //utiity functions
   void cp(tree_p n,  tree_cp o); //copy tree
};
std::istream& operator>>(std::istream&, tree&);
std::ostream& operator<<(std::ostream&, const tree&);

#endif