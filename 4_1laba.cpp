#include <iostream>
#include <string>
using namespace std;
class Child {
	string name;
	string surname;
	int age;
public:
	Child(string&, string&, int);	// Конструкторы класса
	Child(const Child&);
	Child operator= (const Child&);
	void setName(string& name) { this->name = name; }	// Методы ввода данных
	void setSurname(string& surname) { this->surname = surname;	}
	void setAge(int age) { this->age = age;	}
	void print();	// Выводит данные на экран
	~Child() {} //Деструктор класса
};
int main() {
	string name, surname;
	int age;
	cout << "Введите имя первого ребенка: ";
	cin >> name;
	cout << "Введите фамиилию первого ребенка: ";
	cin >> surname;
	cout << "Введите возраст первого ребенка: ";
	cin >> age;
	Child first(name, surname, age);
	Child second(first);
	Child third = second;
	first.print();
	second.print();
	third.print();
	system("pause");
	return 0;
}
Child Child::operator= (const Child& c) {
	this->name = c.name;
	this->age = c.age;
	this->surname = c.surname;
	return *this;
}
Child::Child(const Child& c) {
	name = c.name;
	surname = c.surname;
	age = c.age;
}
Child::Child(string& name, string& surname, int age) {
	setName(name);
	setSurname(surname);
	setAge(age);
}
void Child::print() {
	cout << "Имя " << name << endl;
	cout << "Фамилия: " << surname << endl;
	cout << "Возраст: " << age << endl;
}
