#include "ApiUx.h"

void addItemList(List &ringList)
{
    int dataItem;
    cout << endl << "������� �������� �������� ������: ";
    cin >> dataItem;
    ringList.addItem(dataItem);
    cout << endl << "������� ��������." << endl;
}

void readList(List &ringList)
{
    const size_t emptyList = 0;
    if (ringList.size() != emptyList) {
        cout << endl << "�������� ������: ";
        ringList.read();
        cout << endl;
    }
    else {
        cout << endl << "������ ����. ��������� ������." << endl;
    }
}

void updateItemList(List &ringList)
{
    int numberItem;
    int setDataItem;
    readList(ringList);
    cout << endl << "������� ����� ��������, ������� ������ ��������: ";
    cin >> numberItem;
    if (numberItem > ringList.size() || numberItem == 0) {
        cout << "�� ����� ������������ ����� ��������. ��������� �������.";
    }
    else {
        cout << endl << "������� �������� �����: ";
        cin >> setDataItem;
        ringList.updateItem(numberItem, setDataItem);
        cout << endl << "������� ��� ������� " << numberItem << " ������.";
        readList(ringList);
    }
}

void searchItem(List &ringList)
{
    int item;
    vector<int> numberItem;
    cout << endl << "������� �������, ������� ������ �����: ";
    cin >> item;
    ringList.searchItem(item, numberItem);
    if (numberItem.size() == 0) {
        cout << endl << "���, �� ������� " << item << " �� ������." << endl;
    }
    else {
        for (int i = 0; i < numberItem.size(); i++)
        {
            cout << "������� ������! �� ��������� �� " << numberItem[i] << " �����";
        }
    }
    cout << endl;
}

void deleteItem(List &ringList)
{
    int numberItem;
    const int nonexistentItem = 0;
    readList(ringList);
    cout << endl << "������� �������, ������� ������ �������: ";
    cin >> numberItem;
    if (numberItem > ringList.size() || numberItem <= nonexistentItem) {
        cout << "�� ����� ������������ ����� ��������. ��������� �������." << endl;
    }
    else {
        ringList.deleteItem(numberItem);
        cout << endl << "������� ��� ������� " << numberItem << " �����.";
        readList(ringList);
    }
    cout << endl;
}

void iteratorItem(List &ringList)
{
    cout << "�������� �������." << endl;
    ringList.iteratorItem();
    cout << endl;
}