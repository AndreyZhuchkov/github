#include <iostream>
#include <cmath>
using namespace std;
class Vector {
	double x;
	double y;
	double z;
public:
	Vector(double x, double y, double z);
	Vector(const Vector& v);
	void setVector(double x, double y, double z);
	double getModule();
	void print();
	Vector operator= (const Vector& v);
	friend Vector operator+ (const Vector& v1, const Vector& v2);
	friend Vector operator- (const Vector& v1, const Vector& v2);
};
int main() {
	double x, y, z;
	cout << "Введите координаты вектора:" << endl << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;
	cout << "z = ";
	cin >> z;
	Vector v1(x, y, z);
	Vector v2 = v1;
	Vector v3(v2);
	v1.print();
	v2.print();
v3.print();
	system("pause");
	return 0;
}
Vector::Vector(double x, double y, double z) { setVector(x, y, z); }
Vector::Vector(const Vector& v) {
	x = v.x;
	y = v.y;
	z = v.z;
}
void Vector::setVector(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}
double Vector::getModule() { return sqrt(x * x + y * y + z * z); }
void Vector::print() {
	cout << "Координаты вектора: (" << x << ", " << y << ", " << z << ")" << endl;
	cout << "Модуль: " << getModule() << endl;
}
Vector Vector::operator= (const Vector& v) { return Vector(v.x, v.y, v.z); }
Vector operator+ (const Vector& v1, const Vector& v2) {
	return Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}
Vector operator- (const Vector& v1, const Vector& v2) {
	return Vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}
