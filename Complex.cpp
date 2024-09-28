// Student ID: 20558765
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include "Complex.h"
using namespace std;

bool Complex::operator==(const Complex& that) const{
    return (_real == that._real) && (_imag == that._imag);
}

Complex& Complex::operator=(const Complex& rhs){
    if(this != &rhs){
        _real = rhs._real;
        _imag = rhs._imag;
    }
    return *this;
}

bool Complex::operator<(const Complex& that) const {
    return norm_squared() < that.norm_squared();
}

Complex Complex::operator+(const Complex& that) const{
    double newreal = _real + that._real;
    double newimag = _imag + that._imag;
    return Complex(newreal,newimag);
}

Complex Complex::operator-(const Complex& that) const{
    double newreal = _real - that._real;
    double newimag = _imag - that._imag;
    return Complex(newreal,newimag);
}

Complex Complex::operator*(const Complex& that) const {
    double newreal = _real * that._real - _imag * that._imag;
    double newimag = _real * that._imag + _imag * that._real;
    return Complex(newreal, newimag);
}

Complex Complex::reciprocal() const {
    double denominator = _real * _real + _imag * _imag;
    if (abs(denominator) <= FLOOR) {
        throw Div_By_Zero_Exception();
    }
    double newreal = _real / denominator;
    double newimag = -_imag / denominator;
    return Complex(newreal, newimag);
}

Complex Complex::operator/(const Complex& that) const {
    Complex that_reciprocal = that.reciprocal();
    return (*this) * that_reciprocal;
}

string Complex::to_string() const {
    char buf[140]; 
    sprintf(buf, "(%.11g,%.11g)", _real, _imag);
    return string(buf);
}

ostream& operator<<(ostream& os, const Complex& x){
    os << x.to_string() ;
    return os;
}





