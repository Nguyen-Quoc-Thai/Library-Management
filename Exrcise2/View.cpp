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

		cout << "\t\t\t\t_____________________________________________________________" << endl
			<< "\t\t\t\t|                           M E N U                         |" << endl
			<< "\t\t\t\t|-----------------------------------------------------------|" << endl
			<< "\t\t\t\t|1.  ADD BOOK                                               |" << endl
			<< "\t\t\t\t|2.  DELETE BOOK                                            |" << endl
			<< "\t\t\t\t|3.  UPDATE BOOK                                            |" << endl
			<< "\t\t\t\t|4.  FIND BOOK                                              |" << endl
			<< "\t\t\t\t|-----------------------------------------------------------|" << endl
			<< "\t\t\t\t|5.  ADD READER                                             |" << endl
			<< "\t\t\t\t|6.  DELETE READER                                          |" << endl
			<< "\t\t\t\t|7.  UPDATE READER                                          |" << endl
			<< "\t\t\t\t|8.  FIND READER                                            |" << endl
			<< "\t\t\t\t|-----------------------------------------------------------|" << endl
			<< "\t\t\t\t|9.  CREATE BORROW BILL                                     |" << endl
			<< "\t\t\t\t|10. CREATE RETURN BILL                                     |" << endl
			<< "\t\t\t\t|11. CREATE ALL BORROW BILL                                 |" << endl
			<< "\t\t\t\t|12. CREATE ALL RETURN BILL                                 |" << endl
			<< "\t\t\t\t|-----------------------------------------------------------|" << endl
			<< "\t\t\t\t|13. LIST READER BORROW OVERDUE                             |" << endl
			<< "\t\t\t\t|-----------------------------------------------------------|" << endl
			<< "\t\t\t\t|0.  EXIT                                                   |" << endl
			<< "\t\t\t\t|___________________________________________________________|" << endl
			<< "\n\t\t\t\t>> ";

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

		cout << "\t\t\t\t_____________________________________________________________" << endl
			<< "\t\t\t\t|               M E N U _ D E L E T E _ B O O K             |" << endl
			<< "\t\t\t\t|-----------------------------------------------------------|" << endl
			<< "\t\t\t\t|1.  BY ID                                                  |" << endl
			<< "\t\t\t\t|2.  BY NAME                                                |" << endl
			<< "\t\t\t\t|3.  BY AUTHOR                                              |" << endl
			<< "\t\t\t\t|4.  BY PUBLISHER                                           |" << endl
			<< "\t\t\t\t|5.  BY PRICE                                               |" << endl
			<< "\t\t\t\t|-----------------------------------------------------------|" << endl
			<< "\t\t\t\t|0.  EXIT                                                   |" << endl
			<< "\t\t\t\t|___________________________________________________________|" << endl
			<< "\n\t\t\t\t>> ";

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

		cout << "\t\t\t\t_____________________________________________________________" << endl
			<< "\t\t\t\t|               M E N U _ U P D A T E _ B O O K             |" << endl
			<< "\t\t\t\t|-----------------------------------------------------------|" << endl
			<< "\t\t\t\t|1.  BY ID                                                  |" << endl
			<< "\t\t\t\t|2.  BY NAME                                                |" << endl
			<< "\t\t\t\t|3.  BY AUTHOR                                              |" << endl
			<< "\t\t\t\t|4.  BY PUBLISHER                                           |" << endl
			<< "\t\t\t\t|5.  BY PRICE                                               |" << endl
			<< "\t\t\t\t|-----------------------------------------------------------|" << endl
			<< "\t\t\t\t|0.  EXIT                                                   |" << endl
			<< "\t\t\t\t|___________________________________________________________|" << endl
			<< "\n\t\t\t\t>> ";

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

		cout << "\t\t\t\t_____________________________________________________________" << endl
			<< "\t\t\t\t|               M E N U _ F I N D _ B O O K                 |" << endl
			<< "\t\t\t\t|-----------------------------------------------------------|" << endl
			<< "\t\t\t\t|1.  BY ID                                                  |" << endl
			<< "\t\t\t\t|2.  BY NAME                                                |" << endl
			<< "\t\t\t\t|3.  BY AUTHOR                                              |" << endl
			<< "\t\t\t\t|4.  BY PUBLISHER                                           |" << endl
			<< "\t\t\t\t|5.  BY PRICE                                               |" << endl
			<< "\t\t\t\t|-----------------------------------------------------------|" << endl
			<< "\t\t\t\t|0.  EXIT                                                   |" << endl
			<< "\t\t\t\t|___________________________________________________________|" << endl
			<< "\n\t\t\t\t>> ";

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

		cout << "\t\t\t\t_____________________________________________________________" << endl
			<< "\t\t\t\t|             M E N U _ D E L E T E _ R E A D E R           |" << endl
			<< "\t\t\t\t|-----------------------------------------------------------|" << endl
			<< "\t\t\t\t|1.  BY ID                                                  |" << endl
			<< "\t\t\t\t|2.  BY NAME                                                |" << endl
			<< "\t\t\t\t|___________________________________________________________|" << endl
			<< "\n\t\t\t\t>> ";

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

		cout <<"\t\t\t\t_____________________________________________________________" << endl
			<< "\t\t\t\t|             M E N U _ U P D A T E _ R E A D E R           |" << endl
			<< "\t\t\t\t|-----------------------------------------------------------|" << endl
			<< "\t\t\t\t|1.  BY ID                                                  |" << endl
			<< "\t\t\t\t|2.  BY NAME                                                |" << endl
			<< "\t\t\t\t|-----------------------------------------------------------|" << endl
			<< "\t\t\t\t|0.  EXIT                                                   |" << endl
			<< "\t\t\t\t|___________________________________________________________|" << endl
			<< "\n\t\t\t\t>> ";

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

		cout << "\t\t\t\t_____________________________________________________________" << endl
			<< "\t\t\t\t|               M E N U _ F I N D _ R E A D E R             |" << endl
			<< "\t\t\t\t|-----------------------------------------------------------|" << endl
			<< "\t\t\t\t|1.  BY ID                                                  |" << endl
			<< "\t\t\t\t|2.  BY NAME                                                |" << endl
			<< "\t\t\t\t|-----------------------------------------------------------|" << endl
			<< "\t\t\t\t|0.  EXIT                                                   |" << endl
			<< "\t\t\t\t|___________________________________________________________|" << endl
			<< "\n\t\t\t\t>> ";

		cin >> choose;
		cin.ignore();

		if (choose >= 0 && choose <= 5) {
			return choose;
		}
	}
}
