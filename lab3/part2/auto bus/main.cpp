#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Automobile {
protected:
    string model;
    double maxSpeed;

public:
    Automobile(string m, double s)
        : model(m), maxSpeed(s) {}

    virtual void print() const {
        cout << "Model: " << model << endl;
        cout << "Max speed: " << maxSpeed << " km/h" << endl;
    }

    virtual ~Automobile() = default;
};

class Bus : public Automobile {
    int passengers;

public:
    Bus(string m, double s, int p)
        : Automobile(m, s), passengers(p) {}

    void print() const override {
        Automobile::print();
        cout << "Max passengers: " << passengers << endl;
    }
};

int main() {
    Automobile car("Toyota", 200);
    Bus bus("Mercedes-Benz", 120, 50);

    cout << "Static calls:\n";
    car.print();
    cout << endl;
    bus.print();

    cout << "\nDynamic polymorphism:\n";
    vector<Automobile*> vehicles = {&car, &bus};

    for (Automobile* v : vehicles) {
        v->print();
        cout << endl;
    }

    return 0;
}
