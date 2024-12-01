#pragma once
#include "Interface.h"

void Interface::start()
{
    do
    {
        cout << "Выберите тип элементов\n";
            cout << "1. Предприниматель\n";
            cout << "2. Турист\n";
            cout << "3. Бизнесмен\n";
            cout << "4. Выход\n";
            type = GetInt(1, 4);
        system("cls");
        switch (type)
        {
        case 1:
        {
            Ring<Predprem> RingList;
            OperatingRing(RingList);
        }
        break;
        case 2:
        {
            Ring<Tourist> RingList;
            OperatingRing(RingList);
        }
        break;
        case 3:
        {
            Ring<Business> RingList;
            OperatingRing(RingList);
        }
        break;
        }
    } while (type != 4);
}

template<typename T>
void Interface::OperatingRing(Ring<T>& list)
{
    T element;
    do
    {
        cout << "Действия с кольцом\n";
        GREEN
            cout << "1. Создать элементы\n";
        cout << "2. Посмотреть данные\n";
        cout << "3. Вывести текущий узел\n";
        RED
            cout << "4. Удалить текущий узел\n";
        cout << "5. Удалить все узлы\n";
        BLUE
            cout << "6. Поиск по параметру\n";
        cout << "7. Проверить есть ли узлы\n";
        cout << "8. Найти человека с максимальным возрастом\n";
        cout << "9. Найти человека с минимальным возрастом\n";
        YELLOW
            cout << "10. Выход\n";
        RESET
            choise = GetInt(1, 10);
        system("cls");
        switch (choise)
        {
        case 1:
        {
            GREEN
                cout << "Введите количество элементов:\n";
            RESET
                int number;
            number = GetInt(1, 99);
            for (int i = 0; i < number; i++)
            {
                GREEN
                    cout << "Вводите элемент:\n";
                RESET
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
            GREEN
                cout << "Содержимое кольца:\n";
            RESET
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
                    GREEN
                        cout << "Данный элемент содержится в кольце" << endl;
                    RESET
                }
                else
                {
                    RED
                        cout << "Данный элемент не содержится в кольце или оно пустое" << endl;
                    RESET
                }
            system("pause");
        }
        break;
        case 7:
        {

            if (list.Empty())
            {
                RED
                    cout << "Кольцо пустое!" << endl;
                RESET
            }
            else
            {
                BLUE
                    cout << "В кольце содержатся элементы!" << endl;
                RESET
            }

            system("pause");
            system("cls");
        }
        break;
        case 8:
        {
            BLUE
                cout << "Человек с максимальным возрастом:\n";
            RESET
                list.FindMax();
            system("pause");
            system("cls");
        }
        break;
        case 9:
        {
            BLUE
                cout << "Человек с минимальным возрастом:\n";
            RESET
                list.FindMin();
            system("pause");
            system("cls");
        }
        break;
        case 10:break;
        default:
        {
            RED
                cout << "Введен неверный номер!!!\n";
            RESET
                system("pause");
            system("cls");
        }
        }
        system("cls");
    } while (choise != 10);
}
