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

    // add body to World and return it's id
    int createBody(Body body);

    // set or create body with id
    void setBody(Body body,int id);

    // delete Body by id and return if body is deleted
    bool deleteBody(int id);

    // move Body according to physics and return vector of result movement
    Vector moveBody(int id,Vector v);

    // provide access to bodies map
    const map<int,Body>& getBodies() const;

    // save world to file
    int save(FILE *fp);

    // load world from file
    int load(FILE *fp);

};
