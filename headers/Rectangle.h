#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "../headers/Shape.h"

template<class T>
class Rectangle: public Shape<T>
{
public:
    Rectangle();
    Rectangle(const T&, const T&);
    virtual ~Rectangle();
    Rectangle(const Rectangle<T>&);
    Rectangle<T>& operator=(const Rectangle<T>&);

    void set(const T& h, const T& w);
    
    Shape<T>* clone() override;
    T area() const override;

private:
    void copy(const Rectangle<T>&);

    T height;
    T widght;
};

#include "Rectangle.hpp"

#endif //!_RECTANGLE_H_