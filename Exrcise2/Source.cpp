#include"Manager.h"

#include"Model.h"
#include"View.h"
#include"Controller.h"

#include<iostream>
using namespace std;


int main()
{
	Manager mn;

	Model model(mn);
	View view(model);
	Controller controller(model, view);

	controller.onload();

	return EXIT_SUCCESS;
}