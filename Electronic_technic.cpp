#include "Electronic_technic.h"

Electronic_technic::Electronic_technic() : Technic()
{
    connection_type = "";
}

Electronic_technic::Electronic_technic(string& name, string& category, int quantity, string& brand, string& model, string& connection_type) : Technic(name, category, quantity, brand, model), connection_type(connection_type) {}

Electronic_technic::Electronic_technic(Electronic_technic& other) : Technic(other) 
{
    this->connection_type = other.connection_type;
}

Electronic_technic::~Electronic_technic() {}

void Electronic_technic::displayInfo() 
{
    Technic::displayInfo();
    cout << "Тип подключения: " << connection_type << "\n";
}

string Electronic_technic::getConnectionType() 
{
    return connection_type;
}

void Electronic_technic::setConnectionType(string& connection_type) 
{
    this->connection_type = connection_type;
}

istream& operator>>(istream& in, Electronic_technic& obj) 
{
    in >> static_cast<Technic&>(obj);
    cout << "Введите тип подключения: ";
    in >> obj.connection_type;
    return in;
}

ostream& operator<<(ostream& out, const Electronic_technic& obj) 
{
    out << left;
    out << setw(20) << static_cast<const Technic&>(obj)
        << ", Тип подключения: " << obj.connection_type;
    return out;
}