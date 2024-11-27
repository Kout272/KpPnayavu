#include "ItemIterator.h"

// Конструктор
ItemIterator::ItemIterator(ItemCollection& collection)
    : collection(collection), currentIndex(0) {}

// Метод для получения текущего элемента
Item* ItemIterator::current() const {
    if (currentIndex < collection.getSize()) {
        return collection.getItemAt(currentIndex);
    }
    return nullptr; // Если индекс выходит за пределы
}

// Метод для перехода к следующему элементу
bool ItemIterator::next() {
    if (hasNext()) {
        currentIndex++;
        return true;
    }
    return false;
}

// Метод для проверки, есть ли еще элементы
bool ItemIterator::hasNext() const {
    return currentIndex < collection.getSize();
}

// Метод для сброса итератора на начало
void ItemIterator::reset() {
    currentIndex = 0;
}