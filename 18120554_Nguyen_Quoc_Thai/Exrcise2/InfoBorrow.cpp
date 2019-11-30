#include "InfoBorrow.h"

void InfoBorrow::set_date_borrow(string _date)
{
	this->date_borrow = _date;
}

void InfoBorrow::set_book_borrow(Book* _book)
{
	this->book_borrow = _book;
}

string InfoBorrow::get_date_borrow()
{
	return string(this->date_borrow);
}

Book* InfoBorrow::get_book_borrow()
{
	return this->book_borrow;
}
