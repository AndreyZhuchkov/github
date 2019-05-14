#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class vector{
    private:
        float x;
        float y;
        float z;
    public: //конструктор  класса
        vector(float X,float Y,float Z){
            x=X;
            y=Y;
            z=Z;}
        friend ostream& operator<< (ostream &out, const vector &a);// перегрузка вывода
        friend istream& operator>>(istream& cin, vector &vector);// перегрузка ввода
        //сравниваются модули векторов
        friend bool  operator>(vector& lef,vector& rig);//перегрузка  знака больше
        friend bool  operator<(vector& lef,vector& rig);//перегрузка  знака меньше
        friend bool  operator==(vector& lef,vector& rig);//перегрузка  знака =
        vector& operator=(const vector& right){//перегрузка присваивания
        this->x=right.x;
        this->y=right.y;
        this->z=right.z;
        return *this;}
        friend bool  operator>(vector& lef,vector& rig);//перегрузка  знака больше
        friend bool  operator<(vector& lef,vector& rig);//перегрузка  знака меньше
        friend bool  operator==(vector& lef,vector& rig);//перегрузка  знака =
        };
ostream& operator<< (ostream &out, const vector &a){ // перегрузка вывода

    out<<a.x<<" " <<a.y<<" " <<a.z;
    return out;}

istream& operator>>(istream& cin, vector &a){  //перегрузка ввода
    cin>>a.x>>a.y>>a.z;
    return cin;
    }

bool operator>(vector& lef,vector& rig){ //перегрузка  знака >

        return pow(lef.x*lef.x+lef.y*lef.y+lef.z*lef.z,0.5)>pow(rig.x*rig.x+rig.y*rig.y+rig.z*rig.z,0.5);
        }
bool operator<(vector& lef,vector& rig){ //перегрузка  знака <

        return pow(lef.x*lef.x+lef.y*lef.y+lef.z*lef.z,0.5)<pow(rig.x*rig.x+rig.y*rig.y+rig.z*rig.z,0.5);
        }
bool operator==(vector& lef,vector& rig){ //перегрузка  знака ==

        return pow(lef.x*lef.x+lef.y*lef.y+lef.z*lef.z,0.5)==pow(rig.x*rig.x+rig.y*rig.y+rig.z*rig.z,0.5);
        }


int main(){
    vector q(0,0,0);
    vector wer(0,0,0);
    cout<<"Введите координаты первого вектора: ";
    cin>>q;
    wer=q;
    cout<<"Введите координаты второго вектора: ";
    cin>>q;
    if (q>wer) {
        cout<<"Модуль "<<q<<" больше модуля "<<wer<<endl;
    }
    else {
        cout<<"Модуль "<<wer<<" больше модуля  "<<q<<endl;
    }

    if (q<wer) {
        cout<<"Модуль "<<q<<" меньше модуля "<<wer<<endl;
    }
    else {
        cout<<"Модуль "<<wer<<" меньше модуля "<<q<<endl;
    }
    if (q==wer) {
        cout<<"Модуль "<<q<<" равен модулю "<<wer<<endl;
    }
    else {
        cout<<"Модуль "<<wer<<" не равен модулю "<<q<<endl;
    }
    return 0;}
