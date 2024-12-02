#include"Header.h"
#include<iostream>
#include"Interface.h"
int main()
{
	setlocale(LC_ALL, "ru");
	Ring<Item> a;
	Interface b;
	b.OperatingRing(a);
}