#pragma once
#include "Book.h"

class Scientific_literature : public Book 
{
private:
    string research_area; // Область исследования
    string theme;        // Тематика научной литературы

public:
    Scientific_literature();
    Scientific_literature(string& name, string& category, int quantity, string& author, int publication_year, int page_count, string& research_area, string& theme);
    Scientific_literature(Scientific_literature& other);
    ~Scientific_literature();
    void displayInfo() override;
    string getResearchArea() ;
    string getTheme();
    void setResearchArea(string& research_area);
    void setTheme(string& theme);
    friend istream& operator>>(istream& in, Scientific_literature& obj);
    friend ostream& operator<<(ostream& out, const Scientific_literature& obj);
};