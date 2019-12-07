#pragma once

#include"Manager.h"

class Model
{
private:
	Manager mn;
public:

	Manager get_lib() { return this->mn; }
	void set_lib(Manager _lib) { this->mn = _lib; }

	Model() {}
	Model(const Manager& _lib) { this->mn = _lib; }

};

