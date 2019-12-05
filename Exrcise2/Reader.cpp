#define _CRT_SECURE_NO_WARNINGS 1

#include "Reader.h"
#include"VietnamBook.h"
#include"EnglishBook.h"

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

	while (1) {
		system("cls");
		cout << "___BOOK BORROW:___" << endl;
		cout << "[VietnameBook enter 1, EnglishBook enter 2, End enter 0] >> ";
		cin >> choose;
		cin.ignore();	
	
		if (choose == 0) {
			return;
		}

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
					time_t cur_time = time(0);
					tm* local = gmtime(&cur_time);

					_date = to_string(local->tm_mday) + "/" + to_string(local->tm_mon + 1) + "/" + to_string(local->tm_year + 1900);

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

			Book* _dummy = new VietnamBook();
			_dummy->input();

			InfoBorrow *garbage = new InfoBorrow(_date, _dummy);

			list_book_borrow.push_back(garbage);
		}

		if (choose == 2) {

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
					time_t cur_time = time(0);
					tm* local = gmtime(&cur_time);

					_date = to_string(local->tm_mday) + "/" + to_string(local->tm_mon + 1) + "/" + to_string(local->tm_year + 1900);
					
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

			Book* _dummy = new EnglishBook();
			_dummy->input();

			InfoBorrow *garbage = new InfoBorrow(_date, _dummy);
			list_book_borrow.push_back(garbage);
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

void Reader::input()
{
	cout << "ENTER: Reader id: ";
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

void Reader::print_bill_borrow(string _code)
{
	ofstream out_file;
	out_file.open("Borrow-Management/" + _code + ".txt");

	if (out_file.is_open()) {
		out_file << "\n****** BILL BORROW ******\n\n";
		out_file << "**CODE: " << _code << "HCMUS" << endl << endl;
		out_file << "-----------------------------------" << endl;
		out_file << "**READER INFORMATONS: " << endl;
		out_file << "-----------------------------------" << endl;
		out_file << "****READER: id: " << this->id << endl;
		out_file << "****READER: name: " << this->name << endl << endl;
		out_file << "-----------------------------------" << endl;
		out_file << "**BOOK INFORMATONS: " << endl;
		out_file << "-----------------------------------" << endl << endl;

		for (int i = 0; i < list_book_borrow.size(); i++) {
			out_file << "****DATE: " << list_book_borrow.at(i)->get_date_borrow() << endl;
			out_file << "-----------------------------------" << endl;
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
			}
			else {
				EnglishBook* _dummy = (EnglishBook*)list_book_borrow.at(i)->get_book_borrow();
				out_file << "\t+ Book id: " << _dummy->get_id() << endl;
				out_file << "\t+ Book name: " << _dummy->get_name() << endl;
				out_file << "\t+ Book author: " << _dummy->get_author() << endl;
				out_file << "\t+ Book publisher: " << _dummy->get_publisher() << endl;
				out_file << "\t+ Book price: " << _dummy->get_price() << endl;
				out_file << "\t+ Book ISBN: " << _dummy->get_ISBN() << endl << endl;
			}
		}
	}
	else {
		cout << "Fail to create bill borrow\n";
		return;
	}
}

void Reader::print_bill_return(string _code)
{
	ofstream out_file;
	out_file.open("Return-Management/" + _code + ".txt");

	time_t cur_time = time(0);
	tm* local = gmtime(&cur_time);

	long long sum_pay_fine = 0.0; // Tổng tiền phải trả nếu sách quá hạn quá 
	bool is_viet_nam_book = true;

	if (out_file.is_open()) {
		out_file << "\n****** BILL RETURN ******\n\n";
		out_file << "**CODE: " << _code << "HCMUS" << endl << endl;
		out_file << "-----------------------------------" << endl;
		out_file << "**READER INFORMATONS: " << endl;
		out_file << "-----------------------------------" << endl;
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
				out_file << "****DATE RETURN: " << to_string(local->tm_mday) + "/" + to_string(local->tm_mon + 1) + "/" + to_string(local->tm_year + 1900) << endl;

				if (_count > 7) {
					out_file << "----- OVERDUE: " << _count - 7 << " DAYS" << endl;

					if (is_viet_nam_book) {
						out_file << "----> PAY FINE: " << (_count - 7) * 10000 << " VNĐ" << endl;
						sum_pay_fine += (_count - 7) * 10000;
					}
					else {
						out_file << "----> PAY FINE: " << (_count - 7) * 20000 << " VNĐ" << endl;
						sum_pay_fine += (_count - 7) * 20000;
					}
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
				out_file << "****DATE RETURN: " << to_string(local->tm_mday) + "/" + to_string(local->tm_mon + 1) + "/" + to_string(local->tm_year + 1900) << endl;

				if (_count > 7) {
					out_file << "----- OVERDUE: " << _count - 7 << " DAYS" << endl;

					if (is_viet_nam_book) {
						out_file << "----> PAY FINE: " << (_count - 7) * 10000 << " VND" << endl;
						sum_pay_fine += (_count - 7) * 10000;
					}
					else {
						out_file << "----> PAY FINE: " << (_count - 7) * 20000 << " VND" << endl;
						sum_pay_fine += (_count - 7) * 20000;
					}
				}

				out_file << "-----------------------------------" << endl << endl << endl;
			}
		}

		out_file << "====>> TOTAL FEE PAYABLE: " << sum_pay_fine;
	}
	else {
		cout << "Fail to create bill borrow\n";
		return;
	}
}

