#include "Controller.h"

#include"VietnamBook.h"
#include"EnglishBook.h"

void Controller::onload()
{
	Manager _mn;

	_mn.get_lb().load();
	_mn.get_rm().load();

	Library _lb = _mn.get_lb();
	ReaderManagement _rm = _mn.get_rm();

	int choose = 0;

	while (1)
	{
		system("cls");

		int choose = this->view.render();

		switch (choose)
		{
		case 0: {
			_mn.get_lb().save();
			_mn.get_rm().save();
			return;
		}
		case 10: {


			while (1) {
				system("cls");
				cout << "\nADD BOOK ON LIBRARY" << endl << endl;
				cout << "[VietnameBook enter 1, EnglishBook enter 2, End enter 0] >> ";
				cin >> choose;
				cin.ignore();

				if (choose == 1 || choose == 2 || choose == 0) {
					break;
				}
			}

			if (choose == 0) {
				_mn.get_lb().save();
				_mn.get_rm().save();
				break;
			}

			if (choose == 1) {
				Book* _dummy = new VietnamBook();
				_dummy->input();
				_lb.add(_dummy);
				_mn.set_lb(_lb);
				break;
			}

			if (choose == 2) {
				Book* _dummy = new EnglishBook();
				_dummy->input();
				_lb.add(_dummy);
				_mn.set_lb(_lb);
				break;
			}
		}
			   //------------------------------------------------------------------------------------------------------------------

			   // Delete book------------------------------------
		case 21: {
			string _dummy = "";

			cout << "\nENTER BOOK ID: ";
			getline(cin, _dummy);
			cin.ignore(0);

			_lb.del_by_book_id(_dummy);
			_mn.set_lb(_lb);

			break;

		}
		case 22: {
			string _dummy = "";

			cout << "\nENTER BOOK NAME: ";
			getline(cin, _dummy);
			cin.ignore(0);

			_lb.del_by_book_name(_dummy);
			_mn.set_lb(_lb);

			break;

		}
		case 23: {
			string _dummy = "";

			cout << "\nENTER BOOK AUTHOR: ";
			getline(cin, _dummy);
			cin.ignore(0);

			_lb.del_by_book_author(_dummy);
			_mn.set_lb(_lb);

			break;

		}
		case 24: {
			string _dummy = "";

			cout << "\nENTER BOOK PUBLISHER: ";
			getline(cin, _dummy);
			cin.ignore(0);

			_lb.del_by_book_publisher(_dummy);
			_mn.set_lb(_lb);

			break;

		}
		case 25: {
			string _dummy = "";

			cout << "\nENTER BOOK PRICE: ";
			getline(cin, _dummy);
			cin.ignore(0);

			_lb.del_by_book_price(stoi(_dummy));
			_mn.set_lb(_lb);

			break;

		}

			   // Update book------------------------------------
		case 31: {
			string _dummy = "";

			cout << "\nENTER BOOK ID: ";
			getline(cin, _dummy);
			cin.ignore(0);

			_lb.update_by_book_id(_dummy);
			_mn.set_lb(_lb);

			break;

		}
		case 32: {
			string _dummy = "";

			cout << "\nENTER BOOK NAME: ";
			getline(cin, _dummy);
			cin.ignore(0);

			_lb.update_by_book_name(_dummy);
			_mn.set_lb(_lb);

			break;

		}
		case 33: {
			string _dummy = "";

			cout << "\nENTER BOOK AUTHOR: ";
			getline(cin, _dummy);
			cin.ignore(0);

			_lb.update_by_book_author(_dummy);
			_mn.set_lb(_lb);

			break;

		}
		case 34: {
			string _dummy = "";

			cout << "\nENTER BOOK PUBLISHER: ";
			getline(cin, _dummy);
			cin.ignore(0);

			_lb.update_by_book_publisher(_dummy);
			_mn.set_lb(_lb);

			break;

		}
		case 35: {
			string _dummy = "";

			cout << "\nENTER BOOK PRICE: ";
			getline(cin, _dummy);
			cin.ignore(0);

			_lb.update_by_book_price(stoi(_dummy));
			_mn.set_lb(_lb);

			break;

		}
			   // Find book------------------------------------------

		case 41: {
			string _dummy = "";

			cout << "\nENTER BOOK ID: ";
			getline(cin, _dummy);
			cin.ignore(0);

			_lb.find_by_book_id(_dummy);
			_mn.set_lb(_lb);

			break;

		}
		case 42: {
			string _dummy = "";

			cout << "\nENTER BOOK NAME: ";
			getline(cin, _dummy);
			cin.ignore(0);

			_lb.find_by_book_name(_dummy);
			_mn.set_lb(_lb);

			break;

		}
		case 43: {
			string _dummy = "";

			cout << "\nENTER BOOK AUTHOR: ";
			getline(cin, _dummy);
			cin.ignore(0);

			_lb.find_by_book_author(_dummy);
			_mn.set_lb(_lb);

			break;

		}
		case 44: {
			string _dummy = "";

			cout << "\nENTER BOOK PUBLISHER: ";
			getline(cin, _dummy);
			cin.ignore(0);

			_lb.find_by_book_publisher(_dummy);
			_mn.set_lb(_lb);

			break;

		}
		case 45: {
			string _dummy = "";

			cout << "\nENTER BOOK PRICE: ";
			getline(cin, _dummy);
			cin.ignore(0);

			_lb.find_by_book_price(stoi(_dummy));
			_mn.set_lb(_lb);

			break;

		}

		case 50: {
			Reader* _dummy = new Reader();

			_dummy->input();
			_rm.add(_dummy);

			_mn.set_rm(_rm);

			break;
		}
			   //------------------------------------------------------------------------------------------------------------------

			   // Delete reader------------------------------------
		case 61: {
			string _dummy = "";

			cout << "\nENTER READER ID: ";
			getline(cin, _dummy);
			cin.ignore(0);

			_rm.del_by_reader_id(_dummy);
			_mn.set_rm(_rm);

			break;

		}
		
		case 62: {
			string _dummy = "";

			cout << "\nENTER READER NAME: ";
			getline(cin, _dummy);
			cin.ignore(0);

			_rm.del_by_reader_name(_dummy);
			_mn.set_rm(_rm);

			break;

		}
			   // Update reader------------------------------------------

		case 71: {
			string _dummy = "";

			cout << "\nENTER READER ID: ";
			getline(cin, _dummy);
			cin.ignore(0);

			_rm.update_by_reader_id(_dummy);
			_mn.set_rm(_rm);

			break;

		}

		case 72: {
			string _dummy = "";

			cout << "\nENTER READER NAME: ";
			getline(cin, _dummy);
			cin.ignore(0);

			_rm.update_by_reader_name(_dummy);
			_mn.set_rm(_rm);

			break;

		}
			// Find reader------------------------------------------

		case 81: {
			string _dummy = "";

			cout << "\nENTER READER ID: ";
			getline(cin, _dummy);
			cin.ignore(0);

			_rm.find_by_reader_id(_dummy);
			_mn.set_rm(_rm);

			break;

		}

		case 82: {
			string _dummy = "";

			cout << "\nENTER READER NAME: ";
			getline(cin, _dummy);
			cin.ignore(0);

			_rm.find_by_reader_name(_dummy);
			_mn.set_rm(_rm);

			break;

		}

		case 90: {

			string _dummy = "";

			cout << "\nENTER READER ID: ";
			getline(cin, _dummy);
			cin.ignore(0);

			_rm.print_bill_borrow(_dummy);

			break;

		}
		case 100: {

			string _dummy = "";

			cout << "\nENTER READER ID: ";
			getline(cin, _dummy);
			cin.ignore(0);

			_rm.print_bill_return(_dummy);

			break;

		}
		case 110: {
			_rm.print_all_bill_borrow();

			break;

		}

		case 120: {
			_rm.print_all_bill_return();

			break;

		}

		case 130: {
			_rm.list_reader_overdue();

			break;

		}

		default:
			break;
		}

		system("pause");
	}

}
