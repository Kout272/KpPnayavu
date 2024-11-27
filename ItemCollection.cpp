#include "ItemCollection.h"

ItemCollection::ItemCollection(int capacity) : capacity(capacity), size(0), head(0), tail(0) {
    items = new Item * [capacity];
}

ItemCollection::~ItemCollection() {
    for (int i = 0; i < size; ++i) {
        delete items[(head + i) % capacity]; // ����������� ������ ��� ������� �������
    }
    delete[] items; // ����������� ��� ������
}

// ����� ��� ���������� ������� ���������� ������
void ItemCollection::resize() {
    int newCapacity = capacity * 2;
    Item** newItems = new Item * [newCapacity];

    for (int i = 0; i < size; ++i) {
        newItems[i] = items[(head + i) % capacity];
    }

    delete[] items; // ����������� ������ ������
    items = newItems;
    head = 0;
    tail = size;
    capacity = newCapacity;
}

void ItemCollection::displayCategories() const {
    std::cout << "�������� ���������:\n";
    std::cout << "1. �����\n2. ������\n3. �������\n4. ���������� ������������\n";
}

void ItemCollection::displaySubcategories(int category) const {
    switch (category) {
    case 1: // �����
        std::cout << "������������ ����:\n";
        std::cout << "1. �������������� ����������\n2. ������� ����������\n";
        break;
    case 2: // ������
        std::cout << "������������ ������:\n";
        std::cout << "1. �����\n";
        break;
    case 3: // �������
        std::cout << "������������ �������:\n";
        std::cout << "1. ����������� �������\n2. ������� �������\n";
        break;
    default:
        std::cout << "������������ ���������.\n";
        break;
    }
}

// ����� ��� ���������� �������
void ItemCollection::addItem() {
    displayCategories();
    int category;
    std::cin >> category;

    displaySubcategories(category);
    int subcategory;
    std::cin >> subcategory;

    Item* newItem = nullptr;

    switch (category) {
    case 1: // �����
        if (subcategory == 1) {
            newItem = new Artistic_literature(); // ������� �������������� ����������
        }
        else if (subcategory == 2) {
            newItem = new Scientific_literature(); // ������� ������� ����������
        }
        break;
    case 2: // ������
        if (subcategory == 1) {
            newItem = new Clothing(); // ������� ������ (�����)
        }
        break;
    case 3: // �������
        if (subcategory == 1) {
            newItem = new Electronic_technic(); // ������� ����������� �������
        }
        else if (subcategory == 2) {
            newItem = new Appliances(); // ������� �������
        }
        break;
    case 4: // ���������� ������������
        newItem = new Sport_Equipment(); // ������� ���������� ������������
        break;
    default:
        std::cout << "������������ ��������� ��� ������������.\n";
        return;
    }

    if (size == capacity) {
        resize(); // ����������� ������, ���� �����
    }

    items[tail] = newItem;
    tail = (tail + 1) % capacity; // ����������� ������ ������
    size++;
}

// ����� ��� �������� ������� �� ��������������
void ItemCollection::removeItem() {
    displayCategories();
    int category;
    std::cin >> category;

    cout << "������ ���������:\n";
    int count = 0;
    for (int i = 0; i < size; ++i) {
        int index = (head + i) % capacity;
        if ((category == 1 && dynamic_cast<Book*>(items[index])) ||
            (category == 2 && dynamic_cast<Clothing*>(items[index])) ||
            (category == 3 && dynamic_cast<Technic*>(items[index])) ||
            (category == 4 && dynamic_cast<Sport_Equipment*>(items[index]))) {
            std::cout << count << ": " << *items[index] << "\n"; // ������������, ��� �������� << ����������
            count++;
        }
    }

    if (count == 0) {
        cout << "��� ��������� � ��������� ���������.\n";
        return;
    }

    cout << "������� ����� �������� ��� ��������: ";
    int indexToRemove;
    cin >> indexToRemove;

    if (indexToRemove < 0 || indexToRemove >= count) {
        std::cout << "������������ ������.\n";
        return;
    }

    // ������� �������
    int actualIndex = (head + indexToRemove) % capacity;
    delete items[actualIndex]; // ����������� ������
    // �������� ��������
    for (int j = indexToRemove; j < size - 1; ++j) {
        items[(head + j) % capacity] = items[(head + j + 1) % capacity];
    }

    tail = (tail - 1 + capacity) % capacity; // ������������ �������
    size--;
    cout << "������� ������.\n";
}

// ����� ��� �������������� ������� �� ��������������
void ItemCollection::editItem() {
    displayCategories();
    int category;
    cin >> category;

    cout << "������ ���������:\n";
    int count = 0;
    for (int i = 0; i < size; ++i) {
        int index = (head + i) % capacity;
        if ((category == 1 && dynamic_cast<Book*>(items[index])) ||
            (category == 2 && dynamic_cast<Clothing*>(items[index])) ||
            (category == 3 && dynamic_cast<Technic*>(items[index])) ||
            (category == 4 && dynamic_cast<Sport_Equipment*>(items[index]))) {
            std::cout << count << ": " << *items[index] << "\n"; // ������������, ��� �������� << ����������
            count++;
        }
    }

    if (count == 0) {
        std::cout << "��� ��������� � ��������� ���������.\n";
        return;
    }

    cout << "������� ����� �������� ��� ��������������: ";
    int indexToEdit;
    cin >> indexToEdit;

    if (indexToEdit < 0 || indexToEdit >= count) {
        cout << "������������ ������.\n";
        return;
    }

    // ����������� �������
    int actualIndex = (head + indexToEdit) % capacity;
    cin >> *items[actualIndex]; // ������������, ��� �������� >> ����������
    cout << "������� ��������������.\n";
}

// ����� ��� ��������� ���� ��������
void ItemCollection::viewItems() const {
    displayCategories();
    int category;
    std::cin >> category;

    cout << "������ ���������:\n";
    for (int i = 0; i < size; ++i) {
        int index = (head + i) % capacity;
        if ((category == 1 && dynamic_cast<Book*>(items[index])) ||
            (category == 2 && dynamic_cast<Clothing*>(items[index])) ||
            (category == 3 && dynamic_cast<Technic*>(items[index])) ||
            (category == 4 && dynamic_cast<Sport_Equipment*>(items[index]))) {
            cout << *items[index] << "\n"; // ������������, ��� �������� << ����������
        }
    }
}