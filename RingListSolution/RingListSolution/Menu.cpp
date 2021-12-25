#include "Menu.h"

void menu(List &ringList)
{
    char key = '0';
    while (key != 'q')
    {
        system("cls");
        printMenu();
        cin >> key;
        switch (key)
        {
        case '1':
            addItemList(ringList);
            system("pause");
            break;
        case '2':
            readList(ringList);
            system("pause");
            break;
        case '3':
            updateItemList(ringList);
            system("pause");
            break;
        case '4':
            searchItem(ringList);
            system("pause");
            break;
        case '5':
            deleteItem(ringList);
            system("pause");
            break;
        case '6':
            saveList(ringList);
            system("pause");
            break;
        }
    }
}
void printMenu()
{
    cout << "Структура данных: 'Циклический односвязный список'" << endl;
    cout << "\nMENU";
    cout << "\n1. Добавить элемент списка";
    cout << "\n2. Чтение элементов списка";
    cout << "\n3. Изменение элемента списка";
    cout << "\n4. Поиск элемента из списка";
    cout << "\n5. Удаление элемента из списка";
    cout << "\n6. Сохранить объект класса в файл";
    cout << "\nВведите 'q' и нажмите ENTER для выхода из программы" << endl;
    cout << "\nВведите пункт из меню и нажмите ENTER: ";
}