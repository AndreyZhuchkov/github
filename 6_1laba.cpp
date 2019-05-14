#include <iostream>
#include <string>
using namespace std;
class Student {	// базовый класс "Студент"
	string name;
	string surname;
	int age;
public:
	Student(string &name, string &surname, int age) : name(name), surname(surname), age(age) {};
	string &getName() { return name;	}
	string &getSurname() { return surname; }
	int getAge() { return age; }
};
class Headman : public Student {	// Класс "Староста", производный от "Студент"
	string phone;
	string email;
public:
	Headman(string &name, string &surname, int age, string &phone, string &email) :
		Student(name, surname, age), phone(phone), email(email) {};
	string &getEmail() { return email; }
	string &getPhone() { return phone; }
	friend const ostream& operator<< (ostream& out, const Headman& h);
};
int main() {

	string name, surname, phone, email;
	int age;
	cout << "Введите имя: ";
	cin >> name;
	cout << "Введите фамилию: ";
	cin >> surname;
	cout << "Введите возраст: ";
	cin >> age;
	cout << "Введите мобильный телефон: ";
	cin >> phone;
	cout << "Введите Email: ";
	cin >> email;
	Headman h(name, surname, age, phone, email);
	cout << endl << "Информация о старосте:" << endl;
	cout << "Имя: " << h.getName() << endl;
	cout << "Фамилия: " << h.getSurname() << endl;
	cout << "Возраст: " << h.getAge() << endl;
	cout << "Мобильный телефон: " << h.getPhone() << endl;
	cout << "Email: " << h.getEmail() << endl;
	cout << "Обо мне: " << h;
	cout << endl;

	return 0;
}
const ostream& operator<< (ostream& out, const Headman& h) {
	out << "Я очень дружелюбный!";
	return out;
}
