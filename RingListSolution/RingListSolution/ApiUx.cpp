#include "ApiUx.h"

void addItemList(List &ringList)
{
    int dataItem;
    cout << endl << "Введите значение элемента списка: ";
    cin >> dataItem;
    ringList.addItem(dataItem);
    cout << endl << "Элемент добавлен." << endl;
}

void readList(List &ringList)
{
    const size_t emptyList = 0;
    if (ringList.size() != emptyList) {
        cout << endl << "Элементы списка: ";
        ringList.read();
        cout << endl;
    }
    else {
        cout << endl << "Список пуст. Заполните список." << endl;
    }
}

void updateItemList(List &ringList)
{
    int numberItem;
    int setDataItem;
    readList(ringList);
    cout << endl << "Введите номер элемента, который хотите изменить: ";
    cin >> numberItem;
    if (numberItem > ringList.size() || numberItem == 0) {
        cout << "Вы ввели некорректный номер элемента. Повторите попытку.";
    }
    else {
        cout << endl << "Введите значение числа: ";
        cin >> setDataItem;
        ringList.updateItem(numberItem, setDataItem);
        cout << endl << "Элемент под номером " << numberItem << " изменён.";
        readList(ringList);
    }
}

void searchItem(List &ringList)
{
    int item;
    vector<int> numberItem;
    cout << endl << "Введите элемент, который хотите найти: ";
    cin >> item;
    ringList.searchItem(item, numberItem);
    if (numberItem.size() == 0) {
        cout << endl << "Увы, но элемент " << item << " не найден." << endl;
    }
    else {
        for (int i = 0; i < numberItem.size(); i++)
        {
            cout << "Элемент найден! Он находится на " << numberItem[i] << " месте";
        }
    }
    cout << endl;
}

void deleteItem(List &ringList)
{
    int numberItem;
    const int nonexistentItem = 0;
    readList(ringList);
    cout << endl << "Введите элемент, который хотите удалить: ";
    cin >> numberItem;
    if (numberItem > ringList.size() || numberItem <= nonexistentItem) {
        cout << "Вы ввели некорректный номер элемента. Повторите попытку." << endl;
    }
    else {
        ringList.deleteItem(numberItem);
        cout << endl << "Элемент под номером " << numberItem << " удалён.";
        readList(ringList);
    }
    cout << endl;
}

void iteratorItem(List &ringList)
{
    cout << "Итератор запущен." << endl;
    ringList.iteratorItem();
    cout << endl;
}