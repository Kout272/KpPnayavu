#include "ItemCollection.h"

ItemCollection::ItemCollection(int capacity) : capacity(capacity), size(0), head(0), tail(0) {
    items = new Item * [capacity];
}

ItemCollection::~ItemCollection() {
    for (int i = 0; i < size; ++i) {
        delete items[(head + i) % capacity]; // Освобождаем память для каждого объекта
    }
    delete[] items; // Освобождаем сам массив
}

// Метод для увеличения размера кольцевого буфера
void ItemCollection::resize() {
    int newCapacity = capacity * 2;
    Item** newItems = new Item * [newCapacity];

    for (int i = 0; i < size; ++i) {
        newItems[i] = items[(head + i) % capacity];
    }

    delete[] items; // Освобождаем старый массив
    items = newItems;
    head = 0;
    tail = size;
    capacity = newCapacity;
}

void ItemCollection::displayCategories() const {
    std::cout << "Выберите категорию:\n";
    std::cout << "1. Книги\n2. Одежда\n3. Техника\n4. Спортивное оборудование\n";
}

void ItemCollection::displaySubcategories(int category) const {
    switch (category) {
    case 1: // Книги
        std::cout << "Подкатегории книг:\n";
        std::cout << "1. Художественная литература\n2. Научная литература\n";
        break;
    case 2: // Одежда
        std::cout << "Подкатегории одежды:\n";
        std::cout << "1. Обувь\n";
        break;
    case 3: // Техника
        std::cout << "Подкатегории техники:\n";
        std::cout << "1. Электронная техника\n2. Бытовая техника\n";
        break;
    default:
        std::cout << "Некорректная категория.\n";
        break;
    }
}

// Метод для добавления объекта
void ItemCollection::addItem() {
    displayCategories();
    int category;
    std::cin >> category;

    displaySubcategories(category);
    int subcategory;
    std::cin >> subcategory;

    Item* newItem = nullptr;

    switch (category) {
    case 1: // Книги
        if (subcategory == 1) {
            newItem = new Artistic_literature(); // Создаем художественную литературу
        }
        else if (subcategory == 2) {
            newItem = new Scientific_literature(); // Создаем научную литературу
        }
        break;
    case 2: // Одежда
        if (subcategory == 1) {
            newItem = new Clothing(); // Создаем одежду (обувь)
        }
        break;
    case 3: // Техника
        if (subcategory == 1) {
            newItem = new Electronic_technic(); // Создаем электронную технику
        }
        else if (subcategory == 2) {
            newItem = new Appliances(); // Создаем приборы
        }
        break;
    case 4: // Спортивное оборудование
        newItem = new Sport_Equipment(); // Создаем спортивное оборудование
        break;
    default:
        std::cout << "Некорректная категория или подкатегория.\n";
        return;
    }

    if (size == capacity) {
        resize(); // Увеличиваем размер, если нужно
    }

    items[tail] = newItem;
    tail = (tail + 1) % capacity; // Увеличиваем индекс хвоста
    size++;
}

// Метод для удаления объекта по идентификатору
void ItemCollection::removeItem() {
    displayCategories();
    int category;
    std::cin >> category;

    cout << "Список предметов:\n";
    int count = 0;
    for (int i = 0; i < size; ++i) {
        int index = (head + i) % capacity;
        if ((category == 1 && dynamic_cast<Book*>(items[index])) ||
            (category == 2 && dynamic_cast<Clothing*>(items[index])) ||
            (category == 3 && dynamic_cast<Technic*>(items[index])) ||
            (category == 4 && dynamic_cast<Sport_Equipment*>(items[index]))) {
            std::cout << count << ": " << *items[index] << "\n"; // Предполагаем, что оператор << перегружен
            count++;
        }
    }

    if (count == 0) {
        cout << "Нет предметов в выбранной категории.\n";
        return;
    }

    cout << "Введите номер предмета для удаления: ";
    int indexToRemove;
    cin >> indexToRemove;

    if (indexToRemove < 0 || indexToRemove >= count) {
        std::cout << "Некорректный индекс.\n";
        return;
    }

    // Удаляем предмет
    int actualIndex = (head + indexToRemove) % capacity;
    delete items[actualIndex]; // Освобождаем память
    // Сдвигаем элементы
    for (int j = indexToRemove; j < size - 1; ++j) {
        items[(head + j) % capacity] = items[(head + j + 1) % capacity];
    }

    tail = (tail - 1 + capacity) % capacity; // Корректируем индексы
    size--;
    cout << "Предмет удален.\n";
}

// Метод для редактирования объекта по идентификатору
void ItemCollection::editItem() {
    displayCategories();
    int category;
    cin >> category;

    cout << "Список предметов:\n";
    int count = 0;
    for (int i = 0; i < size; ++i) {
        int index = (head + i) % capacity;
        if ((category == 1 && dynamic_cast<Book*>(items[index])) ||
            (category == 2 && dynamic_cast<Clothing*>(items[index])) ||
            (category == 3 && dynamic_cast<Technic*>(items[index])) ||
            (category == 4 && dynamic_cast<Sport_Equipment*>(items[index]))) {
            std::cout << count << ": " << *items[index] << "\n"; // Предполагаем, что оператор << перегружен
            count++;
        }
    }

    if (count == 0) {
        std::cout << "Нет предметов в выбранной категории.\n";
        return;
    }

    cout << "Введите номер предмета для редактирования: ";
    int indexToEdit;
    cin >> indexToEdit;

    if (indexToEdit < 0 || indexToEdit >= count) {
        cout << "Некорректный индекс.\n";
        return;
    }

    // Редактируем предмет
    int actualIndex = (head + indexToEdit) % capacity;
    cin >> *items[actualIndex]; // Предполагаем, что оператор >> перегружен
    cout << "Предмет отредактирован.\n";
}

// Метод для просмотра всех объектов
void ItemCollection::viewItems() const {
    displayCategories();
    int category;
    std::cin >> category;

    cout << "Список предметов:\n";
    for (int i = 0; i < size; ++i) {
        int index = (head + i) % capacity;
        if ((category == 1 && dynamic_cast<Book*>(items[index])) ||
            (category == 2 && dynamic_cast<Clothing*>(items[index])) ||
            (category == 3 && dynamic_cast<Technic*>(items[index])) ||
            (category == 4 && dynamic_cast<Sport_Equipment*>(items[index]))) {
            cout << *items[index] << "\n"; // Предполагаем, что оператор << перегружен
        }
    }
}