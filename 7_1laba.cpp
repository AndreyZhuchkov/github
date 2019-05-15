#include <iostream>
#include <string>
using namespace std;
class Human {
protected:
	string name;
	string surname;
	string midname;
	int age;
public:
	Human() : name(""), surname(""), midname(""), age(0) {};
	Human(string surname, string name, string midname, int age) :
		name(name), surname(surname), midname(midname), age(age) {};
	virtual void print() = 0;
	~Human() {}
};
class Student : public Human {
	bool on_lesson;
public:
	Student() : Human(), on_lesson(false) {};
	Student(string surname, string name, string midname, int age, bool on_lesson) :
		Human(surname, name, midname, age), on_lesson(on_lesson) {};
	void print();
	~Student() {};
};
class Boss : public Human {
	int number_of_workers;
public:
	Boss() : Human(), number_of_workers(0) {};
	Boss(string surname, string name, string midname, int age, int number_of_workers) :
		Human(surname, name, midname, age), number_of_workers(number_of_workers) {};
	void print();
	~Boss() {};
};
int main() {

	string surname, name, midname;
	int age, number_of_workers;
	bool on_lesson;
	cout.setf(ios::boolalpha);
	cout << "Студент" << endl;
	cout << "Введите фамилию: ";
	cin >> surname;
	cout << "Введите имя: ";
	cin >> name;
	cout << "Введите отчество: ";
	cin >> midname;
	cout << "Введите возраст: ";
	cin  >> age;
	cout << "Присутствует на паре: (1-да 0-нет)";
	cin >> on_lesson;
	Student s(surname, name, midname, age, on_lesson);
	cout << endl << "Босс" << endl;
	cout << "Введите фамилию: ";
	cin >> surname;
	cout << "Введите имя: ";
	cin >> name;
	cout << "Введите отчество: ";
	cin >> midname;
	cout << "Введите возраст: ";
	cin  >> age;
	cout << "Введите количество учащихся: ";
	cin >> number_of_workers;
	Boss b(surname, name, midname, age, number_of_workers);
	s.print();
	b.print();
	return 0;
}
void Student::print() {
	cout << "Имя: " << surname << " " << name << " " << midname << endl;
	cout << "Возраст: " << age << endl;
	cout << "На паре: " << on_lesson << endl;
}
void Boss::print() {
	cout << "Имя: " << surname << " " << name << " " << midname << endl;
	cout << "Возраст: " << age << endl;
	cout << "Количество учащихся: " << number_of_workers << endl;
}
