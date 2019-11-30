#pragma once

#include<string>
using std::string;

class Book
{
protected:
	// Các thuộc tính:
	string id;
	string name;
	string author;
	string publisher;
	double price;

public:
	// Phương thức ảo hóa nhập xuất:
	virtual void input();
	virtual void display();

	// Phương thức khởi tạo:
	Book();
	Book(string _id);
	Book(string _id, string _name);
	Book(string _id, string _name, string _author);
	Book(string _id, string _name, string _author, string _publisher);
	Book(string _id, string _name, string _author, string _publisher, double _price);

	// Sinh các getter và setter
	void set_id(string _id) { this->id = _id; }
	void set_name(string _name) { this->name = _name; }
	void set_author(string _author) { this->author = _author; }
	void set_publisher(string _publisher) { this->publisher = _publisher; }
	void set_price(double _price) { this->price = _price; }

	string get_id() { return this->id; }
	string get_name() { return this->name; }
	string get_author() { return this->author; }
	string get_publisher() { return this->publisher; }
	double get_price() { return this->price; }

	// Get type sách (là sạc VN hay Nước ngoài)
	virtual bool get_type(int i) { return false; };

	// Phương thức đọc ghi xuống file:
	/*virtual void save(ofstream& out_file, Book* _dummy) {}
	virtual void load(ifstream& in_file, Book* _dummy) {}*/
};
