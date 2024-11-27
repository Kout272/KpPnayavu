#pragma once
#include "Technic.h"

class Appliances : public Technic 
{
private:
    int power;     
    string functions;     

public:
    Appliances();
    Appliances(string& name, string& category, int quantity, string& brand, string& model, int power, string& functions);
    Appliances(Appliances& other);
    ~Appliances();
    void displayInfo() override;
    int getPower();
    string getFunctions();
    void setPower(int power);
    void setFunctions(string& functions);
    friend istream& operator>>(istream& in, Appliances& obj);
    friend ostream& operator<<(ostream& out, const Appliances& obj);
};