#pragma once

#include <stdio.h>

// save int to file
size_t saveInt(int x,FILE *fp);

// load int from file
size_t loadInt(int &x,FILE *fp);
