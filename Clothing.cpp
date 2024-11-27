#include "Clothing.h"

Clothing::Clothing() : Item()
{
    size = "";
    color = "";
    material = "";
}

Clothing::Clothing(string& name, string& category, int quantity, string& size, string& color, string& material) : Item(name, category, quantity), size(size), color(color), material(material) {}

Clothing::Clothing(Clothing& other) : Item(other) 
{
    this->size = other.size;
    this->color = other.color;
    this->material = other.material;
}

Clothing::~Clothing() {}

void Clothing::displayInfo() 
{
    Item::displayInfo();
   cout << "Размер: " << size << "\n"
        << "Цвет: " << color << "\n"
        << "Материал: " << material << "\n";
}

string Clothing::getSize()
{
    return size;
}

string Clothing::getColor()
{
    return color;
}

string Clothing::getMaterial()
{
    return material;
}

void Clothing::setSize(string& size) 
{
    this->size = size;
}

void Clothing::setColor(string& color) {
    this->color = color;
}

void Clothing::setMaterial(string& material) 
{
    this->material = material;
}

istream& operator>>(istream& in, Clothing& obj) 
{
    cout << "Введите название, категорию и количество одежды: ";
    in >> static_cast<Item&>(obj);
    cout << "Введите размер: ";
    in >> obj.size;
    cout << "Введите цвет: ";
    in >> obj.color;
    cout << "Введите материал: ";
    in >> obj.material;
    return in;
}

ostream& operator<<(ostream& out,const Clothing& obj) 
{
    out << left;
    out << setw(20) << static_cast<const Item&>(obj)
        << ", Размер: " << obj.size
        << ", Цвет: " << obj.color
        << ", Материал: " << obj.material;
    return out;
}