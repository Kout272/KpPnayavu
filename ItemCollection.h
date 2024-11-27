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
    Item** items;          // ��������� �� ������ ���������� �� ������� Item
    int capacity;          // ����������� ���������� ������
    int size;              // ������� ������ ���������
    int head;              // ������ ������� ��������
    int tail;              // ������ ���������� ��������

    // ����� ��� ���������� ������� ���������� ������
    void resize();

public:
    // �����������
    ItemCollection(int capacity = 10);

    // ����������
    ~ItemCollection();

    // ����� ��� ���������� �������
    void addItem();

    // ����� ��� �������� ������� �� ��������������
    void removeItem();

    // ����� ��� �������������� ������� �� ��������������
    void editItem();

    // ����� ��� ��������� ���� ��������
    void viewItems() const;

    // ����� ��� ����������� ���� ���������
    void displayCategories() const;

    // ����� ��� ����������� ������������ � ����������� �� ��������� ���������
    void displaySubcategories(int category) const;

    // ������� ��� ������� � �����
    int getSize() const { return size; }
    int getCapacity() const { return capacity; }
    int getHead() const { return head; }
    Item* getItemAt(int index) const {
        return items[(head + index) % capacity];
    }

    void undoLastAction();
};