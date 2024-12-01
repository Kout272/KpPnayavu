#pragma once
#include "Interface.h"

void Interface::start()
{
    cout << "�������� �������� ��� �������� �� ������ ����� ���� ������ �����\n";
}
//����� ������� �� ��� ��������� �������� � ����� ������



//���������� ���������� ��� ����� �����
template<typename T>
void Interface::OperatingRing(Ring<T>& list)
{
    T element;
    do
    {
        cout << "�������� � ���������� ���������\n";
        cout << " 1. �������� �������\n";
        cout << " 2. ���������� ��� ���������\n";
        cout << " 3. ���������� ������� �������\n";
        cout << " 4. ������� ������� �������\n";
        cout << " 5. ������� ��� ��������\n";
        cout << " 6. ����� �������� �� ���������\n";
        cout << " 7. ��������� ���� �� ��������\n";
        cout << " 8. ������������� �������\n";
        cout << " 9. ������ ���������� ��������\n";
        cout << "10. ������ ������ ���������� ��������\n";
        cout << "11. ���� TXT\n";
        cout << "12. ���� BIN\n";
        cout << "13. �����\n";
        choise = GetInt(1, 13);
        system("cls");
        switch (choise)
        {
        case 1:
        {
                cout << "������� ���������� ���������:\n";
                int number;
            number = GetInt(1, 99);
            for (int i = 0; i < number; i++)
            {
                    cout << "������� �������:\n";
                    cin >> element;
                rewind(stdin);
                list.Push(element);
            }
            system("pause");
            system("cls");
        }
        break;
        case 2:
        {
                cout << "���������� ������:\n";
                if (!list.Empty())element.shapka();
            list.Display();
            system("pause");
            system("cls");
        }
        break;
        case 3:
        {
            list.ShowCurrent();
            system("pause");
            system("cls");
        }
        break;
        case 4:
        {
            list.RemoveCurrent();
            system("pause");
            system("cls");
        }
        break;
        case 5:
        {
            list.RemoveAll();
            system("pause");
            system("cls");
        }
        break;
        case 6:
        {
            BLUE
                if (list.Search())
                {
                        cout << "������ ������� ���������� � ������" << endl;
                }
                else
                {
                        cout << "������ ������� �� ���������� � ������ ��� ��� ������" << endl;
                }
            system("pause");
        }
        break;
        case 7:
        {

            if (list.Empty())
            {
                    cout << "������ ������!" << endl;
            }
            else
            {
                    cout << "� ������ ���������� ��������!" << endl;
            }

            system("pause");
            system("cls");
        }
        break;
        case 8:
        {
                cout << "������� � ������������ ���������:\n";
                list.FindMax();
            system("pause");
            system("cls");
        }
        break;
        case 9:
        {
                cout << "������� � ����������� ���������:\n";
                list.FindMin();
            system("pause");
            system("cls");
        }
        break;
        case 10:break;
        default:
        {
                cout << "������ �������� �����!!!\n";
                system("pause");
            system("cls");
        }
        }
        system("cls");
    } while (choise != 10);
}
