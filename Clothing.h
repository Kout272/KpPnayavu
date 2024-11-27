#pragma once
#include "item.h"

class Clothing : public Item 
{
private:
    string size;    
    string color;    
    string material; 
public:
    Clothing();
    Clothing(string& name, string& category, int quantity, string& size, string& color, string& material);
    Clothing(Clothing& other);
    ~Clothing();
    void displayInfo() override;
    string getSize();
    string getColor();
    string getMaterial();
    void setSize(string& size);
    void setColor(string& color);
    void setMaterial(string& material);
    friend istream& operator>>(istream& in, Clothing& obj);
    friend ostream& operator<<(ostream& out, const Clothing& obj);
};