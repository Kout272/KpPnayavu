#include "ItemIterator.h"

// �����������
ItemIterator::ItemIterator(ItemCollection& collection)
    : collection(collection), currentIndex(0) {}

// ����� ��� ��������� �������� ��������
Item* ItemIterator::current() const {
    if (currentIndex < collection.getSize()) {
        return collection.getItemAt(currentIndex);
    }
    return nullptr; // ���� ������ ������� �� �������
}

// ����� ��� �������� � ���������� ��������
bool ItemIterator::next() {
    if (hasNext()) {
        currentIndex++;
        return true;
    }
    return false;
}

// ����� ��� ��������, ���� �� ��� ��������
bool ItemIterator::hasNext() const {
    return currentIndex < collection.getSize();
}

// ����� ��� ������ ��������� �� ������
void ItemIterator::reset() {
    currentIndex = 0;
}