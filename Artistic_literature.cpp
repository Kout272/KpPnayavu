#include "Artistic_literature.h"

Artistic_literature::Artistic_literature() : Book()
{
    genre = "";
    target_audience = "";
}

Artistic_literature::Artistic_literature(string& name, string& category, int quantity, string& author, int publication_year, int page_count, string& genre, string& target_audience) : Book(name, category, quantity, author, publication_year, page_count), genre(genre), target_audience(target_audience) {}

Artistic_literature::Artistic_literature(Artistic_literature& other) : Book(other) 
{
    this->genre = other.genre;
    this->target_audience = other.target_audience;
}

Artistic_literature::~Artistic_literature() {}

void Artistic_literature::displayInfo() 
{
    Book::displayInfo(); 
   cout << "Жанр: " << genre << "\n"
        << "Целевая аудитория: " << target_audience << "\n";
}

string Artistic_literature::getGenre() 
{
    return genre;
}

string Artistic_literature::getTargetAudience() 
{
    return target_audience;
}

void Artistic_literature::setGenre(string& genre)
{
    this->genre = genre;
}

void Artistic_literature::setTargetAudience(string& target_audience)
{
    this->target_audience = target_audience;
}

istream& operator>>(istream& in, Artistic_literature& obj) 
{
    in >> static_cast<Book&>(obj);
    cout << "Введите жанр: ";
    in >> obj.genre;
    cout << "Введите целевую аудиторию: ";
    in >> obj.target_audience;
    return in;
}

ostream& operator<<(ostream& out, const Artistic_literature& obj) 
{
    out << left;
    out << setw(20) << static_cast<const Book&>(obj) 
        << ", Жанр: " << obj.genre
        << ", Целевая аудитория: " << obj.target_audience;
    return out;
}