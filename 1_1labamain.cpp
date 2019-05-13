#include "Complex.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
complexnumber cn1,cn2;
string s;
char q;
cout<<"Введите действительную часть первого комплексного числа: "; cin>>cn1.re;
cout<<"Введите мнимую часть первого комплексного числа: ";
cin>>cn1.im;
cout<<"Выберите операцию (+,-,/,*): ";
cin>>s;
if (s=="abs"){
cout<<arifm(&cn1);
}
else {
cout<<"Введите действительную часть второго комплексного числа: ";
cin>>cn2.re;
cout<<"Введите мнимую часть второго комплексного числа: ";
cin>>cn2.im;
q=s[0];
arifm(q, &cn1, &cn2);
}

return 0;}
