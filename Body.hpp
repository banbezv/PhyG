#pragma once

#include <stdio.h>
#include "Vector.hpp"
#include "Double.hpp"

// Body's parameters
class Body{

public:

    // position of the center of rectangle
    Vector position;
    Vector size;
    // deviation from the vertical to clockwise
    Double rotation;

    Body();

    Body(const Vector& _position,const Vector& _size,const Double& _rotation);

    // save body to file
    size_t save(FILE *fp) const;

    // load body from file
    size_t load(FILE *fp);

};
