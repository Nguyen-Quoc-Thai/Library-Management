#pragma once

#include"Book.h"
#include"InfoBorrow.h"

#include<string>
#include<vector>
#include<iostream>
#include<map>
using namespace std;

class Reader
{
private:
	// Các thuộc tính của đọc giả (id, tên, mảng các quyển sách mượn(mỗi quyển có ngày mượn và sách mượn))
	string id;
	string name;
	vector<InfoBorrow *> list_book_borrow;

	// Nhập xuất danh sách sách mượn (thành phần của Class Reader)
	void enter_list_book_borrow();

	// Phiếu mượn sách
	map<int, pair<int, long long>> check_true_time_and_get_pay_fine();

public:
	// Các phương thức:
	void input();
	void display();

	// Phương thức khởi tạo:
	Reader();
	Reader(string _id);
	Reader(string _id, string _name);

	// Sinh các getter setter:
	void set_id(string _id);
	void set_name(string _name);
	void set_list_book_borrow(vector<InfoBorrow*> _list);

	string get_id();
	string get_name();
	vector<InfoBorrow*> get_list_book_borrow();

	// Phiếu mượn sách:
	void print_bill_borrow();
	void print_bill_return();

	//
	void display_list_book_borrow();
};

