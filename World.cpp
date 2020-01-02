#include "World.hpp"

World::World(){
	new_id=0;
}

void World::clear(){
	new_id=0;
	bodies.clear();
}

// add body to World and return it's id
int World::createBody(const Body& body){
	int id=new_id++;
	bodies[id]=body;
	return id;
}

// set or create body with id
void World::setBody(const Body& body,int id){
	bodies[id]=body;
	if(id>=new_id){
		new_id=id+1;
	}
}

// delete Body by id and return if body is deleted
bool World::deleteBody(int id){
	return bodies.erase(id);
}

// provide access to bodies map
const std::map<int,Body>& World::getBodies() const {
	return bodies;
}

// save world to file
size_t World::save(FILE *fp) const {
	size_t res=0;
	int amount=bodies.size();
	res+=saveInt(amount,fp);
	for(auto element:bodies){
		res+=saveInt(element.first,fp);
		res+=element.second.save(fp);
	}
	return res;
}

// load world from file
size_t World::load(FILE *fp){
	size_t res=0;
	int amount;
	res+=loadInt(amount,fp);
	int id;
	Body body;
	clear();
	for(int i=0;i<amount;i++){
		res+=loadInt(id,fp);
		res+=body.load(fp);
		setBody(body,id);
	}
	return res;
}

// move Body according to physics and return vector of result movement
Vector World::moveBody(int id,Vector v){
	Vector res=v,temp;
	for(auto element:bodies){
		const int &id2=element.first;
		if(id2==id){
			continue;
		}
		temp=moveBody1ToBody2(id,id2,v);
		res=reduceMovementVector(v,res,temp);
	}
	bodies[id].position+=res;
	return res;
}

// reducing moveBody to two bodies' case
Vector World::moveBody1ToBody2(int id1,int id2,Vector v) const {
	std::vector<Vector> points1=bodies.at(id1).getPoints(),
		points2=bodies.at(id2).getPoints();
	std::vector<Section> sections1=bodies.at(id1).getSides(),
		sections2=bodies.at(id2).getSides();
	Vector movement1=movePointsToSections(points1,sections2,v),
		movement2=movePointsToSections(points2,sections1,v*(-1))*(-1);
	return reduceMovementVector(v,movement1,movement2);
}
