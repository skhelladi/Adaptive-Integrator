Gauss-Lobatto Adaptive Integrator
===================

A C++ port of the adaptive quadrature algorithm by [Gander and Gautschi](http://link.springer.com/article/10.1023%2FA%3A1022318402393). The same algorithm is implemented in [Numerical Recipes](http://www.nr.com/), but their license is very restrictive. I translated the code from the original paper so it can be used freely, as outlined in the [MIT License](http://opensource.org/licenses/MIT).

Usage
-------------------
A sample example file,`example.cpp`, is provided.
Simply include the header `AdaptiveIntegrator.hpp` in your code:
```cpp
    #include "AdaptiveIntegrator.hpp"
```
Then create an integrator object specialized for the type of functional 
you wish to integrate. In the simplest case this is just a normal function 
with signature `double(const double, void*)`, so the declaration looks like
```cpp
    AdaptiveIntegrator<double(const double, void*)> test;
```
Finally to integrate your function, `func`, invoke the `integrate` method 
with integral bounds `a` and `b`, desired tolerance `tol` and users' parameters `param`:
```cpp
    test.integrate(func, a, b, tol, param);
```

The users' parameters structure is defined in `Integrator.hpp` file as:

```cpp
typedef struct
{
  vector<double>* value;
} *Parameters;
```
In `main.cpp`, user defined parameters are defined as:

```cpp
   double coef = 2.0;
   
   Parameters param;
   param = (Parameters) malloc(sizeof *param);
   param->value = new vector<double>();
 
   param->value->push_back(coef);
```

