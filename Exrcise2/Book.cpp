#include "Book.h"

#include<iostream>
#include<string>
using namespace std;

void Book::input()
{
	string _dummy = "";
	double _price = 0.0;

	cout << "ENTER: Book ID: ";
	getline(cin, _dummy);
	cin.ignore(0);
	this->id = _dummy;

	cout << "ENTER: Book Name: ";
	getline(cin, _dummy);
	cin.ignore(0);
	this->name = _dummy;

	cout << "ENTER: Book Author: ";
	getline(cin, _dummy);
	cin.ignore(0);
	this->author = _dummy;

	cout << "ENTER: Book Publisher: ";
	getline(cin, _dummy);
	cin.ignore(0);
	this->publisher = _dummy;

	cout << "ENTER: Book Price: ";
	cin >> _price;
	cin.ignore();
	this->price = _price;
}

void Book::display()
{
	cout << "+ Book ID: " << this->id << endl;
	cout << "+ Book Name: " << this->name << endl;
	cout << "+ Book Author: " << this->author << endl;
	cout << "+ Book Publisher: " << this->publisher << endl;
	cout << "+ Book Price: " << this->price << endl;
}

Book::Book()
{
	this->author = this->id = this->name = this->publisher = "";
	this->price = 0.0;
}

Book::Book(string _id):Book()
{
	this->id = _id;
}

Book::Book(string _id, string _name):Book(_id)
{
	this->name = _name;
}

Book::Book(string _id, string _name, string _author):Book(_id, _name)
{
	this->author = _author;
}

Book::Book(string _id, string _name, string _author, string _publisher):Book(_id, _name, _author)
{
	this->publisher = _publisher;
}

Book::Book(string _id, string _name, string _author, string _publisher, double _price):Book(_id, _name, _author, _publisher)
{
	this->price = _price;
}
