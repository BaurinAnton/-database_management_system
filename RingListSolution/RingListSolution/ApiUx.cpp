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
        cout << ringList << endl;
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
    cout << endl << "������� �������, ������� ������ �����: ";
    cin >> item;
    const vector<int> numberItem = ringList.searchItem(item);
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

void saveList(List& ringList)
{
    ofstream out;          
    out.open("../hello.txt"); 
    if (out.is_open())
    {
        out << ringList << endl;
    }
    cout << "������ �������!" << endl;
}
