#include <cmath>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

#include "AdaptiveIntegrator.hpp"

double func(const double, void *);

int main()
{
   AdaptiveIntegrator<double (const double, void*)> test;
   
   double coef = 2.0;
   
   Parameters param;
   param = (Parameters) malloc(sizeof *param);
   param->value = new vector<double>();
 
   param->value->push_back(coef);
     
   cout << test.integrate(func, 0., 1., 1.e-8, param) << endl;
   return 0; 
}
double func(const double x, void *params)
{
 
   Parameters param = (Parameters) params;
   double coef = param->value->at(0); 

   return coef*x*x*x;
}


