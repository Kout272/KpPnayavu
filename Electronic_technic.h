#pragma once
#include "Technic.h"

class Electronic_technic : public Technic 
{
private:
    string connection_type; 
public:
    Electronic_technic();
    Electronic_technic(string& name, string& category, int quantity, string& brand, string& model, string& connection_type);
    Electronic_technic(Electronic_technic& other);
    ~Electronic_technic();
    void displayInfo() override;
    string getConnectionType();
    void setConnectionType(string& connection_type);
    friend istream& operator>>(istream& in, Electronic_technic& obj);
    friend ostream& operator<<(ostream& out,const Electronic_technic& obj);
};