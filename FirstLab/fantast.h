#pragma once
#include "Libs.h"


class fantast final : public library
{
private:
	const char id = 2;
	string name;
	string surName;
	string patronymic;
	string* books;
	bool* bbook;
	int nBooks;
public:
	fantast();
	~fantast();
	fantast(string name, string surName, string patronymic, string* books, bool* bbook, int nBooks);
	fantast(const fantast& copy_hyper);
	fantast(int);

	void change() override;
	void print() override;
	int get_id() override;

	int write(std::ofstream& outFile);
	int read(std::ifstream& inFile);

	void setName(string name);
	void setSurname(string surname);
	void setPatronymic(string patronymic);
	void setBBook(bool*& bbook);
	void setBooks(string*& book, int& nBooks);

	string getName();
	string getSurname();
	string getPatronimyc();
	string* getBooks();
	bool* getBBook();
	int getNbooks();

	void editBooks(string*& books, int& nBooks, bool*& bbook);
	void addBook(string*& books, int& nBooks, bool*& bbook);
	void deleteBook(string*& books, int& nBooks, bool*& bbook, int ptr);
	void editBook(string*& books,bool*& bbook, int ptr);
};
