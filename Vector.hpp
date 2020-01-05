#pragma once

#include <string>
#include <stdio.h>
#include <SFML/System.hpp>
#include "Double.hpp"

// Vector for works with float ariphmetics
class Vector{

public:

	Double x,y;

	Vector();

	Vector(const Double& _x,const Double& _y);

	operator sf::Vector2f() const;

	operator std::string() const;

	Double operator*(const Vector& v) const;

	Vector operator+(const Vector& v) const;

	Vector operator-(const Vector& v) const;

	Vector operator*(const Double& d) const;

	Vector operator/(const Double& d) const;

	Vector& operator+=(const Vector& v);
	
	Vector& operator-=(const Vector& v);

	Vector& operator*=(const Double& d);

	Vector& operator/=(const Double& d);

	bool operator==(const Vector& v) const;

	bool operator!=(const Vector& v) const;

	// save Vector to file
	size_t save(FILE *fp) const;

	// load Vector from file
	size_t load(FILE *fp);

};
