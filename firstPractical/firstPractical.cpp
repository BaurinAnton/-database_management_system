﻿#include <iostream>
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

//Функция сортировки выбором одномерного массива
void sortingAnArray(int arraySize, char* ptrarray) {
    cout << endl << endl << "Сортировка массива" << endl;
    int j = 0;
    int tmp = 0;
    cout << "Массив после сортировки: ";
    for (int i = 0; i < arraySize; i++) {
        j = i;
        for (int k = i; k < arraySize; k++) {
            if (ptrarray[j] > ptrarray[k]) {
                j = k;
            }
        }
        tmp = ptrarray[i];
        ptrarray[i] = ptrarray[j];
        ptrarray[j] = tmp;
        cout << ptrarray[i];
    }
    cout << endl;
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
    //Функция сортировки одномерного массива
    sortingAnArray(arraySize, ptrarray);
    delete [] ptrarray;
}
