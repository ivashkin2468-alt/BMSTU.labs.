#include <iostream>
#include <fstream>
#include <utility>
#include "Vector.h"
using namespace std;

int main() {
    ifstream fin("input.txt");
    if (!fin) {
        cout << "File input.txt not found\n";
        return 1;
    }

    Vector v;
    fin >> v;
    if (!fin) {
        cout << "Input error\n";
        return 1;
    }
    fin.close();

    Vector copy(v);
    Vector moved(move(copy));

    Vector assigned;
    assigned = v;

    Vector movedAssigned;
    movedAssigned = move(assigned);

    ++v;

    ofstream fout("output.txt");
    if (!fout) {
        cout << "File output.txt error\n";
        return 1;
    }

    fout << v;
    fout.close();

    cout << "Vector after ++:\n" << v;
    cout << "Moved vector:\n" << moved;
    cout << "Move assignment:\n" << movedAssigned;

    return 0;
}
