#include <iostream>
#include "property.h"
using namespace std;
int main()
{
    double worth;
    Property *property[7];
    for (int i = 0; i < 3; i++)
    {
        cout << "Введите стоимость аппартаментов: " << i + 1 << ": ";
        cin >> worth;
        property[i] = new Apartment(worth);
        cout << "Налог: " << property[i]->payment() << "$" << endl;
    }
    for (int i = 0; i < 2; i++)
    {
        cout << "Введите стоимость автомобиля: " << i + 1 << ": ";
        cin >> worth;
        property[i + 3] = new Car(worth);
        cout << "Налог " << property[i + 3]->payment() << "$" << endl;
    }
    for (int i = 0; i < 2; i++)
    {
        cout << "Введите стоимость загородного дома: " << i + 1 << ": ";
        cin >> worth;
        property[i + 5] = new CountryHouse(worth);
        cout << "Налог " << property[i + 5]->payment() << "$" << endl;
    }
    for (int i = 0; i < 7; i++)
        delete property[i];
    return 0;
}
