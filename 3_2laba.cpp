#include <iostream>
#include <string>
using namespace std;
class Tiles {
public:
	string brand;
	double size_w;
	double size_h;
	double price;
	void getData();	// Вывод данных на экран
};
int main() {
	Tiles t1;
	cout << "Введите производителя первой плитки: ";
	cin >> t1.brand;
	cout << "Введите ширину плитки: ";
	cin >> t1.size_w;
	cout << "Введите длину плитки: ";
	cin >> t1.size_h;
	cout << "Введите цену плитки: ";
	cin >> t1.price;
	Tiles t2;
	cout << "Введите производителя второй плитки: ";
	cin >> t2.brand;
	cout << "Введите ширину плитки: ";
	cin >> t2.size_w;
	cout << "Введите длину плитки ";
	cin >> t2.size_h;
	cout << "Введите цену плитки: ";
	cin >> t2.price;
	cout << "Первая плитка" << endl;
	t1.getData();
cout <<endl << "Вторая плитка" << endl;
	t2.getData();
  system ("pause");
	return 0;
}
void Tiles::getData() {
	cout << "Бренд: " << brand << endl;
	cout << "Ширина: " << size_w << endl;
	cout << "Длина: " << size_h << endl;
	cout << "Цена: " << price << endl;
}
