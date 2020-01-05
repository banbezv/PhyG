#pragma once

#include <string>
#include "Vector.hpp"

// Geometry object Section
class Section{

public:

	// section's ends
	Vector p1,p2;

	Section();

	Section(Vector _p1,Vector _p2);

	operator std::string() const;

	// check if point belongs to section
	bool have(Vector point) const;

};
