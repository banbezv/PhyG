#include "Section.hpp"

Section::Section()=default;

Section::Section(Vector _p1,Vector _p2){
    p1=_p1;
    p2=_p2;
}

// check if point belongs to section
bool Section::have(Vector point) const {
	Double width1=point.x-p1.x,
		width2=point.x-p2.x,
		height1=point.y-p1.y,
		height2=point.y-p2.y;
	if(width1*height2-width2*height1!=Double(0)
		&& double(width1*width2)<=0 && double(height1*height2)<=0){
		return true;
	}
	return false;
}
