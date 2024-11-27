#pragma once
#include "item.h"

class Technic : public Item 
{
private:
    string brand;
    string model; 
public:
    Technic();
    Technic(string& name, string& category, int quantity, string& brand, string& model);
    Technic(Technic& other);
     ~Technic();
    void displayInfo() override;
    string getBrand() ;
    string getModel();
    void setBrand(string& brand);
    void setModel(string& model);
    friend istream& operator>>(istream& in, Technic& obj);
    friend ostream& operator<<(ostream& out, const Technic& obj);
};