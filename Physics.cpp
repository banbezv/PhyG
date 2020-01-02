#include "Physics.hpp"

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
