#ifndef INTEGRATOR_HPP_
#define INTEGRATOR_HPP_

typedef struct
{
  vector<double>* value;
} *Parameters;


template <class T>
class Integrator {

public:
    virtual double integrate(T &func, const double a, const double b, const double tol, void* param) = 0;
};


#endif // INTEGRATOR_HPP_

