#ifndef _SHAPE_H_
#define _SHAPE_H_

template<class T>
class Shape
{
public: 
    virtual ~Shape(){};
    virtual Shape* clone() = 0;
    virtual T area() const = 0;
};

#endif //!_SHAPE_H_
