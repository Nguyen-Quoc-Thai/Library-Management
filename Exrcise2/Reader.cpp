#define _CRT_SECURE_NO_WARNINGS 1

#include "Reader.h"
#include"VietnamBook.h"
#include"EnglishBook.h"
#include"Library.h"

#include<time.h>



bool check_valid_para(string _date) {

	time_t cur_time = time(0);
	tm* local = gmtime(&cur_time);

	vector<int> valid_date{ 31,28,31,30,31,30,31,31,30,31,30,31 };

	// dd/MM/yyyy
	if (_date.length() != 10 || _date.at(2) != '/' || _date.at(5) != _date.at(2)) {
		return false;
	}

	int day, month, year;

	day = stoi(_date.substr(0, 2));
	month = stoi(_date.substr(3, 2));
	year = stoi(_date.substr(6));

	if (year < 1900 || year > local->tm_year + 1900) {
		return false;
	}

	// Kiểm tra năm nhuận
	if (year % 400 == 0) {
		valid_date.at(1)++;
	}

	// Kiểm tra đúng tháng
	if (month <= 0 || month > 12) {
		return false;
	}

	// Kiểm tra ngày hợp lệ
	if (day <= 0 || day > valid_date.at(month - 1)) {
		return false;
	}

	return true;
}

void Reader::enter_list_book_borrow()
{
	int choose = 0;
	int choose2 = 0;
	string _date = "";

	vector<Book*> list_book_ = Library::get_list_book();

	while (1) {
		while (1) {
			system("cls");
			cout << "\n___BOOK BORROW:___\n" << endl;
			cout << "[VietnameBook enter 1, EnglishBook enter 2, End enter 0] >> ";
			cin >> choose;
			cin.ignore();

			if (choose == 1 || choose == 2 || choose == 0) {
				break;
			}
		}
		
	
		if (choose == 0) {
			return;
		}
		else {
			if (choose == 1) {
				while (1)
				{
					cout << "\nENTER: Date borrow (format: dd/MM/yyyy) \n";

					while (1) {
						cout << "[Get local time enter 1, Handle enter 2] >> ";
						cin >> choose2;
						cin.ignore();

						if (choose2 == 1 || choose2 == 2) {
							break;
						}
					}

					if (choose2 == 1) {

						_date += get_local_date();

						goto a;
					}
					else {
						while (1) {
							cout << "ENTER: Date borrow: ";
							getline(cin, _date);
							cin.ignore(0);

							if (check_valid_para(_date)) {
								goto a;
							}
						}
					}
				}

			a:

				string _id = "";

				cout << "ENTER: BOOK ID: ";
				getline(cin, _id);
				cin.ignore(0);


				Book* _dummy = new VietnamBook();

				// Kiểm tra nếu ID sách đã tồn tại ở Library rồi thì lấy nó add vào Reader_book_borrow. Nếu chưa thì gọi phương thức add và thêm nó vào cả Reader_book
				// borrow và Library
				for (int i = 0; i < list_book_.size(); i++) {
					if (list_book_.at(i)->get_id()._Equal(_id)) {
						_dummy = list_book_.at(i);
						break;
					}
				}

				// Nếu chưua có ID sách trong thư viện thì
				if (_dummy->get_id()._Equal("")) {
					cout << "\nBOOK HAS NO INFOMATION IN LIBRARY. PLEASE ENTER THIS BOOK ! \n\n";

					_dummy->input();
					list_book_.push_back(_dummy);
					Library::set_list_book(list_book_);
				}

				InfoBorrow* garbage = new InfoBorrow(_date, _dummy);
				list_book_borrow.push_back(garbage);
			}
			else {
				while (1)
				{
					cout << "\nENTER: Date borrow (format: dd/MM/yyyy) \n";

					while (1) {
						cout << "[Get local time enter 1, Handle enter 2] >> ";
						cin >> choose2;
						cin.ignore();

						if (choose2 == 1 || choose2 == 2) {
							break;
						}
					}

					if (choose2 == 1) {

						_date = get_local_date();

						goto b;


					}
					else {
						while (1) {
							cout << "ENTER: Date borrow: ";
							getline(cin, _date);
							cin.ignore(0);

							if (check_valid_para(_date)) {
								goto b;
							}
						}
					}
				}

			b:

				string _id = "";

				cout << "ENTER: BOOK ID: ";
				getline(cin, _id);
				cin.ignore(0);


				Book* _dummy = new EnglishBook();

				// Kiểm tra nếu ID sách đã tồn tại ở Library rồi thì lấy nó add vào Reader_book_borrow. Nếu chưa thì gọi phương thức add và thêm nó vào cả Reader_book
				// borrow và Library
				for (int i = 0; i < list_book_.size(); i++) {
					if (list_book_.at(i)->get_id()._Equal(_id)) {
						_dummy = list_book_.at(i);
						break;
					}
				}

				// Nếu chưua có ID sách trong thư viện thì
				if (_dummy->get_id()._Equal("")) {
					cout << "\nBOOK HAS NO INFOMATION IN LIBRARY. PLEASE ENTER THIS BOOK ! \n\n";
					_dummy->input();
					list_book_.push_back(_dummy);
					Library::set_list_book(list_book_);
				}

				InfoBorrow* garbage = new InfoBorrow(_date, _dummy);
				list_book_borrow.push_back(garbage);
			}
		}
	}
}

