#include <iostream>
#include <string>
using namespace std;
class Alive {	// Базовый класс
protected:
	string name;
	int age;
public:
	Alive(string &name, int age) : name(name), age(age) {};
	string &getName() { return name; }
	int getAge() { return age; }
	virtual void move() = 0;
};
class Animal : public Alive {	// Производные классы
public:
	Animal(string &name, int age) : Alive(name, age) {};
	void move() { cout << name << " может укусить!" << endl; }
};
class Fish : public Alive {
public:
	Fish(string &name, int age) : Alive(name, age) {};
	void move() { cout << name << " умеет плавать" << endl; }
};
class Bird : public Alive {
public:
	Bird(string &name, int age) : Alive(name, age) {};
	void move() { cout << name << " умеет летать";	}
};
int main() {
	string name;
	int age;
	cout << "Рыба" << endl;
	cout << "Введите имя: ";
	cin >> name;
	cout << "Введите возраст: ";
	cin >> age;
	Fish f(name, age);
	cout << endl << "Животное" << endl;
	cout << "Введите имя: ";
	cin >> name;
	cout << "Введите возраст: ";
	cin >> age;
	Animal a(name, age);
	cout << endl << "Птица" << endl;
	cout << "Введите имя: ";
	cin >> name;
	cout << "Введите возраст: ";
	cin >> age;
	Bird b(name, age);
	cout << endl << "Ваша птица" << endl << "Кличка: " << b.getName() << endl << "Возраст: " <<
			b.getAge() << endl;
	b.move();
	cout << endl << "Ваша рыбка" << endl << "Кличка: " << f.getName() << endl << "Возраст: " <<
			f.getAge() << endl;
	f.move();
	cout << endl << "Ваше животное" << endl << "Кличка: " << a.getName() << endl << "Возраст: " <<
			a.getAge() << endl;
	a.move();
	system("pause");
	return 0;
}
