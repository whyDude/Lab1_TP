#pragma once
class poet final : public library 
{
private:
	const char id=0;
	string name;
	string surName;
	string patronymic;
	int predate;
	int postdate;// будет весело
	int nBooks = 0;
	string* books;
public:
	poet();
	~poet();
	poet(int);
	poet(string name, string surName, string patronymic, int predate,int postdate, string* books,int nBooks);
	poet(const poet& copy_hyper);

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
	void setBooks(string*& books, int& nBooks);

	string getName();
	string getSurname();
	string getPatronimyc();
	int getPreDate();
	int getPostDate();
	string* getBooks();
	int getNbooks();

	void dataflex(int data);
	void makeDate(int& date,int dd, int mm, int yy);
	bool checkDate(int dd, int mm, int yy);
	void editBooks(string*& books, int& nBooks);
	void addBook(string*& books, int& nBooks);
	void deleteBook(string*& books, int& nBooks,int ptr);
	void editBook(string*& books, int ptr);
};

