#pragma once
#include"Reseter.h"
#include"Item.h"
#include "Interface.h"

//void Interface::start()
//{
//    cout << "�������� �������� ��� �������� �� ������ ����� ���� ������ �����\n";
//}
//���������� ���������� ��� ����� �����
template<typename T>
void Interface::OperatingRing(Ring<T>& list)
{
    LinkedList<Ring<Item>> reseter;
    reseter.insertRight(list);
    if (!list.Empty())
        reseter.insertRight(list);
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
        cout << "12. �����\n";
        choise = GetInt(1, 12);
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
            if(cz != 0)
            {
                for (int i = 0;i < cz;i++)
                    reseter.removeRight();
                cz = 0;
            }
            reseter.insertRight(list);
            reseter.tailCursor();
        }
        break;
        case 2:
        {
                cout << "���������� ������:\n";
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
            reseter.insertRight(list);
            system("pause");
            system("cls");
        }
        break;
        case 5:
        {
            list.RemoveAll();
            reseter.insertRight(list);
            system("pause");
            system("cls");
        }
        break;
        case 6:
        {
             /*   if (list.Search())
                {
                        cout << "������ ������� ���������� � ������" << endl;
                }
                else
                {
                        cout << "������ ������� �� ���������� � ������ ��� ��� ������" << endl;
                }
            system("pause");*/
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
                
            system("pause");
            system("cls");
        }
        break;
        case 9:
        {
            cz++;
            --reseter;
            list = reseter.getValue();
            system("pause");
            system("cls");
        }
        break;
        case 10:break;
        default:
        {
            if (cz != 0)
            {
                cz--;
                ++reseter;
                list = reseter.getValue();
            }
                system("pause");
            system("cls");
        }
        }
        system("cls");
    } while (choise != 13);
}