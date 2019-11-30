#include "EnglishBook.h"

#include<string>
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;



void EnglishBook::input()
{
	Book::input();

	string _dummy = "";

	cout << "Enter book ISBN: ";
	getline(cin, _dummy);
	cin.ignore(0);
	this->ISBN = _dummy;
}

void EnglishBook::display()
{
	Book::display();

	cout << "ISBN: " << this->ISBN << endl;
	cout << endl << endl;
}

EnglishBook::EnglishBook() :Book()
{
	this->ISBN = "";
}

EnglishBook::EnglishBook(string _id) : Book(_id)
{
	this->ISBN = "";
}

EnglishBook::EnglishBook(string _id, string _name) : Book(_id, _name)
{
	this->ISBN = "";
}

EnglishBook::EnglishBook(string _id, string _name, string _author) : Book(_id, _name, _author)
{
	this->ISBN = "";
}

EnglishBook::EnglishBook(string _id, string _name, string _author, string _publisher) : Book(_id, _name, _author, _publisher)
{
	this->ISBN = "";
}

EnglishBook::EnglishBook(string _id, string _name, string _author, string _publisher, double _price) : Book(_id, _name, _author, _publisher, _price)
{
	this->ISBN = "";
}

EnglishBook::EnglishBook(string _id, string _name, string _author, string _publisher, double _price, string _ISBN) : Book(_id, _name, _author, _publisher, _price)
{
	this->ISBN = _ISBN;
}

bool EnglishBook::get_type(int i)
{
	return 2 == i;
}

//void EnglishBook::save(ofstream& out_file, EnglishBook* _dummy)
//{
//	out_file << _dummy->id << endl;
//	out_file << _dummy->name << endl;
//	out_file << _dummy->author << endl;
//	out_file << _dummy->publisher << endl;
//	out_file << _dummy->price << endl;
//	out_file << _dummy->ISBN << endl;
//}
//
//void EnglishBook::load(ifstream& in_file, EnglishBook* _dummy)
//{
//
//}

