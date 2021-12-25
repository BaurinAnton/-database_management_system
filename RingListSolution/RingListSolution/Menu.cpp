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
    cout << "��������� ������: '����������� ����������� ������'" << endl;
    cout << "\nMENU";
    cout << "\n1. �������� ������� ������";
    cout << "\n2. ������ ��������� ������";
    cout << "\n3. ��������� �������� ������";
    cout << "\n4. ����� �������� �� ������";
    cout << "\n5. �������� �������� �� ������";
    cout << "\n6. ��������� ������ ������ � ����";
    cout << "\n������� 'q' � ������� ENTER ��� ������ �� ���������" << endl;
    cout << "\n������� ����� �� ���� � ������� ENTER: ";
}