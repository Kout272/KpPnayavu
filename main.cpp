#include <iostream>
#include <locale.h>
#include "ItemCollection.h"
#include "ItemIterator.h"

int main()
{
    setlocale(LC_ALL, "rus");

    ItemCollection collection; // ������� ��������� ������ ItemCollection

    int choice;
    do {
        std::cout << "����:\n";
        std::cout << "1. �������� �������\n";
        std::cout << "2. ������� �������\n";
        std::cout << "3. ������������� �������\n";
        std::cout << "4. ����������� ��������\n";
        std::cout << "5. �������� ��������� ��������\n";
        std::cout << "6. �����\n";
        std::cout << "�������� ��������: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            collection.addItem(); // ���������� ��������
            break;
        case 2:
            collection.removeItem(); // �������� ��������
            break;
        case 3:
            collection.editItem(); // �������������� ��������
            break;
        case 4:
            // ���������� �������� ��� ��������� ���������
        {
            ItemIterator iterator(collection);
            std::cout << "�������� � ���������:\n";
            while (iterator.hasNext()) {
                Item* currentItem = iterator.current();
                if (currentItem) {
                    std::cout << *currentItem << "\n"; // ������������, ��� �������� << ����������
                }
                iterator.next(); // ������� � ���������� ��������
            }
        }
        break;
        case 5:
            collection.undoLastAction(); 
            break;
        case 6:
            std::cout << "����� �� ���������.\n";
            break;
        default:
            std::cout << "������������ �����, ���������� �����.\n";
            break;
        }
    } while (choice != 6);

    return 0;
}