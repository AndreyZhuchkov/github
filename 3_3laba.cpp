#include <iostream>
#include <cmath>
using namespace std;
class Complex {
	double re;
	double im;
public:
	Complex(double re, double im) {	setNumber(re, im); }
	void setNumber(double, double);	// Принимает мнимую и действительную части числа
	double getModule() { return sqrt(re * re + im * im); }	// Модуль числа
	void print();	// Выводит на экран числа
};
int main() {
	double re, im;
	cout << "Введите действительную часть первого числа: ";
	cin >> re;
	cout << "Введите мнимую часть первого числа: ";
	cin >> im;
	Complex c1(re, im);
	cout << "Введите действительную часть второго числа: ";
	cin >> re;
	cout << "Введите мнимую часть второго числа: ";
	cin >> im;
	Complex c2(re, im);
	c1.print();
	c2.print();
	system("pause");
	return 0;
}
void Complex::setNumber(double re, double im) {
	this->re = re;
	this->im = im;
}
void Complex::print() {
	cout << "Число: " << re;
	if (im < 0) {
		cout << im << "i" << endl;
	} else {
		cout << "+" << im << "i" << endl;
	}
	cout << "Модуль: " << getModule() << endl;
}
