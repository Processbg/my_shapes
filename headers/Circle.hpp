#ifndef _CIRCLE_HPP_
#define _CIRCLE_HPP_

#include "../headers/Circle.h"

#include <cmath>

template<class T>
inline Circle<T>::Circle(): radius(0) {}

template<class T>
inline Circle<T>::~Circle(){}

template<class T>
inline Circle<T>::Circle(const T& r): radius(r) {}

template<class T>
inline Circle<T>::Circle(const Circle<T>& other)
{
    copy(other);
}

template<class T>
inline Circle<T>& Circle<T>::operator=(const Circle<T>& other)
{
    if (this != &other)
    {
        copy(other);
    }
    
    return *this;
}

template<class T>
inline void Circle<T>::copy(const Circle<T>& other)
{
    radius = other.radius;
}

template<class T>
inline Shape<T>* Circle<T>::clone()
{
    return new Circle(*this);
}

template<class T>
inline T Circle<T>::area() const
{
    return M_PI * (radius*radius);
}

template<class T>
inline void Circle<T>::set(const T& r) { radius = r; }

#endif //!_CIRCLE_HPP_ 