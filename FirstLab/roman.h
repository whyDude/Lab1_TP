#pragma once
#include "Libs.h"

class roman final : public library
{
private:
	const char id = 1;
	string name;
	string surName;
	string patronymic;
	int predate;
	int postdate;// будет весело
	string* books;
	int nBooks;
	string bio;
public:
	roman();
	~roman();
	roman(int);
	roman(string name, string surName, string patronymic, int predate, int postdate, string* books, int nBooks, string bio);
	roman(const roman& copy_hyper);

	void change() override;
	void print() override;
	int get_id() override;

	int write(std::ofstream& outFile);
	int read(std::ifstream& inFile);

	void setName(string name);
	void setSurname(string surname);
	void setPatronymic(string patronymic);
	void setPreDate(int predate);
	void setPostDate(int postdate);
	void setBio(string bio);
	void setBooks(string*& books, int& nBooks);

	string getBio();
	string getName();
	string getSurname();
	string getPatronimyc();
	int getPreDate();
	int getPostDate();
	string* getBooks();
	int getNbooks();

	void dataflex(int data);
	void makeDate(int& date, int dd, int mm, int yy);
	bool checkDate(int dd, int mm, int yy);
	void editBooks(string*& books, int& nBooks);
	void addBook(string*& books, int& nBooks);
	void deleteBook(string*& books, int& nBooks, int ptr);
	void editBook(string*& books, int ptr);
	void editBio(string &bio);
};
