#ifndef _RECTANGLE_HPP_
#define _RECTANGLE_HPP_

#include "../headers/Rectangle.h"

template<class T>
inline Rectangle<T>::Rectangle(): height(0), widght(0) {}

template<class T>
inline Rectangle<T>::Rectangle(const T& h, const T& w): height(h), widght(w) {}

template<class T>
inline Rectangle<T>::~Rectangle(){}

template<class T>
inline Rectangle<T>::Rectangle(const Rectangle<T>& other)
{
    copy(other);
}

template<class T>
inline Rectangle<T>& Rectangle<T>::operator=(const Rectangle<T>& other)
{
    if (this != &other)
    {
        copy(other);
    }
    
    return *this;
}

template<class T>
inline Shape<T>* Rectangle<T>::clone()
{
    return new Rectangle(*this);
}

template<class T>
inline T Rectangle<T>::area() const
{
    return height * widght;
}

template<class T>
inline void Rectangle<T>::copy(const Rectangle<T>& other)
{
    height = other.height;
    widght = other.widght;
}

template<class T>
inline void Rectangle<T>::set(const T& h, const T& w)
{
    height = h;
    widght = w;
}

#endif //!_RECTANGLE_HPP_