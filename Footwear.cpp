#include "Footwear.h"

Footwear::Footwear() : Clothing() 
{
    type = "";
}

Footwear::Footwear(string& name, string& category, int quantity,string& size, string& color, string& material, string& type) : Clothing(name, category, quantity, size, color, material), type(type) {}

Footwear::Footwear(Footwear& other) : Clothing(other) 
{
    this->type = other.type;
}

Footwear::~Footwear() {}

void Footwear::displayInfo()
{
    Clothing::displayInfo(); 
    cout << "��� �����: " << type << "\n";
}

string Footwear::getType()
{
    return type;
}

void Footwear::setType(string& type) 
{
    this->type = type;
}

istream& operator>>(istream& in, Footwear& obj) 
{
    cout << "������� ��������, ��������� � ���������� �����: ";
    in >> static_cast<Clothing&>(obj);
    cout << "������� ��� �����: ";
    in >> obj.type;
    return in;
}

ostream& operator<<(ostream& out, const Footwear& obj) 
{
    out << left;
    out << setw(20) << static_cast<const Clothing&>(obj) 
        << ", ��� �����: " << obj.type;
    return out;
}