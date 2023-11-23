#include <iostream>
#include <vector>

using namespace std;

class MyVector {
private:
    vector<double> data;

public:
    // Конструктор класу
    MyVector() {}

    // Перевантаження операції приведення до типу int
    operator int() {
        return data.size();
    }

    ~MyVector() {
        cout << "Desructor is called " << endl;
    } //Деструктор

    // Перевантаження операції встановлення нового розміру
    void operator() (int new_size) {
        data.resize(new_size);
    }

    // Перевантаження операції віднімання числа з вектора
    MyVector operator- (double value) {
        MyVector result;
        for (int i = 0; i < data.size(); i++) {
            result.data.push_back(data[i] - value);
        }
        return result;
    }

    // Перевантаження операції доступу до елементів за індексом
    double& operator[] (int index) {
        return data[index];
    }

    // Функція для виведення вектора на екран
    void print() {
        for (int i = 0; i < data.size(); i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MyVector v;

    // Встановлюємо розмір вектора
    v(100);

    // Заповнюємо вектор значеннями
    for (int i = 0; i < v; i++) {
        v[i] = i + 1;
    }

    cout << "Vector size: " << (int)v << endl;
    cout << "Vector before subtraction: ";
    v.print();

    // Віднімаємо число з вектора
    v = v - 2.0;

    cout << "Vector after subtraction: ";
    v.print();

    // Доступ до елементу вектора за індексом
    cout << "Vector 2: " << v[3] << endl;

    return 0;
}
