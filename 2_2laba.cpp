#include<iostream>
using namespace std;

typedef int* (*c)(int *a,int n);

int*  functionvozr(int *a,int n){
    int mn,A;
    for (int i=0;i<n-1;i++){//функция сортировки по возрастанию
        mn=a[i];
        A=i;
        for (int k=i+1;k<n;k++){
            if (mn>a[k]){
                mn=a[k];
                A=k;
            }
        }
        swap(a[i],a[A]);
        }
        return a;
    }

int*  functionubl(int *a,int n){//функция сортировки по убыванию
    int mn,A;
    for (int i=0;i<n-1;i++){
        mn=a[i];
        A=i;
        for (int k=i+1;k<n;k++){
            if (mn<a[k]){
                mn=a[k];
                A=k;
            }
        }
        swap(a[i],a[A]);
        }
        return a;
    }

int*  invert(int *a,int n){//функция инвертирования массива
    int e=n/2;
    for (int i=0;i<(e);i++){
        swap(a[i],a[n-i-1]);
            }
        return a;
    }
c funcdef(int *a,int n){//функция для выбора функции
        int* (*q)(int *a,int n);//для работы с массивом

        int s=0;
        for (int i=0;i<n;i++){
            s=s+a[i];
        }
        if (s==a[0]) {q=&invert; return q;}
        if (s>a[0]) {q=&functionvozr;}
        else  {q=&functionubl;}
        return q;
    }
int main() {//выбирается функция и действие с массивом
      int k;//в зависимости от суммы элементов
      cout<<"Введите размер массива: ";
      cin>>k;
      int* mas = new int[k];
      for (int i=0;i<k;i++){
        cout<<"Введите элемент A"<<"["<<i+1<<"]"<<"= ";
        cin>>mas[i];
      }
      funcdef(mas,k)(mas,k);
      for (int i=0;i<k;i++){
        cout<<mas[i]<<" ";
      }
     return 0;}
