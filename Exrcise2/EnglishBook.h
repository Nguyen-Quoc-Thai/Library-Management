#pragma once

#include"Book.h"

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class EnglishBook : public Book
{
private:
	// Thuộc tính riêng của lớp kế thừa
	string ISBN;

public:
	// Nạp chồng lại phương thức ảo hóa nhập xuất:
	void input();
	void display();

	// Phương thức khởi tạo:
	EnglishBook();
	EnglishBook(string _id);
	EnglishBook(string _id, string _name);
	EnglishBook(string _id, string _name, string _author);
	EnglishBook(string _id, string _name, string _author, string _publisher);
	EnglishBook(string _id, string _name, string _author, string _publisher, double _price);
	EnglishBook(string _id, string _name, string _author, string _publisher, double _price, string _ISBN);

	// Sinh các getter và setter:
	void set_id(string _id) { Book::set_id(_id); }
	void set_name(string _name) { Book::set_name(_name); }
	void set_author(string _author) { Book::set_author(_author); }
	void set_publisher(string _publisher) { Book::set_publisher(_publisher); }
	void set_price(double _price) { Book::set_price(_price); }
	void set_ISBN(string _iSBN) { this->ISBN = _iSBN; }


	string get_id() { return this->id; }
	string get_name() { return  this->name; }
	string get_author() { return  this->author; }
	string get_publisher() { return  this->publisher; }
	double get_price() { return  this->price; }
	string get_ISBN() { return this->ISBN; }

	// Nạp chồng phương thức thuần ảo:
	bool get_type(int i);

	// Nạp chồng lại phương thức load và save file:
	/*void save(ofstream& out_file, EnglishBook* _dummy);
	void load(ifstream& in_file, EnglishBook* _dummy);*/
};
