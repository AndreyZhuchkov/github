#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
void printArray(const vector<int> &); // Выводит массив на экран
void printArray(const vector<double> &);
void fillArray(vector<int> &, int); // Генерирует элементы массива
void fillArray(vector<double> &, int);
void selectionSort(vector<int> &); // Сортировка выбором
void selectionSort(vector<double> &);
int main() {
srand(time(NULL));
int size;
cout << "Введите размер массива: ";
cin >> size;
vector<int> arrI;
vector<double> arrD;
fillArray(arrI, size);
fillArray(arrD, size);
cout << "Входные массивы: " << endl;
cout << "Целые:\t";
printArray(arrI);
cout << "Вещественные:\t";
printArray(arrD);
selectionSort(arrI);
selectionSort(arrD);
cout << "Отсортированные массивы: " << endl;
cout << "Целые:\t";
printArray(arrI);
cout << "Вещественные:\t";
printArray(arrD);
system("pause");
return 0;
}
void printArray(const vector<int> &arr) {
for (int i = 0; i < arr.size(); i++) {
cout << arr[i] << ' ';
}
cout << endl;
}
void printArray(const vector<double> &arr) {
for (int i = 0; i < arr.size(); i++) {
cout << arr[i] << ' ';
}
cout << endl;
}
void selectionSort(vector<int> &arr) {
for (int i = arr.size() - 1; i > 0; i--) {
int maxn = 0;
for (int j = 1; j <= i; j++) {
if (arr[maxn] < arr[j]) {
  maxn = j;
}
}
int c = arr[maxn];
arr[maxn] = arr[i];
arr[i] = c;
}
}
void selectionSort(vector<double> &arr) {
for (int i = arr.size() - 1; i > 0; i--) {
int maxn = 0;
for (int j = 1; j <= i; j++) {
if (arr[maxn] < arr[j]) {
maxn = j;
}
}
double c = arr[maxn];
arr[maxn] = arr[i];
arr[i] = c;
}
}
void fillArray(vector<int> &arr, int size) {
for (int i = 0; i < size; i++) {
arr.push_back(rand() % 100);
}
}
void fillArray(vector<double> &arr, int size) {
for (int i = 0; i < size; i++) {
arr.push_back(((double)(rand() % 1000)) / 10);
}
}
