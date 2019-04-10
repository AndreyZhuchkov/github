#include <iostream>
#include <string>
using namespace std;
class CppStudio
{
  private:
string name,model,number,color,mileage;
public:
void messege ()
{
cout << "Данные о машине: \n";
}
void setdate(string date_name ,string date_model, string date_number,string date_color, string date_mileage )
{

name = date_name;
model = date_model;
number = date_number;
color = date_color;
mileage = date_mileage;
}
void getDate(void)
{
cout << "Марка автомобиля: " << name <<"\n"<<"Модель автомобиля: "<<model<<"\n"<< "Номер: "<< number <<"\n"<< "Цвет: " <<color<<"\n"<<"Пробег: "<<mileage ;
}
};
int main(int argc, char* argv[])
{
setlocale (LC_ALL, "Russia");
string name,model,number,color,mileage;
cout << "Введите марку автомобиля: ";
cin >> name;
cout << "Введите модель автомобиля: ";
cin >> model;
cout << "Введите номер автомобиля: ";
cin >>  number ;
cout << "Введите цвет автомобиля: ";
cin >> color;
cout <<"Введите пробег автомобиля: ";
cin >> mileage;
CppStudio objCppstudio;
objCppstudio.messege();
objCppstudio.setdate (name,model,number,color,mileage);
objCppstudio.getDate();
return 0;
}
