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
задание 2
#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

struct Discipline {
    string name;
    int grade;
};

struct Student {
    string fullName;
    vector<Discipline> disciplines;
};

// Ввод данных одного студента
void inputStudent(Student& s) {
    cout << "\nВведите ФИО студента: ";
    getline(cin, s.fullName);

    int m;
    do {
        cout << "Введите количество дисциплин (не менее 4): ";
        cin >> m;

        if (m < 4) {
            cout << "Количество дисциплин должно быть не менее 4.\n";
        }
    } while (m < 4);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    s.disciplines.resize(m);

    for (int i = 0; i < m; i++) {
        cout << "\nДисциплина " << i + 1 << ":\n";

        cout << "Название: ";
        getline(cin, s.disciplines[i].name);

        do {
            cout << "Оценка (2-5): ";
            cin >> s.disciplines[i].grade;

            if (s.disciplines[i].grade < 2 ||
                s.disciplines[i].grade > 5) {
                cout << "Введите оценку от 2 до 5.\n";
            }
        } while (s.disciplines[i].grade < 2 ||
                 s.disciplines[i].grade > 5);

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Вывод данных одного студента
void outputStudent(const Student& s) {
    cout << "\nФИО: " << s.fullName << '\n';
    cout << "Результаты сессии:\n";

    for (const Discipline& d : s.disciplines) {
        cout << "  " << d.name << " — " << d.grade << '\n';
    }
}

// Проверка: все оценки студента — 4 или 5
bool passedWithFourAndFive(const Student& s) {
    for (const Discipline& d : s.disciplines) {
        if (d.grade < 4) {
            return false;
        }
    }

    return true;
}

int main() {
    setlocale(LC_ALL, "RU");

    int n;
    cout << "Введите количество студентов в группе: ";
    cin >> n;

    while (n <= 0) {
        cout << "Количество студентов должно быть положительным: ";
        cin >> n;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<Student> group(n);

    // Ввод данных
    for (int i = 0; i < n; i++) {
        cout << "\n Студент " << i + 1 << " \n";
        inputStudent(group[i]);
    }

    // Контрольный вывод введённых данных
    cout << "\n ВВЕДЁННЫЕ ДАННЫЕ \n";

    for (int i = 0; i < n; i++) {
        cout << "\nСтудент " << i + 1 << ':';
        outputStudent(group[i]);
    }

    // Подсчёт студентов, сдавших сессию на 4 и 5
    int count = 0;

    for (const Student& s : group) {
        if (passedWithFourAndFive(s)) {
            count++;
        }
    }

    cout << "\nКоличество студентов, сдавших сессию "
         << "только на 4 и 5: " << count << '\n';

    return 0;
}
