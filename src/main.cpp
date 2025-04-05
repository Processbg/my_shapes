#include <iostream>
#include <unordered_map>
#include <cstring>
#include <cstdio>

#include "../headers/Shape.h"
#include "../headers/Rectangle.h"
#include "../headers/Square.h"
#include "../headers/Triangle.h"
#include "../headers/Circle.h"

Shape<double>* makeCircle(double dim1, double dim2, double dim3)
{
    return new Circle<double>(dim1);
}

Shape<double>* makeTriangle(double dim1, double dim2, double dim3)
{
    return new Triangle<double>(dim1, dim2, dim3);
}

Shape<double>* makeSquare(double dim1, double dim2, double dim3)
{
    return new Square<double>(dim1);
}

Shape<double>* makeRectangle(double dim1, double dim2, double dim3)
{
    return new Rectangle<double>(dim1, dim2);
} 

typedef Shape<double>* (*ShapeCreator) (double, double, double);

const int MAX_SIZE = 10;

// Custom hash function for const char*
struct CStrHash
{
    std::size_t operator()(const char* str) const
    {
        std::size_t hash = 0;
        while (*str)
        {
            hash = hash * 31 + static_cast<unsigned char>(*str);  
            // This technique is based on a polynomial rolling hash function, 
            // which is often used to efficiently compute hashes for strings.
            // The multiplier 31 is a constant that is used to 
            // combine the individual character values in the string to produce a final hash value.
            ++str;
        }
        return hash;
    }
};

// Custom equality function for const char*
struct CStrEqual
{
    bool operator()(const char* lhs, const char* rhs) const
    {
        return std::strcmp(lhs, rhs) == 0;  // Compare strings using strcmp
    }
};

int main(int argc, char* argv[])
{
    std::unordered_map<const char *, ShapeCreator, CStrHash, CStrEqual> shapeMakers;

    shapeMakers.try_emplace("rectangle", makeRectangle);
    shapeMakers.try_emplace("triangle", makeTriangle);
    shapeMakers.try_emplace("square", makeSquare);
    shapeMakers.try_emplace("circle", makeCircle);

    std::cout << "Please input a shape: rectangle, triangle, square or circle. If you need help please type --help.\n";
    char* userInputShape = new(std::nothrow) char[MAX_SIZE];
    if (!userInputShape)
    {
        std::cerr << "Could not allocate memmory!\n";
        return -1;
    }

    int i = 0;
    char ch;
    while ( (ch = getchar()) != '\n' && i < MAX_SIZE - 1 )
    {
        userInputShape[i] = ch;
        ++i;
    }
    userInputShape[i] = '\0';

    if (!strcmp(userInputShape, "--help"))
    {
        std::cout << argv[0] << " please choose one of these shapes: triangle, rectangle, circle or square.\n";
        std::cout << "Followed by the dimentions of the desired shape.\n"; 
        std::cout << "Example for rectangle 10 100 0.\n";
        std::cout << "Example for sqaure 14 0 0.\n";
        std::cout << "Example for triangle 12 15 23.\n";
        std::cout << "Example for circle 11 0 0.\n";
        delete[] userInputShape;
        return 0;
    }

    std::cout << "Please input desired dimentions of previously typed shape.\n";
    double dim1, dim2, dim3;
    std::cin >> dim1 >> dim2 >> dim3;

    std::unordered_map<const char*, ShapeCreator, CStrHash, CStrEqual>::iterator it = shapeMakers.find(userInputShape);
    if (it != shapeMakers.end())
    {
        Shape<double>* madeShape = it->second(dim1, dim2, dim3);
        if (!madeShape)
        {
            std::cerr << "Could not allocate memory for desired shape.\n";
            delete[] userInputShape;
            return -1;
        }

        std::cout << "The area of the shape is " << madeShape->area() << std::endl;

        delete madeShape;
        madeShape = nullptr;
    }
    else
    {
        std::cerr << "Desired shape " << userInputShape << " is not supported yet. Sorry!\n";
        delete[] userInputShape;
        return -1;
    }

    delete[] userInputShape;
    return 0;
}