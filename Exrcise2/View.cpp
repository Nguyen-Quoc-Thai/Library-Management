#include "View.h"

int View::render()
{
	int choose2 = 0;
	int choose1 = main_menu();

	if (choose1 == 2) {
		choose2 = menu_son_1_delete();
	}
	if (choose1 == 3) {
		choose2 = menu_son_1_update();
	}
	if (choose1 == 4) {
		choose2 = menu_son_1_find();
	}
	if (choose1 == 6) {
		choose2 = menu_son_2_delete();
	}
	if (choose1 == 7) {
		choose2 = menu_son_2_update();
	}
	if (choose1 == 8) {
		choose2 = menu_son_2_find();
	}

	if (choose1 == 0) {
		return 0;
	}

	return choose1 * 10 + choose2;
}

int View::main_menu()
{
	int choose = 0;

	while (true)
	{
		system("cls");

		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "+                           M E N U                         +" << endl
			<< "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "+1.  ADD BOOK                                               +" << endl
			<< "+2.  DELETE BOOK                                            +" << endl
			<< "+3.  UPDATE BOOK                                            +" << endl
			<< "+4.  FIND BOOK                                              +" << endl
			<< "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "+5.  ADD READER                                             +" << endl
			<< "+6.  DELETE READER                                          +" << endl
			<< "+7.  UPDATE READER                                          +" << endl
			<< "+8.  FIND READER                                            +" << endl
			<< "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "+9.  CREATE BORROW BILL                                     +" << endl
			<< "+10. CREATE RETURN BILL                                     +" << endl
			<< "+11. CREATE ALL BORROW BILL                                 +" << endl
			<< "+12. CREATE ALL RETURN BILL                                 +" << endl
			<< "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "+13. LIST READER BORROW OVERDUE                             +" << endl
			<< "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "+0.  EXIT                                                   +" << endl
			<< "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "\n>> ";

		cin >> choose;
		cin.ignore();

		if (choose >= 0 && choose <= 13) {
			return choose;
		}
	}
}

int View::menu_son_1_delete()
{
	int choose = 0;

	while (true)
	{
		system("cls");

		cout <<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "+               M E N U _ D E L E T E _ B O O K             +" << endl
			<< "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "+1.  BY ID                                                  +" << endl
			<< "+2.  BY NAME                                                +" << endl
			<< "+3.  BY AUTHOR                                              +" << endl
			<< "+4.  BY PUBLISHER                                           +" << endl
			<< "+5.  BY PRICE                                               +" << endl
			<< "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "+0.  EXIT                                                   +" << endl
			<< "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "\n>> ";

		cin >> choose;
		cin.ignore();

		if (choose >= 0 && choose <= 5) {
			return choose;
		}
	}
}

int View::menu_son_1_update()
{
	int choose = 0;

	while (true)
	{
		system("cls");

		cout <<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "+               M E N U _ U P D A T E _ B O O K             +" << endl
			<< "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "+1.  BY ID                                                  +" << endl
			<< "+2.  BY NAME                                                +" << endl
			<< "+3.  BY AUTHOR                                              +" << endl
			<< "+4.  BY PUBLISHER                                           +" << endl
			<< "+5.  BY PRICE                                               +" << endl
			<< "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "+0.  EXIT                                                   +" << endl
			<< "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "\n>> ";

		cin >> choose;
		cin.ignore();

		if (choose >= 0 && choose <= 5) {
			return choose;
		}
	}
}

int View::menu_son_1_find()
{
	int choose = 0;

	while (true)
	{
		system("cls");

		cout <<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "+               M E N U _ F I N D _ B O O K                 +" << endl
			<< "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "+1.  BY ID                                                  +" << endl
			<< "+2.  BY NAME                                                +" << endl
			<< "+3.  BY AUTHOR                                              +" << endl
			<< "+4.  BY PUBLISHER                                           +" << endl
			<< "+5.  BY PRICE                                               +" << endl
			<< "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "+0.  EXIT                                                   +" << endl
			<< "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "\n>> ";

		cin >> choose;
		cin.ignore();

		if (choose >= 0 && choose <= 5) {
			return choose;
		}
	}
}

int View::menu_son_2_delete()
{
	int choose = 0;

	while (true)
	{
		system("cls");

		cout <<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "+             M E N U _ D E L E T E _ R E A D E R           +" << endl
			<< "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "+1.  BY ID                                                  +" << endl
			<< "+2.  BY NAME                                                +" << endl
			<< "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "+0.  EXIT                                                   +" << endl
			<< "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "\n>> ";

		cin >> choose;
		cin.ignore();

		if (choose >= 0 && choose <= 5) {
			return choose;
		}
	}
}

int View::menu_son_2_update()
{
	int choose = 0;

	while (true)
	{
		system("cls");

		cout <<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "+             M E N U _ U P D A T E _ R E A D E R           +" << endl
			<< "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "+1.  BY ID                                                  +" << endl
			<< "+2.  BY NAME                                                +" << endl
			<< "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "+0.  EXIT                                                   +" << endl
			<< "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "\n>> ";

		cin >> choose;
		cin.ignore();

		if (choose >= 0 && choose <= 5) {
			return choose;
		}
	}
}

int View::menu_son_2_find()
{
	int choose = 0;

	while (true)
	{
		system("cls");

		cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "+               M E N U _ F I N D _ R E A D E R             +" << endl
			<< "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "+1.  BY ID                                                  +" << endl
			<< "+2.  BY NAME                                                +" << endl
			<< "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "+0.  EXIT                                                   +" << endl
			<< "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "\n>> ";

		cin >> choose;
		cin.ignore();

		if (choose >= 0 && choose <= 5) {
			return choose;
		}
	}
}
