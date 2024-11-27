#pragma once
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Item
{
protected:
    string name;
    string category;
    int quantity;
public:
    Item();
    Item(Item& other);
    Item(string& name,string& category, int quantity);
    virtual ~Item();
    virtual void displayInfo();
    void setQuantity(int quantity);
    void setName(string name);
    void setCategory(string category);
    int getQuantity();
    string getName();
    string getCategory();
    friend istream& operator>>(istream& in, Item& obj);
    friend ostream& operator<<(ostream& out,const Item& obj);
};