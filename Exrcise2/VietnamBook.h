#pragma once

#include"Book.h"

#include<iostream>
#include<fstream>
using namespace std;

class VietnamBook : public Book
{
public:
	// Nạp chồng lại phương thức ảo hóa nhập xuất:
	void input();
	void display();

	// Phương thức khởi tạo:
	VietnamBook();
	VietnamBook(string _id);
	VietnamBook(string _id, string _name);
	VietnamBook(string _id, string _name, string _author);
	VietnamBook(string _id, string _name, string _author, string _publisher);
	VietnamBook(string _id, string _name, string _author, string _publisher, double _price);	

	// Sinh các getter setter:
	void set_id(string _id) { Book::set_id(_id); }
	void set_name(string _name) { Book::set_name(_name); }
	void set_author(string _author) { Book::set_author(_author); }
	void set_publisher(string _publisher) { Book::set_publisher(_publisher); }
	void set_price(double _price) { Book::set_price(_price); }

	string get_id() { return this->id; }
	string get_name() { return  this->name; }
	string get_author() { return  this->author; }
	string get_publisher() { return  this->publisher; }
	double get_price() { return  this->price; }

	// Nạp chồng phương thức thuần ảo:
	bool get_type(int i);

	// Nạp chồng lại phương thức load và save file:
	/*void save(ofstream& out_file, VietnamBook* _dummy);
	void load(ifstream& in_file, VietnamBook* _dummy);*/
};

