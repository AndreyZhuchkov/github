#include <iostream>
#include <list>
#include <iterator>
using namespace std;
class Complex {
public:
	double re, im;
	void put_number() {
		cout << "Введите комплексное число" << endl;
		cout << "Действительная часть: ";
		cin >> re;
		cout << "Мнимая часть: ";
		cin >> im;
		cout << endl;
	}
	void get_info() {
		cout << re << "+i" << im << "\n";
	}
};
int main() {
	setlocale(LC_ALL, "Russian");

	list<Complex> a;
	for (int i = 0; i < 2; i++) {
		Complex b;
		b.put_number();
		a.push_back(b);
	}
	cout << endl;
	Complex last;
	last = a.back();
	a.pop_back();
	cout << "Список: \n";
	for (Complex f : a) {
		f.get_info();
	}
	cout << last.re << "+i" << last.im  << endl;
	return 0;
}
