#include "ReaderManagement.h"
#include"EnglishBook.h"
#include"VietnamBook.h"
#include"Library.h"

#include<fstream>
#include<string>
#include<time.h>
#include<iostream>
using namespace std;

ReaderManagement::ReaderManagement()
{
}

void ReaderManagement::add(Reader* _reader)
{
	list_reader.push_back(_reader);
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
		cout << "\n*NOT FOUND !\n\n";
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
	vector<int> _dummy = find_by_name(_name);

	if (_dummy.size() == 0) {
		cout << "\n*NOT FOUND !\n\n";
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
	// Con trỏ file đọc đối tượng:
	ifstream in_file;

	in_file.open(file_name_in);

	string reader_id = "";
	string reader_name = "";
	string num_book_borrow = "";
	string date = "";

	string book_id = "";

	

	int count = 0;

	if (in_file.is_open()) {
		while (!in_file.eof())
		{
			Reader* dummy = new Reader();
			vector<InfoBorrow*> list_book;

			getline(in_file, reader_id);

			if (!reader_id.size()) {
				return;
			}

			getline(in_file, reader_name);
			getline(in_file, num_book_borrow);

			for (int i = 0; i < stoi(num_book_borrow); i++) {
				InfoBorrow* temp = new InfoBorrow();

				getline(in_file, date);
				getline(in_file, book_id);

				for (int j = 0; j < Library::get_list_book().size(); j++) {
					if (Library::get_list_book().at(j)->get_id()._Equal(book_id)) {
						temp->set_book_borrow(Library::get_list_book().at(j));
						temp->set_date_borrow(date);

						list_book.push_back(temp);

						break;
					}
				}
			}

			dummy->set_id(reader_id);
			dummy->set_name(reader_name);
			dummy->set_list_book_borrow(list_book);
			list_reader.push_back(dummy);
		}
	}
}


/* Trình tự ghi xuống file sẽ là:

* Bắt đầu ghi reader ID
* Tiếp theo ghi reader Name
* Tiếp theo ghi số lượng sách mà đọc giả đó mượn

while()

* Ghi reader Date borrow
* Ghi xuống book id

*/
void ReaderManagement::save(string file_name_out)
{
	ofstream out_file;
	bool is_viet_nam_book = false;
	out_file.open(file_name_out);

	if (out_file.is_open()) {
		for (int i = 0; i < list_reader.size(); i++) {

			out_file << list_reader.at(i)->get_id() << endl;  // Ghi xuống file Reader id
			out_file << list_reader.at(i)->get_name() << endl; // Ghi xuống Reader name
			out_file << list_reader.at(i)->get_list_book_borrow().size() << endl; // ghi xuống số lượng sách mà Reader thứ i mượn

			for (int j = 0; j < list_reader.at(i)->get_list_book_borrow().size(); j++) {
				out_file << list_reader.at(i)->get_list_book_borrow().at(j)->get_date_borrow() << endl; // Ghi xuống ngày mượn
				out_file << list_reader.at(i)->get_list_book_borrow().at(j)->get_book_borrow()->get_id() << endl; // Ghi xuống ID
			}
		}
	}
}

void ReaderManagement::print_bill_borrow(string _reader_id)
{
	vector <int > result =  find_by_id(_reader_id);

	if (!result.size()) {
		cout << "\n----> NOT FOUND READER ID !" << endl << endl;
		return;
	}
	else {
		for (int i = 0; i < result.size(); i++) {
			list_reader.at(result.at(i))->print_bill_borrow(list_reader.at(result.at(i))->get_id());
		}
		cout << "\n----> DONE !" << endl << endl;
	}
}

void ReaderManagement::print_bill_return(string _reader_id)
{
	vector <int > result = find_by_id(_reader_id);

	if (!result.size()) {
		cout << "\n----> NOT FOUND READER ID !" << endl << endl;
		return;
	}
	else {
		for (int i = 0; i < result.size(); i++) {
			list_reader.at(result.at(i))->print_bill_return(list_reader.at(result.at(i))->get_id());
		}
		cout << "\n----> DONE !" << endl << endl;
	}
}

void ReaderManagement::print_all_bill_borrow(string _folder_name)
{
	for (int i = 0; i < list_reader.size(); i++) {
		list_reader.at(i)->print_bill_borrow(list_reader.at(i)->get_id(), _folder_name);
	}
	cout << "\n----> DONE !" << endl << endl;
}

void ReaderManagement::print_all_bill_return(string _folder_name)
{
	for (int i = 0; i < list_reader.size(); i++) {
		list_reader.at(i)->print_bill_return(list_reader.at(i)->get_id(), _folder_name);
	}
	cout << "\n----> DONE !" << endl << endl;
}

void ReaderManagement::list_reader_overdue(string _file_name)
{
	ofstream out_file;
	out_file.open(_file_name);

	if (!out_file.is_open()) {
		return;
	}

	time_t cur_time = time(0);
	tm* local = gmtime(&cur_time);

	system("cls");

	out_file << "\n******** LIST READER OVERDUE ***********\n\n";
	cout << "\n******** LIST READER OVERDUE ***********\n\n";

	for (int i = 0; i < list_reader.size(); i++) {
		if ((int)list_reader.at(i)->total_pay_fine() > 0) {
			out_file << "-----------------------------------" << endl;
			out_file << "**READER INFORMATONS: " << endl;
			out_file << "-----------------------------------" << endl << endl;
			out_file << "****READER: id: " << list_reader.at(i)->get_id() << endl;
			out_file << "****READER: name: " << list_reader.at(i)->get_name() << endl << endl;
			out_file << "-----------------------------------" << endl;
			out_file << "------> TOTAL PAYFINE: " << list_reader.at(i)->total_pay_fine() << endl << endl;

			cout << "-----------------------------------" << endl;
			cout << "**READER INFORMATONS: " << endl;
			cout << "-----------------------------------" << endl << endl;
			cout << "****READER: id: " << list_reader.at(i)->get_id() << endl;
			cout << "****READER: name: " << list_reader.at(i)->get_name() << endl << endl;
			cout << "-----------------------------------" << endl;
			cout << "------> TOTAL PAYFINE: " << list_reader.at(i)->total_pay_fine() << endl << endl;
		}
	}
}

void ReaderManagement::update_menu(int i)
{
	int choose = 0;
	string _dummy = "";

	system("cls");

	while (1) {
		system("cls");

		cout <<"\t\t\t\t_____________________________________________________________" << endl
			<< "\t\t\t\t|                    U P D A T E _ R E A D E R              |" << endl
			<< "\t\t\t\t|-----------------------------------------------------------|" << endl
			<< "\t\t\t\t|1.  Change ID                                              |" << endl
			<< "\t\t\t\t|2.  Change Name                                            |" << endl
			<< "\t\t\t\t|0.  No change !                                            |" << endl
			<< "\t\t\t\t|-----------------------------------------------------------|" << endl
			<< "\t\t\t\t|>>  You choose ?                                           |" << endl
			<< "\t\t\t\t|___________________________________________________________|" << endl
			<< "\n\t\t\t\t>> ";

		cin >> choose;
		cin.ignore();

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
