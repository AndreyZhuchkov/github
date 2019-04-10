#include <iostream>
#include <string>
using namespace std;
class CppStudio
{
  private:
string name,surname,lastname;
string date,month,year;
public:
void messege ()
{
cout << "Данные о студенте: \n";
}
void setdate(string date_surname ,string date_name,string date_lastname, string date_date, string date_month, string date_year )
{

surname = date_surname;
name = date_name;
lastname = date_lastname;
date = date_date;
month = date_month;
year = date_year;
}
void getDate(void)
{
cout << "Ф.И.О : " << surname <<" " << name << " "<<lastname <<"\n"<< "Дата рождения в виде: дд.мм.гг."<< date << "." <<month<< "."<< year<< "."<< endl ;
}
};
int main(int argc, char* argv[])
{
setlocale (LC_ALL, "Russia");
string month,date, year;
string surname,name,lastname;
cout << "Введите данные студента:\n";
cout << "Фамилия Имя Отчество: ";
cin >> surname >> name >> lastname ;
cout << "Введите дату рождения студента в  формате дд.мм.гг.";
cin >> date >> month >> year;
CppStudio objCppstudio;
objCppstudio.messege();
objCppstudio.setdate (surname,name,lastname,date,month,year);
objCppstudio.getDate();
return 0;
}
