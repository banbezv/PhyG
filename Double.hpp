#pragma once

#include <stdio.h>

#define MYEPSILON 1e-5

// wrapper for float ariphmetic with soft comparison
class Double{

public:

    double x;

    Double();

    Double(int _x);

    Double(float _x);

    Double(double _x);

    operator double();

    Double& operator+=(const Double& d);

    Double& operator-=(const Double& d);

    Double& operator*=(const Double& d);

    Double& operator/=(const Double& d);

    Double operator+(const Double& d) const;

    Double operator-(const Double& d) const;

    Double operator*(const Double& d) const;

    Double operator/(const Double& d) const;

    bool operator==(const Double& d) const;

    bool operator>(const Double& d) const;

    bool operator<(const Double& d) const;

    bool operator!=(const Double& d) const;

    bool operator>=(const Double& d) const;

    bool operator<=(const Double& d) const;

    // save Double to file
    int save(FILE *fp);

    // load Double from file
    int load(FILE *fp);

};
