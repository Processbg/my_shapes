#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "../headers/Shape.h"

template<class T>
class Triangle: public Shape<T>
{
public:
    Triangle();
    ~Triangle();
    Triangle(const T&, const T&, const T&);
    Triangle(const Triangle<T>& other);
    Triangle<T>& operator=(const Triangle<T>& other);

    void set(const T& A, const T& B, const T& C);
    
    Shape<T>* clone() override;
    T area() const override;

private:

    void copy(const Triangle<T>& other);

    T a;
    T b;
    T c;
};

#include "Triangle.hpp"

#endif //!_TRIANGLE_H_