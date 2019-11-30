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

	// Nạp chồng phương thức thuần ảo:
	bool get_type(int i);

	// Nạp chồng lại phương thức load và save file:
	/*void save(ofstream& out_file, VietnamBook* _dummy);
	void load(ifstream& in_file, VietnamBook* _dummy);*/
};

