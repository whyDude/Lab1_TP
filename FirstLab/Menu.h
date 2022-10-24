#pragma once
#include "libs.h"

class Menu
{
protected:
	Keeper list;
	library* libs;
	string redact;
	int exit = 1;
public:
	void main_menu();
	int show(int ptrUD, int ptrLR);
	void edit(int& ptrUD, int ptrLR);
	int showIN(int ptrUD, int ptrLR, int ptr);
	void add_new(char id);
	void exit_from_programm();

};