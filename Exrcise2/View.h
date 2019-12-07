#pragma once

#include"Model.h"

class View
{
private:
	Model model;

public:

	View() {}
	View(const Model& _model) { this->model = _model; }

	void set_model(const Model& _model) { this->model = _model; }
	Model get_model() { return this->model; }

	int render();

	int main_menu();

private:

	int menu_son_1_delete();
	int menu_son_1_update();
	int menu_son_1_find();

	int menu_son_2_delete();
	int menu_son_2_update();
	int menu_son_2_find();
};

