#pragma once
#include "Item.h"
#include "ItemCollection.h"

class ItemIterator {
private:
    ItemCollection& collection; // Ссылка на коллекцию
    int currentIndex;           // Текущий индекс итератора

public:
    ItemIterator(ItemCollection& collection);

    // Метод для получения текущего элемента
    Item* current() const;

    // Метод для перехода к следующему элементу
    bool next();

    // Метод для проверки, есть ли еще элементы
    bool hasNext() const;

    // Метод для сброса итератора на начало
    void reset();
};