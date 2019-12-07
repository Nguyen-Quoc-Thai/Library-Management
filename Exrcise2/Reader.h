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

	// Tính số ngày mượn sách
	int get_day_borrow(string _date);

	// Get local date:
	string get_local_date();

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
	void print_bill_borrow(string _code, string folder_name = "Borrow-Management"); // in phiếu mượn sách
	void print_bill_return(string _code, string folder_name = "Return-Management"); // In phiếu trả sách

	//
	void display_list_book_borrow();

	// Tính tổng tiền quá hạn phải trả:
	long long total_pay_fine();
};

