#include "Double.hpp"
#include <cmath>

Double::Double():x(0){}

Double::Double(int _x):x(_x){}

Double::Double(float _x):x(_x){}

Double::Double(double _x):x(_x){}

Double::operator double(){
	return x;
}

Double& Double::operator+=(const Double& d){
	x=x+d.x;
	return *this;
}

Double& Double::operator-=(const Double& d){
	x=x-d.x;
	return *this;
}

Double& Double::operator*=(const Double& d){
	x=x*d.x;
	return *this;
}

Double& Double::operator/=(const Double& d){
	x=x/d.x;
	return *this;
}

Double Double::operator+(const Double& d) const {
	return Double(x+d.x);
}

Double Double::operator-(const Double& d) const {
	return Double(x-d.x);
}

Double Double::operator*(const Double& d) const {
	return Double(x*d.x);
}

Double Double::operator/(const Double& d) const {
	return Double(x/d.x);
}

bool Double::operator==(const Double& d) const {
	return std::abs(x-d.x)<MYEPSILON;
}

bool Double::operator>(const Double& d) const {
	return x>=d.x+MYEPSILON;
}

bool Double::operator<(const Double& d) const {
	return x<=d.x-MYEPSILON;
}

bool Double::operator!=(const Double& d) const {
	return !(*this==d);
}

bool Double::operator>=(const Double& d) const {
	return !(*this<d);
}

bool Double::operator<=(const Double& d) const {
	return !(*this>d);
}

// save Double to file
size_t Double::save(FILE *fp) const {
	return fwrite(&x,sizeof(x),1,fp);
}

// load Double from file
size_t Double::load(FILE *fp){
	return fread(&x,sizeof(x),1,fp);
}
