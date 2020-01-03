#pragma once

#include "Section.hpp"
#include "Vector.hpp"
#include "Double.hpp"

// check if sections intersects
bool isIntersected(Section section1,Section section2);

// return crosspoint of two sections
Vector intersect(Section section1,Section section2);

// return true if clockwise counted angle between vectors
// (section.p2-section.p1) and (point-section.p1) is greater than 180
bool isPointLeftOfSection(Vector point,Section section);

// return (0,0) if v==(0,0) else return direction vector of lenght 1
Vector getDirection(Vector v);
