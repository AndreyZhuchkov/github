#include <iostream>
#include <cmath>
using namespace std;
class Complex {
	double re;
	double im;
public:
	Complex(double re, double im) : re(re), im(im) {}
	Complex(const Complex& c);
	Complex operator= (const Complex& c);
	void setNumber(double re, double im);
	double getModule();
	void displayData();
	~Complex() {
    cout<<"Очищение памяти деструктор"<<endl;
  }
};
int main() {
	double re, im;
	cout << "Введите действительную часть первого числа: ";
	cin >> re;
	cout << "Введите мнимую часть первого числа: ";
	cin >> im;
	Complex c1(re, im);
	Complex c2(c1);
	Complex c3 = c1;
	c1.displayData();
c2.displayData();
	c3.displayData();
	system("pause");
	return 0;
}
Complex::Complex(const Complex& c) {
	re = c.re;
	im = c.re;
}
Complex Complex::operator= (const Complex& c) { return Complex(c.re, c.im); }
void Complex::setNumber(double re, double im) {
	this->re = re;
	this->im = im;
}
double Complex::getModule() { return sqrt(re * re + im * im); }
void Complex::displayData() {
	cout << "Число: " << re;
	if (im < 0) {
		cout << im << "i" << endl;
	} else {
		cout << "+" << im << "i" << endl;
	}
	cout << "Модуль: " << getModule() << endl;
}
