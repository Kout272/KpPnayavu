#include "Technic.h"

Technic::Technic() : Item()
{
    brand = "";
    model = "";
}

Technic::Technic(string& name, string& category, int quantity, string& brand, string& model) : Item(name, category, quantity), brand(brand), model(model) {}

Technic::Technic(Technic& other) : Item(other) 
{
    this->brand = other.brand;
    this->model = other.model;
}

Technic::~Technic() {}

void Technic::displayInfo() 
{
    Item::displayInfo(); 
   cout << "�����: " << brand << "\n"
        << "������: " << model << "\n";
}

string Technic::getBrand() 
{
    return brand;
}

string Technic::getModel() 
{
    return model;
}

void Technic::setBrand(string& brand) 
{
    this->brand = brand;
}

void Technic::setModel(string& model)
{
    this->model = model;
}

istream& operator>>(istream& in, Technic& obj) 
{
    cout << "������� ��������, ��������� � ���������� �������: ";
    in >> static_cast<Item&>(obj);
    cout << "������� �����: ";
    in >> obj.brand;
    cout << "������� ������: ";
    in >> obj.model;
    return in;
}

ostream& operator<<(ostream& out, const Technic& obj) 
{
    out << left;
    out << setw(20) << static_cast<const Item&>(obj)
        << ", �����: " << obj.brand
        << ", ������: " << obj.model;
    return out;
}