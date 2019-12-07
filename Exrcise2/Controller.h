#pragma once

#include"Model.h"
#include"View.h"

class Controller
{
private:
	Model model;
	View view;

public:
	Controller(const Model& _model, const View& _view) { this->model = _model; this->view = _view; }

	void set_model(const Model& _model) { this->model = _model; }
	void set_view(const View& _view) { this->view = _view; }

	void onload();
};

