#pragma once

#include "Vector.hpp"

// Geometry object Section
class Section{

public:

	// section's ends
	Vector p1,p2;

	Section();

	Section(Vector _p1,Vector _p2);

};
