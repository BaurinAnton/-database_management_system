#pragma once

#include "ApiUx.h"

/*!
 \brief Функция работы меню
 \param[in] List &ringList - адрес на объект ringList класса List.

 В данной функции производится работа меню программы. В меню находятся функции UX нашего API.
*/

void menu(List &ringList);

/*!
 \brief Функция вывода пунктов меню на экран

 В данной функции выводятся пункты меню на консоль. 
*/

void printMenu();