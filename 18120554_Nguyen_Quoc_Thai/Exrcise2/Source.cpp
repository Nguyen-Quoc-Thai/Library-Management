#include"Book.h"
#include"EnglishBook.h"
#include"VietnamBook.h"
#include"Library.h"
#include"ReaderManagement.h"

#include<iostream>
using namespace std;


int main()
{
	Library lb;

	Book *c = new VietnamBook();
	Book *b = new EnglishBook();

	c->input();
	b->input();

	lb.add(c);
	lb.add(b);

	lb.save("output.txt");

	/*Reader* rd1 = new Reader();

	rd1->input();

	rd1->print_bill_borrow();
	rd1->print_bill_return();

	cout << "\nDISPLAY\n";
	rd1->display();*/

	system("pause");
	return EXIT_SUCCESS;
}