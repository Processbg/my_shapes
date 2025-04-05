#ifndef _SQUARE_H_
#define _SQUARE_H_

#include "../headers/Rectangle.h"

template<class T>
class Square: public Rectangle<T> 
{
public:
    Square();
    Square(const T&);
    Square(const Square<T>&);
    Square<T>& operator=(const Square<T>&);
    ~Square();

    void set(const T& s);
    
    Shape<T>* clone() override;
    T area() const override;

private:
    void copy(const Square<T>&);

    T side;
};

#include "Square.hpp"

#endif //!_SQUARE_H_