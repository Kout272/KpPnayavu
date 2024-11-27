#include "item.h"

Item::Item()
{
    name = "";
    category = "";
    quantity = 0;
}

Item::Item(Item& other)
{
    this->name = other.name;
    this->category = other.category;
    this->category = other.category;
}

Item::Item(string& name, string& category, int quantity)
{
    this->name = name;
    this->category = category;
    this->quantity = quantity;
}

Item::~Item() {}

void Item::displayInfo() 
{
   cout << "Название: " << name << "\n"
        << "Категория: " << category << "\n"
        << "Количество: " << quantity << "\n";
}

void Item::setQuantity(int quantity)
{
    this->quantity = quantity;
}

void Item::setName(string name)
{
    this->name = name;
}

void Item::setCategory(string category)
{
    this->category = category;
}

int Item::getQuantity()
{
    return quantity;
}

string Item::getName()
{
    return name;
}

string Item::getCategory()
{
    return category;
}

istream& operator>>(istream& in, Item& obj)
{
    cout << "Введите название, категорию и количество предмета: ";
    in >> obj.name >> obj.category >> obj.quantity;
    return in;
}

ostream& operator<<(ostream& out, const Item& obj)
{
    out << left;
    out << setw(20) << obj.name
        << setw(20) << obj.category
        << setw(20) << obj.quantity;
    return out;
}