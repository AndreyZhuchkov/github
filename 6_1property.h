#ifndef PROPERTY_H
#define PROPERTY_H
#include<iostream>
using namespace std;
class Property
{
public:
    Property(double worth);
    virtual double payment(void) = 0;
    virtual ~Property();
protected:
    double worth;
};
class Apartment : public Property
{
public:
    Apartment(double worth);
    double payment(void);
};
class Car : public Property
{
public:
    Car(double worth);
    double payment(void);
};
class CountryHouse : public Property
{
public:
    CountryHouse(double worth);
    double payment(void);
};
#endif
