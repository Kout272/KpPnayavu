#pragma once
#include <iostream>
#include "Item.h"
#include "Book.h"
#include "Clothing.h"
#include "Technic.h"
#include "Sport_Equipment.h"
#include "Artistic_literature.h"
#include "Scientific_literature.h"
#include "Electronic_Technic.h"
#include "Appliances.h"
#include "ActionHistory.h"

class ItemCollection {
private:
    Item** items;          // Указатель на массив указателей на объекты Item
    int capacity;          // Вместимость кольцевого буфера
    int size;              // Текущий размер коллекции
    int head;              // Индекс первого элемента
    int tail;              // Индекс последнего элемента

    // Метод для увеличения размера кольцевого буфера
    void resize();

public:
    // Конструктор
    ItemCollection(int capacity = 10);

    // Деструктор
    ~ItemCollection();

    // Метод для добавления объекта
    void addItem();

    // Метод для удаления объекта по идентификатору
    void removeItem();

    // Метод для редактирования объекта по идентификатору
    void editItem();

    // Метод для просмотра всех объектов
    void viewItems() const;

    // Метод для отображения меню категорий
    void displayCategories() const;

    // Метод для отображения подкатегорий в зависимости от выбранной категории
    void displaySubcategories(int category) const;

    // Геттеры для доступа к полям
    int getSize() const { return size; }
    int getCapacity() const { return capacity; }
    int getHead() const { return head; }
    Item* getItemAt(int index) const {
        return items[(head + index) % capacity];
    }

    void undoLastAction();
};