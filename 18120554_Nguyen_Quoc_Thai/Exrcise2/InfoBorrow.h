#pragma once

#include"Book.h"

#include<string>
#include<iostream>
using namespace std;

class InfoBorrow
{
private:
	string date_borrow;
	Book* book_borrow;

public:
	// Sinh các getter và setter
	void set_date_borrow(string _date);
	void set_book_borrow(Book* _book);

	string get_date_borrow();
	Book* get_book_borrow();

	// Phương thức khởi tạo
	InfoBorrow() { this->date_borrow = ""; this->book_borrow = nullptr; }
	InfoBorrow(string _date, Book* _book) { this->date_borrow = _date; this->book_borrow = _book; }

};

