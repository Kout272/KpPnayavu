#pragma once
#include"Reseter.h"
#include"Item.h"
#include "Interface.h"

//void Interface::start()
//{
//    cout << "Создайте человека для которого вы хотите вести учет дичных вещей\n";
//}
//Переделать функционал для всего этого
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
        cout << "12. Выход\n";
        choise = GetInt(1, 12);
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
                cout << "Содержимое кольца:\n";
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
                        cout << "Данный элемент содержится в кольце" << endl;
                }
                else
                {
                        cout << "Данный элемент не содержится в кольце или оно пустое" << endl;
                }
            system("pause");*/
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