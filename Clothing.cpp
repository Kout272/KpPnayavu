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
   cout << "������: " << size << "\n"
        << "����: " << color << "\n"
        << "��������: " << material << "\n";
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
    cout << "������� ��������, ��������� � ���������� ������: ";
    in >> static_cast<Item&>(obj);
    cout << "������� ������: ";
    in >> obj.size;
    cout << "������� ����: ";
    in >> obj.color;
    cout << "������� ��������: ";
    in >> obj.material;
    return in;
}

ostream& operator<<(ostream& out,const Clothing& obj) 
{
    out << left;
    out << setw(20) << static_cast<const Item&>(obj)
        << ", ������: " << obj.size
        << ", ����: " << obj.color
        << ", ��������: " << obj.material;
    return out;
}