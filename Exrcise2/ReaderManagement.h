#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include"Reader.h"

#include<vector>
using namespace std;

class ReaderManagement
{
	// Mảng tĩnh chứa các đọc giả
	static vector<Reader*> list_reader;

private:
	

	// Phương thức display menu update:
	void update_menu(int i);

	// Tìm đọc giả (Nhận về vị trí các đối tượng đúng yêu cầu):
	vector<int > find_by_id(string _id);
	vector<int > find_by_name(string _name);

public:

	//Phương thức khởi tạo
	ReaderManagement();

	// Phương thức thêm đối tượng:
	void add(Reader* _reader);

	// In danh sách ra màn hình:
	void display();

	// Tìm đọc giả 
	void find_by_reader_id(string _id);
	void find_by_reader_name(string _name);

	// Update đọc giả:
	void update_by_reader_id(string _id);
	void update_by_reader_name(string _name);

	// Delete đọc giả:
	void del_by_reader_id(string _id);
	void del_by_reader_name(string _name);

	// Phương thức load và save đối tượng:
	void load(string file_name_in = "Reader-Mana.txt");
	void save(string file_name_out = "Reader-Mana.txt");

	// In phiếu mượn sách, trả sách
	void print_bill_borrow(string _reader_id);
	void print_bill_return(string _reader_id);

	void print_all_bill_borrow(string _folder_name = "All-Borrow-Management");
	void print_all_bill_return(string _folder_name = "All-Return-Management");

	// Liệt kê danh sách các đọc giả mượn sách quá hạn và số tiền phải trả:
	void list_reader_overdue(string _file_name = "List-Reader-Overdue/List-Over.txt");
};