// Hàm đổi ra số ngày từ một thời điểm đánh dấu xác định ở quá khứ
long long get_day_from(int year, int month, int day) {
	if (month < 3) {
		year--;
		month += 12;
	}
	return 365 * year + year / 4 - year / 100 + year / 400 + (153 * month - 457) / 5 + day - 306;
}

void Reader::display_list_book_borrow()
{
	for (int i = 0; i < list_book_borrow.size(); i++) {
		cout << "**DATE: " << list_book_borrow.at(i)->get_date_borrow() << endl;
		cout << "____________________ \n";
		cout << "**BOOK:" << endl;
		list_book_borrow.at(i)->get_book_borrow()->display();
	}
}

long long Reader::total_pay_fine()
{
	long long sum_pay_fine = 0.0;

	for (int i = 0; i < list_book_borrow.size(); i++) {

		bool is_viet_nam_book = list_book_borrow.at(i)->get_book_borrow()->get_type(1);

		string _date = list_book_borrow.at(i)->get_date_borrow();
		int _count = get_day_borrow(_date);

		if (is_viet_nam_book) {
			if (_count > 7) {
				sum_pay_fine += (_count - 7) * 10000;
			}
		}
		else {
			
			if (_count > 7) {
				sum_pay_fine += (_count - 7) * 20000;
			}
		}
	}

	return sum_pay_fine;
}

int Reader::get_day_borrow(string _date)
{
	time_t cur_time = time(0);
	tm* local = gmtime(&cur_time);

	// dd/MM/yyyy
	int day, month, year;
	long long count;

		day = stoi(_date.substr(0, 2));
		month = stoi(_date.substr(3, 2));
		year = stoi(_date.substr(6));

		return get_day_from(local->tm_year + 1900, local->tm_mon + 1, local->tm_mday) - get_day_from(year, month, day);
}

string Reader::get_local_date()
{
	string _day = "", _month = "", _year = "";
	string _date = "";

	time_t cur_time = time(0);
	tm* local = gmtime(&cur_time);

	// Kiểm tra số lượng chử số ngày tháng nếu chưa đúng định dạng dd/MM/yyyy thì thêm kí tự giả vào
	if (to_string(local->tm_mday).size() == 1) {
		_day += "0" + to_string(local->tm_mday);

	}
	else {
		_day += to_string(local->tm_mday);
	}

	if (to_string(local->tm_mon + 1).size() == 1) {
		_month += "0" + to_string(local->tm_mon + 1);

	}
	else {
		_month += to_string(local->tm_mon + 1);
	}

	_year += to_string(local->tm_year + 1900);

	_date += _day + "/" + _month + "/" + _year;

	return string(_date);
}

