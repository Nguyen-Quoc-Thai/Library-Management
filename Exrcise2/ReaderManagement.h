#pragma once

#include"Reader.h"

#include<vector>
using namespace std;

class ReaderManagement
{
private:
	// Mảng chứa các đọc giả
	vector<Reader*> list_reader;

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
	void load(string file_name_in);
	void save(string file_name_out);
};

