#pragma once
#include <complex>
using namespace std;

namespace solver{
struct RealVariable{
    double _a, _b, _c;
public:
RealVariable():_a(0),_b(1),_c(0){}
    
RealVariable(double x, double y, double z):_a(x),_b(y),_c(z){}

RealVariable(double x):_a(0),_b(0),_c(x){}

RealVariable(const RealVariable& other)
{
        _a=other._a;
        _b=other._b;
        _c=other._c;
}
const RealVariable& operator= (const RealVariable &other)
{
   
    if (this == &other)
        return *this;
 
   
    _a = other._a; 
    _b = other._b; 
    _c = other._c;

    return *this;
}
friend const RealVariable operator*(const RealVariable& x, const RealVariable& y);
friend const RealVariable operator/(const RealVariable& x, double y);
friend const RealVariable operator-(const RealVariable& x, const RealVariable& y);
friend const RealVariable operator^(const RealVariable& x, int y);
friend const RealVariable operator==(const RealVariable& x, const RealVariable& y);
friend const RealVariable operator+(const RealVariable& x, const RealVariable& y);
};

struct ComplexVariable
{
complex<double> _a;
complex<double> _b;
complex<double> _c;

public:

ComplexVariable():_a(0),_b(1),_c(0){}
ComplexVariable(const ComplexVariable& other){
 _a=other._a;
 _b=other._b;
 _c=other._c;
    }
ComplexVariable(const complex<double> a, const complex<double> b, const complex<double> c):_a(a),_b(b),_c(c){}

ComplexVariable(const complex<double> c):_a(0),_b(0),_c(c){}

ComplexVariable(double x):_a(0),_b(0),_c(x){}
  
ComplexVariable& operator=(const ComplexVariable& other)
{
 if (this == &other)
    return *this;
 
_a=other._a; 
_b=other._b; 
_c=other._c;

    return *this;
}
friend const ComplexVariable operator*(const ComplexVariable& x, const ComplexVariable& y);
friend const ComplexVariable operator^(const ComplexVariable& x, int y);
friend const ComplexVariable operator/(const ComplexVariable& x, double y);
friend const ComplexVariable operator-(const ComplexVariable& x, const ComplexVariable& y);
friend const ComplexVariable operator==(const ComplexVariable& x, const ComplexVariable& y);
friend const ComplexVariable operator+(const ComplexVariable& x, const ComplexVariable& y);
};
double solve(const RealVariable& x);
complex<double> solve(const ComplexVariable& y);
}