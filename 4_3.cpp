#include <iostream>
#include <random>
using namespace std;
void set_data(int **Arr, int line, int column);
void get_data(int **Arr, int line, int column);
int main()
{
    int **Arr = nullptr;
    int line, column;
    cout << "Введите количество строк: ";
    cin >> line;
    cout << "Введите количество столбцов: ";
    cin >> column;
    Arr = new int *[line];
    for (int i = 0; i < line; i++)
    {
        Arr[i] = new int [column];
    }
    set_data(Arr, line, column);
    get_data(Arr, line, column);
    //удаление из памяти массива
    for (int i = 0; i < line; i++)
    {
        delete [] Arr[i];
    }
    delete [] Arr;
    return 0;
}
//заполнение массива рандомными числами
void set_data(int **Arr, int line, int column)
{
    default_random_engine random;
    uniform_int_distribution<int> interval(10, 50);
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < column; j++)
        {
            Arr[i][j] = interval(random);
        }
    }
}
//Функция вывода массива на экран
void get_data(int **Arr, int line, int column)
{
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << Arr[i][j] <<" ";
        }
        cout << endl;
    }
}
