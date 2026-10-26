#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

class Vector {
    int* p;
    int n;

public:
    Vector();
    Vector(const int* a, int n);
    Vector(const Vector& v);
    Vector(Vector&& v) noexcept;
    ~Vector();

    Vector& operator=(const Vector& v);
    Vector& operator=(Vector&& v) noexcept;
    int& operator[](int i);
    Vector& operator++();

    friend ostream& operator<<(ostream& out, const Vector& v);
    friend istream& operator>>(istream& in, Vector& v);
};

#endif
