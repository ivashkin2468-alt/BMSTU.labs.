задание 1
#include<iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double eps[] = { 1e-2, 1e-4, 1e-6 };

    for (int i = 0; i < 3; i++) {
        double sum = 1.0;
        double term = 1.0;
        int k = 0;
        int iterations = 0;

        while (true) {
            k++;
            term *= -1.0 / ((2 * k - 1) * (2 * k));

            if (abs(term) < eps[i])
                break;

            sum += term;
            iterations++;
        }

        cout << "Tochnost: " << eps[i] << endl;
        cout << "Summa: " << setprecision(10) << sum << endl;
        cout << "cos(1): " << cos(1.0) << endl;
        cout << "Pogreshnost: " << abs(sum - cos(1.0)) << endl;
        cout << "Iteracii: " << iterations << endl;
        cout << endl;
    }

    return 0;
}
