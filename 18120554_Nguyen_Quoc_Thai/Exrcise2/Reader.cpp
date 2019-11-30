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

					break;


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
					
					break;


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

// Hàm đổi ra số ngày từ một thời điểm đánh dấu ở quá khứ
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

map<int, pair<int, long long>> Reader::check_true_time_and_get_pay_fine()
{
	map<int, pair<int, long long>> map_out_of_date;
	pair<int, pair<int, long long>> _dummy;

	time_t cur_time = time(0);
	tm* local = gmtime(&cur_time);

	// dd/MM/yyyy

	int day, month, year;
	long long count;

	for (int i = 0; i < list_book_borrow.size(); i++) {
		day = stoi(list_book_borrow.at(i)->get_date_borrow().substr(0, 2));
		month = stoi(list_book_borrow.at(i)->get_date_borrow().substr(3, 2));
		year = stoi(list_book_borrow.at(i)->get_date_borrow().substr(6));

		count = get_day_from(local->tm_year + 1900, local->tm_mon + 1, local->tm_mday) - get_day_from(year, month, day);

		if (count > 7) {
			_dummy.first = i;
			_dummy.second.first = count - 7;

			bool is_vn_book = list_book_borrow.at(i)->get_book_borrow()->get_type(1);

			if (is_vn_book) {
				_dummy.second.second = 10000 * _dummy.second.first;
			}
			else {
				_dummy.second.second = 20000 * _dummy.second.first;
			}
		
			map_out_of_date.insert(_dummy);
		}
	}

	return map_out_of_date;
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
	cout << "Reader id: " << this->id << endl;
	cout << "Reader name: " << this->name << endl << endl;

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

string Reader::get_id()
{
	return string(this->id);
}

string Reader::get_name()
{
	return string(this->name);
}

void Reader::print_bill_borrow()
{
	system("cls");
	cout << "\n\n***** BILL BORROW ******\n\n";
	cout << "**READER: " << endl;
	display();
}

void Reader::print_bill_return()
{
	cout << "\n\n***** BILL RETURN *****\n\n";
	cout << "**READER:" << endl;
	display();

	map<int, pair<int, long long>> map_out_of_date = check_true_time_and_get_pay_fine();

	if (map_out_of_date.size()) {
		cout << "\n**YOU BORROWED OVERDUE BOOKS !\n\n";

		map<int, pair<int, long long>>::iterator it;
		long long sum_pay_fine = 0.0;

		for (it = map_out_of_date.begin(); it != map_out_of_date.end(); it++) {
			list_book_borrow.at(it->first)->get_book_borrow()->display();
			cout << "\n**OUT OF DATE: " << it->second.first << " DAYS !\n";
			sum_pay_fine += it->second.second;
		}

		cout << "\n**TOTAL PAY FINE: " << sum_pay_fine << endl << endl;
	}
}

