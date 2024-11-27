#pragma once
#include "Clothing.h"

class Footwear : public Clothing 
{
private:
    string type;

public:
    Footwear();
    Footwear(string& name, string& category, int quantity, string& size, string& color, string& material, string& type);
    Footwear(Footwear& other);
    ~Footwear();
    void displayInfo() override;
    string getType();
    void setType(string& type);
    friend istream& operator>>(istream& in, Footwear& obj);
    friend ostream& operator<<(ostream& out, const Footwear& obj);
};