#pragma once

#include"ReaderManagement.h"
#include"Library.h"

class Manager
{ 
private:
	Library lb;
	ReaderManagement rm;

public:

	// Sinh các getter và setter
	void set_lb(Library _lb) { this->lb = _lb; }
	void set_rm(ReaderManagement _rm) { this->rm = _rm; }

	Library get_lb() { return this->lb; }
	ReaderManagement get_rm() { return this->rm; }

	Manager() {};
	~Manager() {};
};

