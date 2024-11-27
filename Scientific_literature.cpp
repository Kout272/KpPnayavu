#include "Scientific_literature.h"

Scientific_literature::Scientific_literature() : Book()
{
    research_area = "";
    theme = "";
}

Scientific_literature::Scientific_literature(string& name, string& category, int quantity, string& author, int publication_year, int page_count, string& research_area, string& theme) : Book(name, category, quantity, author, publication_year, page_count), research_area(research_area), theme(theme) {}

Scientific_literature::Scientific_literature(Scientific_literature& other) : Book(other)
{
    this->research_area = other.research_area;
    this->theme = other.theme;
}

Scientific_literature::~Scientific_literature() {}

void Scientific_literature::displayInfo() 
{
    Book::displayInfo();
   cout << "Область исследования: " << research_area << "\n"
        << "Тематика: " << theme << "\n";
}

string Scientific_literature::getResearchArea() 
{
    return research_area;
}

string Scientific_literature::getTheme() 
{
    return theme;
}

void Scientific_literature::setResearchArea(string& research_area) 
{
    this->research_area = research_area;
}

void Scientific_literature::setTheme(string& theme) 
{
    this->theme = theme;
}

istream& operator>>(istream& in, Scientific_literature& obj) 
{
    in >> static_cast<Book&>(obj);
    cout << "Введите область исследования: ";
    in >> obj.research_area;
    cout << "Введите тематику: ";
    in >> obj.theme;
    return in;
}

ostream& operator<<(ostream& out, const Scientific_literature& obj) 
{
    out << left;
    out << setw(20) << static_cast<const Book&>(obj) 
        << ", Область исследования: " << obj.research_area
        << ", Тематика: " << obj.theme;
    return out;
}