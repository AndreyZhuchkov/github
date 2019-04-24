#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
void keyboardInput(int&, int&, double&, double&); // Ввод чисел с клавиатуры
void randInput(int&, int&, double&, double&); // Генерация случяйных чисел
void sum(int, int); // Сумма и разность чисел
void sum(double, double);
void prod(int, int); // Произведение чисел
void prod(double, double);
void quot(int, int); // Частное чисел
void quot(double, double);
int main() {
cout << "Хотите ввести числа с клавиатуры?" << endl;
cout << "1) Да" << endl << "0) Нет" << endl;
int c;
cin >> c;
int ai, bi;
double ad, bd;
if(c) {
keyboardInput(ai, bi, ad, bd);
} else {
randInput(ai, bi, ad, bd);
}
cout << "Целые:" << endl;
cout << "a = " << ai << "\tb = " << bi << endl;
sum(ai, bi);
prod(ai, bi);
quot(ai, bi);
cout << "Вещественные:" << endl;
cout << "a = " << ad << "\tb = " << bd << endl;
sum(ad, bd);
prod(ad, bd);
quot(ad, bd);
system("pause");
return 0;
}
void keyboardInput(int &ai, int &bi, double &ad, double &bd) {
cout << "Введите целые числа а,b :" << endl;
cout << "a = ";
cin >> ai;
cout << "b = ";
cin >> bi;
cout << "Введите вещественные числа a,b:" << endl;
cout << "a = ";
cin >> ad;
cout << "b = ";
cin >> bd;
}
void randInput(int &ai, int &bi, double &ad, double &bd) {
srand(time(NULL));
ai = rand() % 100;
bi = rand() % 100;
ad = (rand() % 10000) / 100.0;
bd = (rand() % 10000) / 100.0;
}
void sum(int a, int b) {
cout << "Сумма (a+b): " << (a + b) << endl;
cout << "Разность (a-b) : " << (a - b) << endl;
}
void sum(double a, double b) {
cout << "Суммма (a+b): " << (a + b) << endl;
cout << "Разность (a-b): " << (a - b) << endl;
}
void prod(int a, int b) { cout << "Произведение: " << a * b << endl; }
void prod(double a, double b) { cout << "Произведение: " << a * b << endl; }
void quot(int a, int b) { cout << "Деление: " << (float)a/b << endl; }
void quot(double a, double b) { cout << "Деление: " << a/b << endl; }
