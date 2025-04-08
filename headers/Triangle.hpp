#ifndef _TRIANGLE_HPP_
#define _TRIANGLE_HPP_

#include "../headers/Triangle.h"

#include <iostream>
#include <cmath>

template<class T>
inline Triangle<T>::Triangle(): a(0), b(0), c(0) {}

template<class T>
inline Triangle<T>::Triangle(const T& A, const T& B, const T& C): a(A), b(B), c(C) {}

template<class T>
inline Triangle<T>::~Triangle(){}

template<class T>
inline Triangle<T>::Triangle(const Triangle<T>& other)
{
    copy(other);
}

template<class T>
inline Triangle<T>& Triangle<T>::operator=(const Triangle<T>& other)
{
    if (this != &other)
    {
        copy(other);
    }

    return *this;
}

template<class T>
inline void Triangle<T>::copy(const Triangle<T>& other)
{
    a = other.a;
    b = other.b;
    c = other.c;
}

template<class T>
inline Shape<T>* Triangle<T>::clone()
{
    return new Triangle(*this);
}

template<class T>
inline T Triangle<T>::area() const
{
    if ( a + b <= c || a + c <= b || b + c <= a)
    {
        std::cerr << "Invalid triangle: The sum of any two sides must be greater than the third side.\n";
        return -1;
    }

    T p = (a + b + c) / 2;
    T pa = p - a;
    T pb = p - b;
    T pc = p - c;
    T product = p * pa * pb * pc;
    return static_cast<T>( sqrt( static_cast<double>(product) ) );
}

template<class T>
inline void Triangle<T>::set(const T& A, const T& B, const T& C)
{ 
    a = A;
    b = B;
    c = C;
}

#endif //!_TRIANGLE_HPP_