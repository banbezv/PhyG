#pragma once

#include <stdio.h>
#include "Vector.hpp"

// save int to file
size_t saveInt(int x,FILE *fp);

// load int from file
size_t loadInt(int &x,FILE *fp);

Vector reduceMovementVector(Vector direction,Vector v1,Vector v2);
