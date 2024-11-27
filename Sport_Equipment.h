#pragma once
#include "item.h"

class Sport_Equipment : public Item 
{
private:
    string type_of_sport; 
    double weight;    
    string purpose;  

public:
    Sport_Equipment();
    Sport_Equipment(string& name, string& category, int quantity, string& type_of_sport, double weight, string& purpose);
    Sport_Equipment(Sport_Equipment& other);
    ~Sport_Equipment();
    void displayInfo() override;
    string getTypeOfSport();
    double getWeight();
    string getPurpose();
    void setTypeOfSport(string& type_of_sport);
    void setWeight(double weight);
    void setPurpose(string& purpose);
    friend istream& operator>>(istream& in, Sport_Equipment& obj);
    friend ostream& operator<<(ostream& out, const Sport_Equipment& obj);
};