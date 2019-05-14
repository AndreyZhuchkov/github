#include <iostream>
#include <string>
using namespace std;
class Tiles {
public:
	string brand;
	double size_w;
	double size_h;
	double price;
	Tiles(string& brand, double size_w, double size_h, double price) : //Конструктор
		brand(brand), size_w(size_w), size_h(size_h), price(price) {}
	Tiles(const Tiles&);
	Tiles operator= (const Tiles&);
	void getData();
	~Tiles() {}// Деструктор
};
int main() {
	string brand;
	double size_w, size_h, price;
	cout << "Введите производителя первой плитки: ";
	cin >> brand;
	cout << "Введите длину первой плитки: ";
	cin >> size_w;
	cout << "Введите ширину первой плитки: ";
	cin >> size_h;
	cout << "Введите цену первой плитки: ";
	cin >> price;
	Tiles t1(brand, size_w, size_h, price);
	Tiles t2(t1);
	Tiles t3 = t1;
	cout << "Первая плитка" << endl;
	t1.getData();
	cout <<endl << "Вторая плитка" << endl;
	t2.getData();
	cout <<endl << "Третья плитка" << endl;
	t3.getData();
	return 0;
}
Tiles::Tiles(const Tiles& t) {
	this->brand = t.brand;
	this->price = t.price;
	this->size_h = t.size_h;
	this->size_w = t.size_w;
}
Tiles Tiles::operator= (const Tiles& t) {
	this->brand = t.brand;
	this->price = t.price;
	this->size_h = t.size_h;
	this->size_w = t.size_w;
	return *this;
}
void Tiles::getData() {
	cout << "Производитель: " << brand << endl;
	cout << "Длина: " << size_w << endl;
	cout << "Ширина: " << size_h << endl;
	cout << "Стоимость: " << price << endl;
}
