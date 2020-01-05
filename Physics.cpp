#include "Physics.hpp"

#include <string>
#include <iostream>
using namespace std;

Vector movePointsToSections(const std::vector<Vector>& points,
const std::vector<Section> sections,Vector v){
	Vector res=v,temp;
	for(auto point:points){
		for(auto section:sections){
			temp=movePointToSection(point,section,v);
			res=reduceMovementVector(v,res,temp);
		}
	}
	return res;
}

// move point to vector until it collides with section
// return movement vector
Vector movePointToSection(Vector point,Section section,Vector v){
	if(v==Vector()){
		return Vector();
	}
	if(isIntersected(Section(point,point+v),section)){
		Vector crosspoint=intersect(Section(point,point+v),section);
		while(!isPointLeftOfSection(crosspoint,section)){
			crosspoint-=getDirection(v)*MYEPSILON;
		}
		return crosspoint-point;
	} else {
		return v;
	}
}
