#include "Geometry.hpp"

// check if sections intersects
bool isIntersected(Section section1,Section section2){
	Double width1=section1.p2.x-section1.p1.x,
		width2=section2.p2.x-section2.p1.x,
		height1=section1.p2.y-section1.p1.y,
		height2=section2.p2.y-section2.p1.y;
	if(double(width1*height2-width2*height1)==0.){
		return false;
	}
	Vector crossPoint=intersect(section1,section2);
	//cout<<string(section1)<<" ^ "<<string(section2)<<" = "<<string(crossPoint)<<endl;
	return section1.have(crossPoint) && section2.have(crossPoint);
}

// return (0,0) if v==(0,0) else return direction vector of lenght 1
Vector getDirection(Vector v){
	if(v==Vector()){
		return Vector();
	}
	Double length=sqrt(pow(v.x,2)+pow(v.y,2));
	return v/length;
}

// return true if clockwise counted angle between vectors
// (section.p2-section.p1) and (point-section.p1) is greater than 180
bool isPointLeftOfSection(Vector point,Section section){
	Vector v1=section.p2-section.p1,
		v2=point-section.p1;
	return v1.x*v2.y-v1.y*v2.x>Double(0);
}

// return crosspoint of two sections
// it is expected that they intersects indeed
Vector intersect(Section section1,Section section2){
	Double width1=section1.p2.x-section1.p1.x,
			width2=section2.p2.x-section2.p1.x,
			height1=section1.p2.y-section1.p1.y,
			height2=section2.p2.y-section2.p1.y;
	if(double(width1*height2-width2*height1)==0.){
		return Vector(-INFINITY,-INFINITY);
	}
	Vector crosspoint;
	Vector AB=section1.p2-section1.p1,
		DC=section2.p1-section2.p2,
		AC=section2.p1-section1.p1;
	Double alpha=(AC.x*DC.y-AC.y*DC.x)/(AB.x*DC.y-AB.y*DC.x);
	crosspoint=section1.p1+AB*alpha;
	return crosspoint;
}
