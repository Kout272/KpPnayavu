#include "Human.h"

Human::Human()
{
    Name = "";
    Surname = "";
}

Human::Human(Human& other)
{
    this->Name = other.Name;
    this->Surname = other.Surname;
}

Human::Human(string& Name, string& Surname)
{
    this->Name = Name;
    this->Surname = Surname;
}

Human::~Human() {}

void Human::displayInfo()
{
    cout << "Имя: " << Name << "\n"
        << "Фамилия: " << Surname << "\n";
}

void Human::setNAME(string Name)
{
    this->Name = Name;
}

void Human::setSURNAME(string Surname)
{
    this->Surname = Surname;
}

string Human::getNAME()
{
    return Name;
}

string Human::getSURNAME()
{
    return Surname;
}

istream& operator>>(istream& in, Human& obj)
{
    cout << "Введите имя и фамилию человека: ";
    in >> obj.Name >> obj.Surname;
    return in;
}

ostream& operator<<(ostream& out, const Human& obj)
{
    out << left;
    out << setw(20) << obj.Name
        << setw(20) << obj.Surname;
    return out;
}