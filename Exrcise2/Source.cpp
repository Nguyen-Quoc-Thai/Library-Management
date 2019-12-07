#include"Manager.h"

#include"Model.h"
#include"View.h"
#include"Controller.h"

#include<iostream>
using namespace std;


int main()
{
	//Library lb;

	//Book* b1 = new VietnamBook();
	//Book* b2 = new Book();
	//Book* b3 = new Book();

	//b1->input();
	////b2->input();
	////b3->input();

	//lb.add(b1);
	////lb.add(b2);
	////lb.add(b3);

	//Reader* rd1 = new Reader();
	//Reader* rd2 = new Reader();

	//cout << "RD1" << endl;
	//rd1->input();
	//rd1->print_bill_return(rd1->get_id());

	//cout << "RD2" << endl;
	//rd2->input();
	//rd2->print_bill_return(rd2->get_id());

	//ReaderManagement rm;

	//rm.add(rd1);
	//rm.add(rd2);

	//rm.print_all_bill_borrow("All-Borrow-Management");
	//rm.print_all_bill_return("All-Return-Management");

	//lb.save("Library-Mana.txt");

	////rm.add(rd1);
	////rm.add(rd2);

	////rm.display();
	////rm.save("reader-mana.txt");

	Manager mn;

	Model model(mn);

	View view(model);

	Controller controller(model, view);

	controller.onload();

	return EXIT_SUCCESS;
}