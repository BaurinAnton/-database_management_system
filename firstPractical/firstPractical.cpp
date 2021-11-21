#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

//Функция заполнения одномерного массива
void fillingTheArray(int arraySize, char *ptrarray) {
    //Функция srand генерирует псевдослучайные числа относительно 
    //возвращенного значения времени в секундах на данный момент
    //unsigned - целое положительное число.
    srand(unsigned(time(NULL)));
    //Заполнение одномерного массива псевдослучайными числами и вывод одномерного массива
    cout << endl << "Заполнения массива псевдослучайными числами";
    cout << endl << "Одномерный массив = ";
    for (int count = 0; count < arraySize; count++) {
        //Данный диапазон чисел по таблице ASII - заглавные буквы английского алфавита
        //Причина данного диапазона - наглядное отображения одномерного массива в консоли
        ptrarray[count] = 65 + rand() % (90 - 65 + 1);
        cout << ptrarray[count];
    }
}

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
    //Функция заполнения массива
    fillingTheArray(arraySize, ptrarray);
    delete [] ptrarray;
}
