#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

/*!
 \brief Функция заполнения массива
 \param[in] arraySize - размер массива.
 \param[in] *ptrarray - ссылка на первый элемент динамического массива.

 Данная функция заполняет динамический массив символами char.
 В данной функции используется генератор псевдослучайных чисел, реализуемый функцией srand().
 Диапазон генерируемых чисел выбран такой, что генерируются char, соответствующие по таблице ASII заглавным английским буквам.
*/

void fillingArray(int arraySize, char* ptrarray);

/*!
 \brief Функция сортировки массива
 \param[in] arraySize - размер массива.
 \param[in] *ptrarray - ссылка на первый элемент динамического массива.

 Данная функция сортирует элементы динамического массива по возрастанию методом выбора.
*/

void sortingAnArray(int arraySize, char* ptrarray);

/*!
 \brief Функция вывода динамического массива в консоль.
 \param[in] arraySize - размер массива.
 \param[in] *ptrarray - ссылка на первый элемент динамического массива.

 Данная функция выводит элементы динамического массива в консоль.
*/

void outputAnArrayToConsole(int arraySize, char* ptrarray);

/*!
 \brief Функция очистки памяти динамического массива.
 \param[in] *ptrarray - ссылка на первый элемент динамического массива.

 Данная функция очищает память, выделенную под динамический массив.
*/

void clearingMemoryFromAnArray(char* ptrarray);

/*!
 \brief Главная функция.
 В данной функции вводится с клавиатуры размер будущего динамического массива.
 Инициализируется динамический массив.
 Выполняются функции заполнения, сортировки, вывода на консоль, очистки памяти динамического массива.
*/

int main()
{
    setlocale(LC_ALL, "Russian");
    int arraySize;
    cout << "Введите размер одномерного массива:";
    cin >> arraySize;
    char* ptrarray = new char[arraySize];
    fillingArray(arraySize, ptrarray);
    cout << endl << "Заполнения массива псевдослучайными числами";
    cout << endl << "Одномерный массив = ";
    outputAnArrayToConsole(arraySize, ptrarray);
    cout << endl << "Сортировка массива" << endl;
    sortingAnArray(arraySize, ptrarray);
    outputAnArrayToConsole(arraySize, ptrarray);
    clearingMemoryFromAnArray(ptrarray);
}

void fillingArray(int arraySize, char* ptrarray) {
    const int initialValueOfTheRange = 65;
    const int finalValueOfTheRange = 90;
    const int rangeOffset = 1;
    srand(unsigned(time(NULL)));
    for (int count = 0; count < arraySize; count++) {
        ptrarray[count] = initialValueOfTheRange + rand() % (finalValueOfTheRange - initialValueOfTheRange + rangeOffset);
    }
}

void sortingAnArray(int arraySize, char* ptrarray) {
    int j = 0;
    int tmp = 0;
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
    }
}
void outputAnArrayToConsole(int arraySize, char* ptrarray) {
    for (int count = 0; count < arraySize; count++) {
        cout << ptrarray[count];
    }
    cout << endl;
}
void clearingMemoryFromAnArray(char* ptrarray) {
    if (ptrarray != nullptr)
    {
        delete[] ptrarray;
        ptrarray = nullptr;
    }
}