#pragma once
#include<iostream>
#include<iomanip>
#include <stdio.h>
#include <conio.h>
#include <fstream>
using namespace std;



class library {
public:
	static int count;
	library() {};
	~library() {};
	virtual void print() = 0;
	virtual void change() = 0;
	virtual int  write(std::ofstream& outFile) = 0;
	virtual int  read(std::ifstream& inFile) = 0;
	virtual int get_id() = 0;
};

typedef struct Elem
{
	library* m_data;
	Elem* next;
} Elem;