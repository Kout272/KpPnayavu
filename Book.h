#pragma once
#include "item.h"

class Book : public Item 
{
private:
    string author;    
    int publication_year;  
    int page_count;       
public:
    Book();
    Book(string& name, string& category, int quantity, string& author, int publication_year, int page_count);
    Book(Book& other);
    ~Book();
    void displayInfo() override;
    string getAuthor();
    int getPublicationYear() ;
    int getPageCount();
    void setAuthor(string& author);
    void setPublicationYear(int publication_year);
    void setPageCount(int page_count);
    friend istream& operator>>(istream& in, Book& obj);
    friend ostream& operator<<(ostream& out,const Book& obj);
};