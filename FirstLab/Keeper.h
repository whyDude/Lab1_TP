#pragma once
#include "libs.h"

class Keeper
{
private:
	int m_size = 0;
	Elem* head = NULL;
public:
	Keeper();
	Keeper(int size);
	~Keeper();

	library* operator[] (int index);

	int get_size();
	void insert(library* n_data); 
	void save();
	void load();
	Elem* merge(Elem* a, Elem* b);
	Elem* mergeSort(Elem* c);
	void sortID();

	void pop_front();
	void clear();
	void remove(int index);
};