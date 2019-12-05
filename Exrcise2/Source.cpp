#include"Book.h"
#include"EnglishBook.h"
#include"VietnamBook.h"
#include"Library.h"
#include"ReaderManagement.h"

#include<iostream>
using namespace std;


int main()
{
	/*Library lb;

	lb.load("library-mana.txt");

	lb.display();*/

	Reader* rd1 = new Reader();
	//Reader* rd2 = new Reader();

	cout << "RD1" << endl;
	rd1->input();
	rd1->print_bill_return(rd1->get_id());

	//cout << "RD2" << endl;
	//rd2->input();

	//ReaderManagement rm;

	//rm.add(rd1);
	//rm.add(rd2);

	//rm.display();
	//rm.save("reader-mana.txt");

	system("pause");
	return EXIT_SUCCESS;
}