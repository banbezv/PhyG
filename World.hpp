#pragma once

#include <map>
#include <stdio.h>
#include "Body.hpp"
#include "Vector.hpp"
#include "utils.hpp"

// World class manipulates with Body objects and implements physics
class World{

private:

	// id reserved for new body creation
	int new_id;
	std::map<int,Body> bodies;
	
public:

	World();

	void clear();

	// add body to World and return it's id
	int createBody(const Body& body);

	// set or create body with id
	void setBody(const Body& body,int id);

	// delete Body by id and return if body is deleted
	bool deleteBody(int id);

	// move Body according to physics and return vector of result movement
	Vector moveBody(int id,Vector v);

	// provide access to bodies map
	const std::map<int,Body>& getBodies() const;

	// save world to file
	size_t save(FILE *fp) const;

	// load world from file
	size_t load(FILE *fp);

};
