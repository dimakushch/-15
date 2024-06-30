#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <Windows.h>
using namespace std;

struct Engine {
    string type;
    string color;
    int own;
};

struct Car {
    string brand;
    string model;
    int year;
    double price;
    bool nego;
    Engine eng;
};

void add(vector<Car>& cars, const Car& car);
void rem(vector<Car>& cars, size_t index);
void print(const vector<Car>& cars);

void add(vector<Car>& cars, const Car& car) {
    cars.push_back(car);
}

void rem(vector<Car>& cars, size_t index) {
    if (index < cars.size()) {
        cars.erase(cars.begin() + index);
    }
    else {
        cout << "Індекс поза діапазоном" << endl;
    }
}

void print(const vector<Car>& cars) {
    cout << left << setw(10) << "Бренд"
        << setw(10) << "Модель"
        << setw(6) << "Рік"
        << setw(10) << "Ціна"
        << setw(10) << "Торг"
        << setw(15) << "Тип двигуна"
        << setw(10) << "Колір"
        << setw(8) << "Кількість власників"
        << endl;

    for (const Car& car : cars) {
        cout << left << setw(10) << car.brand
            << setw(10) << car.model
            << setw(6) << car.year
            << setw(10) << car.price
            << setw(10) << (car.nego ? "Так" : "Ні")
            << setw(15) << car.eng.type
            << setw(10) << car.eng.color
            << setw(8) << car.eng.own
            << endl;
    }
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<Car> cars;

    cars.push_back({ "Toyota", "Camry", 2015, 15000, true, {"V6", "Red", 2} });
    cars.push_back({ "Honda", "Civic", 2018, 18000, false, {"I4", "Blue", 1} });
    cars.push_back({ "Ford", "Mustang", 2020, 30000, true, {"V8", "Black", 1} });
    cars.push_back({ "Tesla", "Model 3", 2021, 35000, false, {"Electric", "White", 1} });

    print(cars);

    Car newCar = { "BMW", "X5", 2019, 45000, true, {"V6", "Grey", 1} };
    add(cars, newCar);

    cout << "Після додавання нового автомобіля:" << endl;
    print(cars);

    rem(cars, 2);

    cout << "Після вилучення третьої машини:" << endl;
    print(cars);

    return 0;
}
