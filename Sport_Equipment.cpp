#include "Sport_Equipment.h"

Sport_Equipment::Sport_Equipment() : Item()
{
    type_of_sport = "";
    weight = 0.0;
    purpose = "";
}

Sport_Equipment::Sport_Equipment(string& name, string& category, int quantity, string& type_of_sport, double weight, string& purpose) : Item(name, category, quantity), type_of_sport(type_of_sport), weight(weight), purpose(purpose) {}

Sport_Equipment::Sport_Equipment(Sport_Equipment& other) : Item(other) 
{
    this->type_of_sport = other.type_of_sport;
    this->weight = other.weight;
    this->purpose = other.purpose;
}

Sport_Equipment::~Sport_Equipment() {}

void Sport_Equipment::displayInfo() 
{
    Item::displayInfo(); 
   cout << "��� ������: " << type_of_sport << "\n"
        << "���: " << weight << " ��\n"
        << "��������������: " << purpose << "\n";
}

string Sport_Equipment::getTypeOfSport() 
{
    return type_of_sport;
}

double Sport_Equipment::getWeight() 
{
    return weight;
}

string Sport_Equipment::getPurpose() 
{
    return purpose;
}

void Sport_Equipment::setTypeOfSport(string& type_of_sport) 
{
    this->type_of_sport = type_of_sport;
}

void Sport_Equipment::setWeight(double weight) 
{
    this->weight = weight;
}

void Sport_Equipment::setPurpose(string& purpose)
{
    this->purpose = purpose;
}

istream& operator>>(istream& in, Sport_Equipment& obj) 
{
    cout << "������� ��������, ��������� � ���������� ����������� ������������: ";
    in >> static_cast<Item&>(obj);
    cout << "������� ��� ������: ";
    in >> obj.type_of_sport;
    cout << "������� ��� (� ��): ";
    in >> obj.weight;
    cout << "������� ��������������: ";
    in >> obj.purpose;
    return in;
}

ostream& operator<<(ostream& out, const Sport_Equipment& obj)
{
    out << left;
    out << setw(20) << static_cast<const Item&>(obj)
        << ", ��� ������: " << obj.type_of_sport
        << ", ���: " << obj.weight << " ��"
        << ", ��������������: " << obj.purpose;
    return out;
}