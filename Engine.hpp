#pragma once

#include <map>
#include "Body.hpp"
#include "Vector.hpp"

using namespace std;


// World class manipulates with Body objects and implements physics
class World{

private:

    // id reserved for new body creation
    int new_id;

    map<int,Body> bodies;
    
public:

    World();

    void clear();

    // adds body to World and returns
    int createBody(Body body);

    // deletes Body by id and returns if body is deleted
    bool deleteBody(int id);

    // moves Body according to physics and returns vector of result movement
    Vector moveBody(int id,Vector v);

    // provides access to bodies map
    const map<int,Body>& getBodies() const;

};
