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

	Book *c = new VietnamBook();
	Book *b = new EnglishBook();

	c->input();
	b->input();

	lb.add(c);
	lb.add(b);

	lb.save("reader-mana.txt");*/

	Reader* rd1 = new Reader();
	Reader* rd2 = new Reader();

	rd1->input();
	rd2->input();

	ReaderManagement rm;

	rm.add(rd1);
	rm.add(rd2);

	rm.display();
	rm.save("reader-mana.txt");

	system("pause");
	return EXIT_SUCCESS;
}