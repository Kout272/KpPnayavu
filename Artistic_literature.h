#pragma once
#include "Book.h"

class Artistic_literature : public Book 
{
private:
    string genre;          // Жанр художественной литературы
    string target_audience; // Целевая аудитория
public:
    Artistic_literature();
    Artistic_literature(string& name, string& category, int quantity, string& author, int publication_year, int page_count, string& genre, string& target_audience);
    Artistic_literature(Artistic_literature& other);
    ~Artistic_literature();
    void displayInfo() override;
    string getGenre();
    string getTargetAudience();
    void setGenre(string& genre);
    void setTargetAudience(string& target_audience);
    friend istream& operator>>(istream& in, Artistic_literature& obj);
    friend ostream& operator<<(ostream& out, const Artistic_literature& obj);
};