#include "ReaderManagement.h"

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
