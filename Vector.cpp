#include "Vector.hpp"

Vector::Vector()=default;

Vector::Vector(const Double& _x,const Double& _y){
	x=_x;
	y=_y;
}

Vector::operator sf::Vector2f() const {
	return sf::Vector2f(x,y);
}

Vector::operator std::string() const {
	return "("+std::string(x)+","+std::string(y)+")";
}

Double Vector::operator*(const Vector& v) const {
	return x*v.x+y*v.y;
}

Vector Vector::operator+(const Vector& v) const {
	return Vector(x+v.x,y+v.y);
}

Vector Vector::operator-(const Vector& v) const {
	return Vector(x-v.x,y-v.y);
}

Vector Vector::operator*(const Double& d) const {
	return Vector(x*d,y*d);
}

Vector Vector::operator/(const Double& d) const {
	return Vector(x/d,y/d);
}

Vector& Vector::operator+=(const Vector& v){
	x+=v.x;
	y+=v.y;
	return *this;
}
	
Vector& Vector::operator-=(const Vector& v){
	x-=v.x;
	y-=v.y;
	return *this;
}

Vector& Vector::operator*=(const Double& d){
	x*=d;
	y*=d;
	return *this;
}

Vector& Vector::operator/=(const Double& d){
	x/=d;
	y/=d;
	return *this;
}

bool Vector::operator==(const Vector& v) const {
	return x==v.x&&y==v.y;
}

bool Vector::operator!=(const Vector& v) const {
	return !(*this==v);
}

// save Vector to file
size_t Vector::save(FILE *fp) const {
	return x.save(fp)+y.save(fp);
}

// load Vector from file
size_t Vector::load(FILE *fp){
	return x.load(fp)+y.load(fp);
}
