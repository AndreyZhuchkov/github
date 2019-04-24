#include "property.h"
Property::Property(double worth)
{
    this->worth = worth;
}
Property::~Property() {}
Apartment::Apartment(double worth):Property(worth){}
Car::Car(double worth):Property(worth) {}
CountryHouse::CountryHouse(double worth):Property(worth) {}
double Apartment::payment(void)
{
    return worth / 1000;
}
double Car::payment(void)
{
    return worth / 200;
}
double CountryHouse::payment(void)
{
    return worth / 500;
}
