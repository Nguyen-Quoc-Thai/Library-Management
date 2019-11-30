#include "VietnamBook.h"

#include<iostream>
using std::cout;
using std::endl;

void VietnamBook::input()
{
	Book::input();
}

void VietnamBook::display()
{
	Book::display();
	cout << endl << endl;
}

VietnamBook::VietnamBook() :Book()
{
}

VietnamBook::VietnamBook(string _id) : Book(_id)
{
}

VietnamBook::VietnamBook(string _id, string _name) : Book(_id, _name)
{
}

VietnamBook::VietnamBook(string _id, string _name, string _author) : Book(_id, _name, _author)
{
}

VietnamBook::VietnamBook(string _id, string _name, string _author, string _publisher) : Book(_id, _name, _author, _publisher)
{
}

VietnamBook::VietnamBook(string _id, string _name, string _author, string _publisher, double _price) : Book(_id, _name, _author, _publisher, _price)
{
}

bool VietnamBook::get_type(int i)
{
	return 1 == i;
}

//void VietnamBook::save(ofstream& out_file, VietnamBook* _dummy)
//{
//	out_file << _dummy->id << endl;
//	out_file << _dummy->name << endl;
//	out_file << _dummy->author << endl;
//	out_file << _dummy->publisher << endl;
//	out_file << _dummy->price << endl;
//}
//
//void VietnamBook::load(ifstream& in_file, VietnamBook* _dummy)
//{
//
//}