void Reader::input()
{
	system("cls");
	cout << "\nENTER: Reader id: ";
	getline(cin, this->id);
	cin.ignore(0);

	cout << "ENTER: Reader name: ";
	getline(cin, this->name);
	cin.ignore(0);

	enter_list_book_borrow();
}

void Reader::display()
{
	cout << "__________________" << endl;
	cout << "**READER: id: " << this->id << endl;
	cout << "**READER: name: " << this->name << endl << endl;

	display_list_book_borrow();
}

Reader::Reader()
{
	this->id = this->name = "";
}

Reader::Reader(string _id):Reader()
{
	this->id = _id;
}

Reader::Reader(string _id, string _name):Reader(_id)
{
	this->name = _name;
}

void Reader::set_id(string _id)
{
	this->id = _id;
}

void Reader::set_name(string _name)
{
	this->name = _name;
}

void Reader::set_list_book_borrow(vector<InfoBorrow*> _list)
{
	this->list_book_borrow = _list;
}

string Reader::get_id()
{
	return string(this->id);
}

string Reader::get_name()
{
	return string(this->name);
}

vector<InfoBorrow*> Reader::get_list_book_borrow()
{
	return vector<InfoBorrow*>(list_book_borrow);
}

void Reader::print_bill_borrow(string _code, string folder_name)
{
	ofstream out_file;
	out_file.open(folder_name + "/" + _code + ".txt");

	if (out_file.is_open()) {
		out_file << "\n****** BILL BORROW ******\n\n";
		out_file << "**CODE: " << _code << "HCMUS" << endl << endl;
		out_file << "-----------------------------------" << endl;
		out_file << "**READER INFORMATONS: " << endl;
		out_file << "-----------------------------------" << endl << endl;
		out_file << "****READER: id: " << this->id << endl;
		out_file << "****READER: name: " << this->name << endl << endl;
		out_file << "-----------------------------------" << endl;
		out_file << "**BOOK INFORMATONS: " << endl;
		out_file << "-----------------------------------" << endl << endl;

		for (int i = 0; i < list_book_borrow.size(); i++) {
			
			if (list_book_borrow.at(i)->get_book_borrow()->get_type(1)) {
				out_file << "*Vietnam-Book" << endl;
			}
			else {
				out_file << "*English-Book" << endl;
			}

			if (list_book_borrow.at(i)->get_book_borrow()->get_type(1)) {
				VietnamBook* _dummy = (VietnamBook*)list_book_borrow.at(i)->get_book_borrow();
				out_file << "\t+ Book id: " << _dummy->get_id() << endl;
				out_file << "\t+ Book name: " << _dummy->get_name() << endl;
				out_file << "\t+ Book author: " << _dummy->get_author() << endl;
				out_file << "\t+ Book publisher: " << _dummy->get_publisher() << endl;
				out_file << "\t+ Book price: " << _dummy->get_price() << endl << endl;
				out_file << "****DATE: " << list_book_borrow.at(i)->get_date_borrow() << endl;
				out_file << "-----------------------------------" << endl << endl;
			}
			else {
				EnglishBook* _dummy = (EnglishBook*)list_book_borrow.at(i)->get_book_borrow();
				out_file << "\t+ Book id: " << _dummy->get_id() << endl;
				out_file << "\t+ Book name: " << _dummy->get_name() << endl;
				out_file << "\t+ Book author: " << _dummy->get_author() << endl;
				out_file << "\t+ Book publisher: " << _dummy->get_publisher() << endl;
				out_file << "\t+ Book price: " << _dummy->get_price() << endl;
				out_file << "\t+ Book ISBN: " << _dummy->get_ISBN() << endl << endl;
				out_file << "****DATE: " << list_book_borrow.at(i)->get_date_borrow() << endl;
				out_file << "-----------------------------------" << endl << endl;
			}
		}
	}
	else {
		cout << "Fail to create bill borrow\n";
		return;
	}
}

