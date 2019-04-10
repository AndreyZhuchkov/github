#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Vector
{
private:
	double length, x, y, z;
public:
	Vector(double vector_x,double vector_y,double vector_z)
	{
		x = vector_x;
		y = vector_y;
		z = vector_z;
		len();
	}
	void len(void)
	{
		length = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	}
	void getInf(void)
	{
		cout << "Введите координаты вектора a = ( " << x << ", " << y << ", " << z << ") " << endl << "Длина вектора а = " << length << endl;
	}
};

int main()
{
	double length, x, y, z;
	cout << "Введите координату х вектора а: ";
	cin >> x;
	cout << "Введите координату у вектора a: ";
	cin >> y;
	cout << "Введите координату z вектора a: ";
	cin >> z;
	Vector a(x, y, z);
	a.getInf();
system ("pause");
	return 0;
}
