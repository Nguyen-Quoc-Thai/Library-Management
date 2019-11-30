#pragma once
#pragma pack(pop)

#include"Book.h"

#include<vector>
#include<iostream>
#include<fstream>
using std::vector;

class Library
{
private:
	// Mảng vector chứa tất cả các sách có trong thư viện
	vector<Book*> list_book;

	// Menu phương thức update đối tượng
	void update_menu(int i);

	// Phương thức tìm kiếm nội bộ lấy về vị trí các đối tượng cần tìm:
	vector<int> find_by_id(string _id);
	vector<int> find_by_name(string _name);
	vector<int> find_by_author(string _author);
	vector<int> find_by_publisher(string _publiser);
	vector<int> find_by_price(double _price);

public:
	// Phương thức thêm 1 quyển sách
	void add(Book* _book);

	// Phương thức xuất toàn bộ sách trong thư viện
	void display();

	// Phương thức xóa 1 quyển sách:
	void del_by_book_id(string _id);
	void del_by_book_name(string _name);
	void del_by_book_author(string _author);
	void del_by_book_publisher(string _publiser);
	void del_by_book_price(double _price);

	// Phương thức tìm kiếm sách:
	void find_by_book_id(string _id);
	void find_by_book_name(string _name);
	void find_by_book_author(string _author);
	void find_by_book_publisher(string _publiser);
	void find_by_book_price(double _price);
	 
	// Phương thức update sách:
	void update_by_book_id(string _id);
	void update_by_book_name(string _name);
	void update_by_book_author(string _author);
	void update_by_book_publisher(string _publiser);
	void update_by_book_price(double _price);

	// Phương thức load và save đối tượng:
	void load(string file_name_in);
	void save(string file_name_out);

};

