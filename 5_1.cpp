#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
void printArray(const vector<int> &); // Выводит массив на экран
void printArray(const vector<double> &);
void fillArray(vector<int> &, int); // Создает элементы массива
void fillArray(vector<double> &, int);
void bubbleSort(vector<int> &); // Сортирует пузырьком
void bubbleSort(vector<double> &);
int main() {
srand(time(NULL));
int size;
cout << "Введите размер массива: ";
cin >> size;
vector<int> arrI;
vector<double> arrD;
fillArray(arrI, size);
fillArray(arrD, size);
cout << "Исходные массивы: " << endl;
cout << "Целые:\t";
printArray(arrI);
cout << "Вещественный:\t";
printArray(arrD);
bubbleSort(arrI);
bubbleSort(arrD);
cout << "Отсортированный массив: " << endl;
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
void bubbleSort(vector<int> &arr) {
for (int i = arr.size() - 1; i > 0; i--) {
for (int j = 0; j < i; j++) {
if (arr[j] > arr[j + 1]) {
int c = arr[j];
arr[j] = arr[j + 1];
arr[j + 1] = c;
}
}
}
}
void bubbleSort(vector<double> &arr) {
for (int i = arr.size() - 1; i > 0; i--) {
for (int j = 0; j < i; j++) {
if (arr[j] > arr[j + 1]) {
double c = arr[j];
arr[j] = arr[j + 1];
arr[j + 1] = c;
}
}
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
