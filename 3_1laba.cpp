#include <iostream>
#include <string>
using namespace std;
class Child {
string name;
string surname;
int age;
public:
Child(string&, string&, int);
//Методы ввода данных о ребенке
void setName(string& name) { this->name = name; }
void setSurname(string& surname) { this->surname = surname; }
void setAge(int age) { this->age = age; }
void print(); // Вывод информации на экран
};
int main() {
int age;
string name, surname;
cout << "Введите имя первого ребенка: ";
cin >> name;
cout << "Введите фамилию первого ребенка: ";
cin >> surname;
cout << "Введите возраст первого ребенка: ";
cin >> age;
Child first(name, surname, age);
cout << "Введите имя второго ребенка: ";
cin >> name;
cout << "Введите фамилию второго ребенка: ";
cin >> surname;
cout << "Введите возраст второго ребенка: ";
cin >> age;
Child second(name, surname, age);
first.print();
second.print();
return 0;
}
Child::Child(string& name, string& surname, int age) {
setName(name);
setSurname(surname);
setAge(age);
}
void Child::print() {
cout << "Имя: " << name << endl;
cout << "Фамилия: " << surname << endl;
cout << "Возраст: " << age << endl;
}
