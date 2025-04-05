#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "../headers/Shape.h"

template<class T>
class Circle: public Shape<T>
{
public:
    Circle();
    ~Circle();
    Circle(const T&);
    Circle(const Circle<T>&);
    Circle<T>& operator=(const Circle<T>&);

    void set(const T& r);
    
    Shape<T>* clone() override;
    T area() const override;

private:
    void copy(const Circle<T>& other);

    T radius;
};

#include "Circle.hpp"

#endif //!_CIRCLE_H_