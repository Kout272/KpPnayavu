#include <iostream>
#include <locale.h>
#include "ItemCollection.h"
#include "ItemIterator.h"

int main()
{
    setlocale(LC_ALL, "rus");

    ItemCollection collection; // Создаем экземпляр класса ItemCollection

    int choice;
    do {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить предмет\n";
        std::cout << "2. Удалить предмет\n";
        std::cout << "3. Редактировать предмет\n";
        std::cout << "4. Просмотреть предметы\n";
        std::cout << "5. Отменить последнее действие\n";
        std::cout << "6. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            collection.addItem(); // Добавление предмета
            break;
        case 2:
            collection.removeItem(); // Удаление предмета
            break;
        case 3:
            collection.editItem(); // Редактирование предмета
            break;
        case 4:
            // Используем итератор для просмотра предметов
        {
            ItemIterator iterator(collection);
            std::cout << "Предметы в коллекции:\n";
            while (iterator.hasNext()) {
                Item* currentItem = iterator.current();
                if (currentItem) {
                    std::cout << *currentItem << "\n"; // Предполагаем, что оператор << перегружен
                }
                iterator.next(); // Переход к следующему элементу
            }
        }
        break;
        case 5:
            collection.undoLastAction(); 
            break;
        case 6:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Некорректный выбор, попробуйте снова.\n";
            break;
        }
    } while (choice != 6);

    return 0;
}