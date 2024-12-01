#pragma once
#include "Interface.h"

void Interface::start()
{
    cout << "Создайте человека для которого вы хотите вести учет дичных вещей\n";
}
//Здесь сделать то как добавлять человека в самом начале



//Переделать функционал для всего этого
template<typename T>
void Interface::OperatingRing(Ring<T>& list)
{
    T element;
    do
    {
        cout << "Действия с коллекцией пердметов\n";
        cout << " 1. Добавить предмет\n";
        cout << " 2. Посмотреть все предеметы\n";
        cout << " 3. Посмотреть текущий предмет\n";
        cout << " 4. Удалить текущий предмет\n";
        cout << " 5. Удалить все предметы\n";
        cout << " 6. Поиск предмета по параметру\n";
        cout << " 7. Проверить есть ли предметы\n";
        cout << " 8. Редактировать предмет\n";
        cout << " 9. Отмена последнего действия\n";
        cout << "10. Отмена отмены последнего действия\n";
        cout << "11. Файл TXT\n";
        cout << "12. Файл BIN\n";
        cout << "13. Выход\n";
        choise = GetInt(1, 13);
        system("cls");
        switch (choise)
        {
        case 1:
        {
                cout << "Введите количество элементов:\n";
                int number;
            number = GetInt(1, 99);
            for (int i = 0; i < number; i++)
            {
                    cout << "Вводите элемент:\n";
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
                cout << "Содержимое кольца:\n";
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
                        cout << "Данный элемент содержится в кольце" << endl;
                }
                else
                {
                        cout << "Данный элемент не содержится в кольце или оно пустое" << endl;
                }
            system("pause");
        }
        break;
        case 7:
        {

            if (list.Empty())
            {
                    cout << "Кольцо пустое!" << endl;
            }
            else
            {
                    cout << "В кольце содержатся элементы!" << endl;
            }

            system("pause");
            system("cls");
        }
        break;
        case 8:
        {
                cout << "Человек с максимальным возрастом:\n";
                list.FindMax();
            system("pause");
            system("cls");
        }
        break;
        case 9:
        {
                cout << "Человек с минимальным возрастом:\n";
                list.FindMin();
            system("pause");
            system("cls");
        }
        break;
        case 10:break;
        default:
        {
                cout << "Введен неверный номер!!!\n";
                system("pause");
            system("cls");
        }
        }
        system("cls");
    } while (choise != 10);
}