void Reader::print_bill_return(string _code, string folder_name)
{
	ofstream out_file;
	out_file.open(folder_name + "/" + _code + ".txt");

	time_t cur_time = time(0);
	tm* local = gmtime(&cur_time);

	long long sum_pay_fine = 0.0; // Tổng tiền phải trả nếu sách quá hạn quá 
	bool is_viet_nam_book = true;

	if (out_file.is_open()) {
		out_file << "\n****** BILL RETURN ******\n\n";
		out_file << "**CODE: " << _code << "HCMUS" << endl << endl;
		out_file << "-----------------------------------" << endl;
		out_file << "**READER INFORMATONS: " << endl;
		out_file << "-----------------------------------" << endl << endl;
		out_file << "****READER: id: " << this->id << endl;
		out_file << "****READER: name: " << this->name << endl << endl;
		out_file << "-----------------------------------" << endl;
		out_file << "**BOOK INFORMATONS: " << endl;
		out_file << "-----------------------------------" << endl << endl;

		for (int i = 0; i < list_book_borrow.size(); i++) {

			is_viet_nam_book = list_book_borrow.at(i)->get_book_borrow()->get_type(1);

			string _date = list_book_borrow.at(i)->get_date_borrow();
			int _count = get_day_borrow(_date);

			

			if (is_viet_nam_book) {
				out_file << "*Vietnam-Book" << endl;
			}
			else {
				out_file << "*English-Book" << endl;
			}

			if (is_viet_nam_book) {
				VietnamBook* _dummy = (VietnamBook*)list_book_borrow.at(i)->get_book_borrow();

				out_file << "\t+ Book id: " << _dummy->get_id() << endl;
				out_file << "\t+ Book name: " << _dummy->get_name() << endl;
				out_file << "\t+ Book author: " << _dummy->get_author() << endl;
				out_file << "\t+ Book publisher: " << _dummy->get_publisher() << endl;
				out_file << "\t+ Book price: " << _dummy->get_price() << endl << endl;

				out_file << "****DATE BORROW: " << list_book_borrow.at(i)->get_date_borrow() << endl;
				out_file << "****DATE RETURN: " << get_local_date()  << endl;

				if (_count > 7) {
					out_file << "\n----- OVERDUE: " << _count - 7 << " DAYS" << endl;

					out_file << "----> PAY FINE: " << (_count - 7) * 10000 << " VND" << endl;
					sum_pay_fine += (_count - 7) * 10000;
				}
				else {
					out_file << "\n----- DONT OVERDUE" << endl;
					out_file << "----> NO PAY FINE !" << endl;
				}

				out_file << "-----------------------------------" << endl << endl << endl;
			}
			else {
				EnglishBook* _dummy = (EnglishBook*)list_book_borrow.at(i)->get_book_borrow();

				out_file << "\t+ Book id: " << _dummy->get_id() << endl;
				out_file << "\t+ Book name: " << _dummy->get_name() << endl;
				out_file << "\t+ Book author: " << _dummy->get_author() << endl;
				out_file << "\t+ Book publisher: " << _dummy->get_publisher() << endl;
				out_file << "\t+ Book price: " << _dummy->get_price() << endl;
				out_file << "\t+ Book ISBN: " << _dummy->get_ISBN() << endl << endl;

				out_file << "****DATE BORROW: " << list_book_borrow.at(i)->get_date_borrow() << endl;
				out_file << "****DATE RETURN: " << get_local_date() << endl;

				if (_count > 7) {
					out_file << "\n----- OVERDUE: " << _count - 7 << " DAYS" << endl;

					out_file << "----> PAY FINE: " << (_count - 7) * 20000 << " VND" << endl;
					sum_pay_fine += (_count - 7) * 20000;
				}
				else {
					out_file << "\n----- DONT OVERDUE"<< endl;
					out_file << "----> NO PAY FINE !" << endl;
				}

				out_file << "-----------------------------------" << endl << endl;
			}
		}

		out_file << "====>> TOTAL FEE PAYABLE: " << sum_pay_fine;
	}
	else {
		cout << "Fail to create bill borrow\n";
		return;
	}
}

