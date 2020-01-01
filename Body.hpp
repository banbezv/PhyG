#pragma once

#include "Vector.hpp"
#include "Double.hpp"

// Body's parameters
class Body{

private:

    // position of the center of rectangle
    Vector position;
    Vector size;
    // deviation from the vertical to clockwise
    Double rotation;

public:

    Body();

    void setPosition(Vector _position);

    void setSize(Vector _size);

    void setRotation(Double _rotation);

    const Vector& getPosition() const;

    const Vector& getSize() const;

    const Double& getRotation() const;

    // save body to file
    int save(FILE *fp);

    // load body from file
    int load(FILE *fp);

};
