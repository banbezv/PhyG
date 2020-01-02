#include "Body.hpp"

Body::Body()=default;

Body::Body(const Vector& _position,const Vector& _size,const Double& _rotation){
	position=_position;
	size=_size;
	rotation=_rotation;
}

// get corners of rectangle body
std::vector<Vector> Body::getPoints() const {
	std::vector<Vector> points;
	double angle=rotation.x*M_PI/180.;
	Vector semiH=Vector(cos(angle),-sin(angle))*size.x/2.,
		semiV=Vector(sin(angle),cos(angle))*size.y/2.;
	points.push_back(position-semiH-semiV);
	points.push_back(position-semiH+semiV);
	points.push_back(position+semiH+semiV);
	points.push_back(position+semiH-semiV);
	return points;
}

// get sides of rectangle body
std::vector<Section> Body::getSides() const {
	std::vector<Section> sections;
	auto points=getPoints();
	sections.push_back(Section(points[0],points[1]));
	sections.push_back(Section(points[1],points[2]));
	sections.push_back(Section(points[2],points[3]));
	sections.push_back(Section(points[3],points[0]));
	return sections;
}

// save body to file
size_t Body::save(FILE *fp) const {
	return position.save(fp)+size.save(fp)+rotation.save(fp);
}

// load body from file
size_t Body::load(FILE *fp){
	return position.load(fp)+size.load(fp)+rotation.load(fp);
}
