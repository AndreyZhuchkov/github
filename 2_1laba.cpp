#include <iostream>
using namespace std;
double carLux(double value); // Вычисляет налог люксового авто стоимостью > 1 000 000
double carEconom(double value); // Вычисляет налог на машину стоимостью < 1 000 000
double (*getcar)(double value); // Выбирает, как вычислять налог
int main() {
double cost;
cout << "Введите стоимость авто: ";
cin >> cost;
if (cost > 1000000) {
getcar = carLux;
} else {
getcar = carEconom;
}
cout << "Налог на авто: " << getcar(cost) << endl;
return 0;
}
double carLux(double value) {
return value * 0.04;
}
double carEconom(double value) {
return value * 0.03;
}
