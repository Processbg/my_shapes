#ifndef _SQUARE_HPP_
#define _SQUARE_HPP_

#include "../headers/Square.h"

template<class T>
inline Square<T>::Square(): side(0), Rectangle<T>(side, side) {}

template<class T>
inline Square<T>::Square(const T& s): side(s), Rectangle<T>(side, side) {}

template<class T>
inline Square<T>::~Square(){}

template<class T>
inline Square<T>::Square(const Square<T>& other): Rectangle<T>(other)
{
    copy(other);
}

template<class T>
inline Square<T>& Square<T>::operator=(const Square<T>& other)
{
    copy(other);
    
    return *this;
}

template<class T>
inline void Square<T>::copy(const Square<T>& other)
{
    if (this != &other)
    {
        side = other.side;
    }
}

template<class T>
inline Shape<T>* Square<T>::clone()
{
    return new Square(*this);
}

template<class T>
inline T Square<T>::area() const 
{
    return side * side;
}

template<class T>
inline void Square<T>::set(const T& s) { side = s; }

#endif //!_SQUARE_HPP_