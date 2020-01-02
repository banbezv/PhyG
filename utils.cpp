#include "utils.hpp"

// save int to file
size_t saveInt(int x,FILE *fp){
	return fwrite(&x,sizeof(x),1,fp);
}

// load int from file
size_t loadInt(int &x,FILE *fp){
	return fread(&x,sizeof(x),1,fp);
}

Vector reduceMovementVector(Vector direction,Vector v1,Vector v2){
	Vector res=(v1*direction<v2*direction)?v1:v2;
	if(res*direction<=Double(0)){
		res=Vector();
	}
	return res;
}
