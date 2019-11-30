#include "ReaderManagement.h"
#include"EnglishBook.h"
#include"VietnamBook.h"

#include<fstream>
#include<iostream>
using namespace std;

ReaderManagement::ReaderManagement()
{
}

void ReaderManagement::add(Reader* _reader)
{
	Reader* dummy = new Reader();

	dummy->input();
	list_reader.push_back(dummy);
}

void ReaderManagement::display()
{
	cout << "\n______DISPLAY______\n\n";
	for (int i = 0; i < list_reader.size(); i++) {
		list_reader.at(i)->display();
	}
}

void ReaderManagement::find_by_reader_id(string _id)
{
	for (int i = 0; i < list_reader.size(); i++) {
		if (list_reader.at(i)->get_id()._Equal(_id)) {
			cout << "*READER: " << endl;
			list_reader.at(i)->display();
		}
	}
}

void ReaderManagement::find_by_reader_name(string _name)
{
	for (int i = 0; i < list_reader.size(); i++) {
		if (list_reader.at(i)->get_name()._Equal(_name)) {
			cout << "*READER: " << endl;
			list_reader.at(i)->display();
		}
	}
}

void ReaderManagement::update_by_reader_id(string _id)
{
	vector<int> _dummy = find_by_id(_id);

	if (_dummy.size() == 0) {
		cout << "NOT FOUND !\n";
		return;
	}

	cout << "**TOTAL FOUND " << _dummy.size() << " RESULTS !\n";

	for (int i = 0; i < _dummy.size(); i++) {
		cout << "*UPDATE BOOK " << i + 1 << endl;
		update_menu(_dummy.at(i));
	}
}

void ReaderManagement::update_by_reader_name(string _name)
{
	vector<int> _dummy = find_by_id(_name);

	if (_dummy.size() == 0) {
		cout << "NOT FOUND !\n";
		return;
	}

	cout << "**TOTAL FOUND " << _dummy.size() << " RESULTS !\n";

	for (int i = 0; i < _dummy.size(); i++) {
		cout << "*UPDATE BOOK " << i + 1 << endl;
		update_menu(_dummy.at(i));
	}
}

void ReaderManagement::del_by_reader_id(string _id)
{
	for (int i = 0; i < list_reader.size(); i++) {
		if (list_reader.at(i)->get_id()._Equal(_id)) {
			list_reader.erase(list_reader.begin() + i);
			i--;
		}
	}
}

void ReaderManagement::del_by_reader_name(string _name)
{
	for (int i = 0; i < list_reader.size(); i++) {
		if (list_reader.at(i)->get_name()._Equal(_name)) {
			list_reader.erase(list_reader.begin() + i);
			i--;
		}
	}
}

void ReaderManagement::load(string file_name_in)
{

}


/* Trình tự ghi xuống file sẽ là:

* Bắt đầu với kí tự đánh dấu là '#'
* Tiếp theo ghi reader ID
* Tiếp theo ghi reader Name

while()

* Ghi reader Date
* Ghi 1 or 0 thể hiện sách là Việt Nam hay English
* Ghi các thuộc tính tương ứng với từng loại sách

*/
void ReaderManagement::save(string file_name_out)
{
	ofstream out_file;
	bool is_viet_nam_book = false;
	out_file.open(file_name_out, ios::out);

	if (out_file.is_open()) {
		for (int i = 0; i < list_reader.size(); i++) {
			out_file << "#" << endl;
			out_file << list_reader.at(i)->get_id() << endl;
			out_file << list_reader.at(i)->get_name() << endl;
			for (int j = 0; j < list_reader.at(i)->get_list_book_borrow().size(); j++) {
				is_viet_nam_book = list_reader.at(i)->get_list_book_borrow().at(j)->get_book_borrow()->get_type(1);
				
				out_file << list_reader.at(i)->get_list_book_borrow().at(j)->get_date_borrow() << endl;
				out_file << is_viet_nam_book << endl;

				if (is_viet_nam_book) {
					VietnamBook* _dummy = (VietnamBook*)list_reader.at(i)->get_list_book_borrow().at(j);
					out_file << _dummy->get_id() << endl;
					out_file << _dummy->get_name() << endl;
					out_file << _dummy->get_author() << endl;
					out_file << _dummy->get_publisher() << endl;
					out_file << _dummy->get_price() << endl;
				}
				else {
					EnglishBook* _dummy = (EnglishBook*)list_reader.at(i)->get_list_book_borrow().at(j);
					out_file << _dummy->get_id() << endl;
					out_file << _dummy->get_name() << endl;
					out_file << _dummy->get_author() << endl;
					out_file << _dummy->get_publisher() << endl;
					out_file << _dummy->get_price() << endl;
					out_file << _dummy->get_ISBN() << endl;
				}
			}
		}
	}
}

void ReaderManagement::update_menu(int i)
{
	int choose = 0;
	string _dummy = "";

	system("cls");

	while (1) {
		cout<< "*1: Change ID \n"
			<< "*2: Change Name \n"
			<< "*0: No change ! \n"
			<< "+ Choose ?  \n"
			<< ">> ";

		cin >> choose;

		switch (choose)
		{
		case 0: {
			return;
		}
		case 1: {
			cout << "+ New ID: ";
			getline(cin, _dummy);
			cin.ignore(0);
			list_reader.at(i)->set_id(_dummy);
			break;
		}
		case 2: {
			cout << "+ New Name: ";
			getline(cin, _dummy);
			cin.ignore(0);
			list_reader.at(i)->set_name(_dummy);
			break;
		}

		default: break;
		}
	}
}

vector<int> ReaderManagement::find_by_id(string _id)
{
	vector<int>_dummy;

	for (int i = 0; i < this->list_reader.size(); i++) {
		if (list_reader.at(i)->get_id()._Equal(_id)) {
			_dummy.push_back(i);
		}
	}

	return vector<int>(_dummy);
}

vector<int> ReaderManagement::find_by_name(string _name)
{

	vector<int>_dummy;

	for (int i = 0; i < this->list_reader.size(); i++) {
		if (list_reader.at(i)->get_name()._Equal(_name)) {
			_dummy.push_back(i);
		}
	}

	return vector<int>(_dummy);
}
