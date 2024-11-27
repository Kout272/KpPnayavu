#include "Book.h"

Book::Book() : Item()
{
    author = "";
    publication_year = 0;
    page_count = 0;
}

Book::Book(string& name, string& category, int quantity, string& author, int publication_year, int page_count) : Item(name, category, quantity), author(author), publication_year(publication_year), page_count(page_count) {}

Book::Book(Book& other) : Item(other) 
{
    this->author = other.author;
    this->publication_year = other.publication_year;
    this->page_count = other.page_count;
}

Book::~Book() {}

void Book::displayInfo()
{
    Item::displayInfo(); 
   cout << "Автор: " << author << "\n"
        << "Год публикации: " << publication_year << "\n"
        << "Количество страниц: " << page_count << "\n";
}

string Book::getAuthor() 
{
    return author;
}

int Book::getPublicationYear() 
{
    return publication_year;
}

int Book::getPageCount() 
{
    return page_count;
}

void Book::setAuthor(string& author) 
{
    this->author = author;
}

void Book::setPublicationYear(int year) 
{
    this->publication_year = publication_year;
}

void Book::setPageCount(int count)
{
    this->page_count = page_count;
}

istream& operator>>(istream& in, Book& obj) 
{
    cout << "Введите название, категорию и количество книг: ";
    in >> static_cast<Item&>(obj); 
    cout << "Введите автора: ";
    in >> obj.author;
    cout << "Введите год публикации: ";
    in >> obj.publication_year;
    cout << "Введите количество страниц: ";
    in >> obj.page_count;
    return in;
}

ostream& operator<<(ostream& out, const Book& obj)
{
    out << left;
    out << setw(20) << static_cast<const Item&>(obj) 
        << ", Автор: " << obj.author
        << ", Год публикации: " << obj.publication_year
        << ", Количество страниц: " << obj.page_count;
    return out;
}