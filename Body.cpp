#include "Body.hpp"

Body::Body()=default;

Body::Body(const Vector& _position,const Vector& _size,const Double& _rotation){
	position=_position;
	size=_size;
	rotation=_rotation;
}

// save body to file
size_t Body::save(FILE *fp) const {
	return position.save(fp)+size.save(fp)+rotation.save(fp);
}

// load body from file
size_t Body::load(FILE *fp){
	return position.load(fp)+size.load(fp)+rotation.load(fp);
}
