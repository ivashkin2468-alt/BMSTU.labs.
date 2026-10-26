#include "Vector.h"
#include <utility>
#include <stdexcept>

Vector::Vector() : p(nullptr), n(0) {}

Vector::Vector(const int* a, int n) : p(nullptr), n(n) {
    if (n < 0) throw invalid_argument("Invalid size");
    if (n > 0) {
        p = new int[n];
        for (int i = 0; i < n; i++) p[i] = a[i];
    }
}

Vector::Vector(const Vector& v) : p(nullptr), n(v.n) {
    if (n > 0) {
        p = new int[n];
        for (int i = 0; i < n; i++) p[i] = v.p[i];
    }
}

Vector::Vector(Vector&& v) noexcept : p(v.p), n(v.n) {
    v.p = nullptr;
    v.n = 0;
}

Vector::~Vector() {
    delete[] p;
}

Vector& Vector::operator=(const Vector& v) {
    if (this != &v) {
        int* a = v.n > 0 ? new int[v.n] : nullptr;
        for (int i = 0; i < v.n; i++) a[i] = v.p[i];
        delete[] p;
        p = a;
        n = v.n;
    }
    return *this;
}

Vector& Vector::operator=(Vector&& v) noexcept {
    if (this != &v) {
        delete[] p;
        p = v.p;
        n = v.n;
        v.p = nullptr;
        v.n = 0;
    }
    return *this;
}

int& Vector::operator[](int i) {
    if (i < 0 || i >= n) throw out_of_range("Index");
    return p[i];
}

Vector& Vector::operator++() {
    for (int i = 0; i < n; i++) ++p[i];
    return *this;
}

ostream& operator<<(ostream& out, const Vector& v) {
    out << v.n << '\n';
    for (int i = 0; i < v.n; i++) out << v.p[i] << ' ';
    out << '\n';
    return out;
}

istream& operator>>(istream& in, Vector& v) {
    int n;
    if (!(in >> n)) return in;
    if (n < 0) {
        in.setstate(ios::failbit);
        return in;
    }

    Vector temp;
    temp.n = n;
    if (n > 0) {
        temp.p = new int[n];
        for (int i = 0; i < n; i++) {
            if (!(in >> temp.p[i])) return in;
        }
    }

    v = move(temp);
    return in;
}
