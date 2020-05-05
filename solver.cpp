#include <iostream>
#include <math.h>
#include "solver.hpp"
#include <stdexcept>
#include <complex>
#include <string>

using namespace std;
namespace solver{
/////////////////////////////RealVariable//////////////////////////////////////////

const RealVariable operator-(const RealVariable& x, const RealVariable& y){
    return RealVariable(x._a-y._a,x._b-y._b,x._c-y._c);
}

const RealVariable operator*(const RealVariable& x, const RealVariable& y){
    
    return RealVariable(x._a*y._c+x._b*y._b+x._c*y._a,x._b*y._c+x._c*y._b,x._c*y._c);

}

const RealVariable operator^(const RealVariable& x, int y)
{

    if(y==1){ return x;}
    if(y==0) return 1;
    else return x*x;

}

const RealVariable operator/(const RealVariable& x, double y){
    if(y==0)   throw string{"num/0-error!!!"};
    return RealVariable(x._a/y, x._b/y,x._c/y);

}


const RealVariable operator+(const RealVariable& x, const RealVariable& y){
    
    return RealVariable(x._a+y._a,x._b+y._b,x._c+y._c);
}

const RealVariable operator==(const RealVariable& x, const RealVariable& y)
{
    return RealVariable(x-y);
}

double solve(const RealVariable& x)
{
      if (x._a==0){
          if(x._b==0)    throw string{"b==0 error!!!"};

        return double(-x._c/x._b);
    }
    else{
        if(double(pow(x._b,2)-double(double(4*x._a)*x._c))<0) throw string{"error-(4*a)*c))<0"};
        return double((-x._b +sqrt(double(pow(x._b,2)-double(double(4*x._a)*x._c))))) /double(2*x._a);
    }
}
/////////////////////////////////ComplexVarable////////////////////////////////////

const ComplexVariable operator*(const ComplexVariable& x, const ComplexVariable& y)
{
    return ComplexVariable(x._a*y._c+x._b*y._b+x._c*y._a,x._b*y._c+x._c*y._b,x._c*y._c);
}

const ComplexVariable operator-(const ComplexVariable& x, const ComplexVariable& y)
{
    return ComplexVariable(x._a-y._a,x._b-y._b,x._c-y._c);
}

const ComplexVariable operator/(const ComplexVariable& x, double y)
{
    if(y==0)         throw string{"num/0- error!!!"};
    return ComplexVariable(x._a/y, x._b/y,x._c/y);
}

const ComplexVariable operator^(const ComplexVariable& x, int y)
{
    if(y==1) return x;
    if(y==0) return 1;

    return x*x;
}

const ComplexVariable operator+(const ComplexVariable& x, const ComplexVariable& y)
{
    return ComplexVariable(x._a+y._a,x._b+y._b,x._c+y._c);
}

const ComplexVariable operator==(const ComplexVariable &x, const ComplexVariable &y)
{
    return ComplexVariable(x-y);
}


complex<double> solve(const ComplexVariable& x)
{

      if (real(x._a)== 0 && imag(x._a)==0){
      if(imag(x._b)==0&&real(x._b)==0)         throw string{"error"};
        return (-x._c/x._b);
      }
    else{
        return complex<double>(-x._b +sqrt(complex<double>(pow(x._b,2)-complex<double>((complex<double>(x._a))*4.0*x._c)))) /complex<double>(2.0*x._a);
    }
}

}