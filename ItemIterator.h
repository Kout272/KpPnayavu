#pragma once
#include "Item.h"
#include "ItemCollection.h"

class ItemIterator {
private:
    ItemCollection& collection; // ������ �� ���������
    int currentIndex;           // ������� ������ ���������

public:
    ItemIterator(ItemCollection& collection);

    // ����� ��� ��������� �������� ��������
    Item* current() const;

    // ����� ��� �������� � ���������� ��������
    bool next();

    // ����� ��� ��������, ���� �� ��� ��������
    bool hasNext() const;

    // ����� ��� ������ ��������� �� ������
    void reset();
};