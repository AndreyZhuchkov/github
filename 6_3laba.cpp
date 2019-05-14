#include <iostream>
#include <string>
using namespace std;
class Animal {	// Базовый класс
protected:
	string name;
	int age;
public:
	Animal(string &name, int age) : name(name), age(age) {};
	string &getName() { return name; }
	int getAge() { return age; }
	virtual void talk() = 0;
};
class Dog : public Animal {	// Производные классы
public:
	Dog(string &name, int age) : Animal(name, age) {};
	void talk() { cout << "-Гав" << endl; }
};
class Cat : public Animal {
public:
	Cat(string &name, int age) : Animal(name, age) {};
	void talk() { cout << "-Мяу" << endl; }
};
int main() {
	string name;
	int age;
	cout << "Кошка" << endl;
	cout << "Введите кличку: ";
	cin >> name;
	cout << "Введите возраст: ";
	cin >> age;
	Cat c(name, age);
	cout << endl << "Собака" << endl;
	cout << "Введите кличку: ";
	cin >> name;
	cout << "Введите возраст: ";
cin >> age;
	Dog d(name, age);
	cout << endl << "Ваша собака" << endl << "Кличка: " << d.getName() << endl << "Возраст: " <<
			d.getAge() << endl;
	d.talk();
	cout << endl << "Ваша кошка" << endl << "Кличка: " << c.getName() << endl << "Возраст: " <<
			c.getAge() << endl;
	c.talk();
	return 0;
}
