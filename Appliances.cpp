#include "Appliances.h"

Appliances::Appliances() : Technic() 
{
    power = 0;
    functions = "";
}

Appliances::Appliances(string& name, string& category, int quantity, string& brand, string& model, int power, string& functions) : Technic(name, category, quantity, brand, model), power(power), functions(functions) {}

Appliances::Appliances(Appliances& other) : Technic(other) 
{
    this->power = other.power;
    this->functions = other.functions;
}

Appliances::~Appliances() {}

void Appliances::displayInfo() 
{
    Technic::displayInfo(); 
   cout << "Мощность: " << power << " Вт\n"
        << "Функции: " << functions << "\n";

   cout << "Мощность: " << power << " Вт\n"
       << "Функции: " << functions << "\n";

   cout << "Мощность: " << power << " Вт\n"
       << "Функции: " << functions << "\n";
}

int Appliances::getPower() 
{
    return power;
}

string Appliances::getFunctions() 
{
    return functions;
}

void Appliances::setPower(int power)
{
    this->power = power;
}

void Appliances::setFunctions(string& functions) 
{
    this->functions = functions;
}

istream& operator>>(istream& in, Appliances& obj) 
{
    in >> static_cast<Technic&>(obj);
    cout << "Введите мощность (Вт): ";
    in >> obj.power;
    cout << "Введите функции: ";
    in >> obj.functions;
    return in;
}

ostream& operator<<(ostream& out, const Appliances& obj) 
{
    out << left;
    out << setw(20) << static_cast<const Technic&>(obj)
        << ", Мощность: " << obj.power << " Вт"
        << ", Функции: " << obj.functions;
    return out;
}

ostream& operator<<(ostream& out, const Appliances& obj)
{
    out << left;
    out << setw(20) << static_cast<const Technic&>(obj)
        << ", Мощность: " << obj.power << " Вт"
        << ", Функции: " << obj.functions;
    return out;
}