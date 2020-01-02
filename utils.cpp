#include "utils.hpp"

// save int to file
size_t saveInt(int x,FILE *fp){
    return fwrite(&x,sizeof(x),1,fp);
}

// load int from file
size_t loadInt(int &x,FILE *fp){
    return fread(&x,sizeof(x),1,fp);
}
