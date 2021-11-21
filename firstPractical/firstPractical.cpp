#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    //Объявление переменной размерности одномерного массива
    int arraySize;
    cout << "Введите размер одномерного массива:";
    //Ввод размерности одномерного массива
    cin >> arraySize;
    //Объявление динамического одномерного массива
    //* ptrarray - адрес первого элемента массива
    char* ptrarray = new char[arraySize];
    delete [] ptrarray;
}
