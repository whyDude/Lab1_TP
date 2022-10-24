#include "libs.h"
#define DAY 0x1f
#define MONTH 0x1e0
#define YEAR 0xffe00

roman::roman() : name("name"), surName("surname"), patronymic("patronymic"), predate(0), postdate(1), books(nullptr), nBooks(0),bio("-") { count++; }
roman::~roman() { count--; }
roman::roman(string name, string surName, string patronymic, int predate, int postdate, string* books, int nBooks, string bio)
{
	this->name = name;
	this->surName = surName;
	this->patronymic = patronymic;
	this->predate = predate;
	this->postdate = postdate;
	this->books = books;
	this->nBooks = nBooks;
	this->bio = bio;
	count++;
}
roman::roman(const roman& copy_hyper)
{
	name = copy_hyper.name;
	surName = copy_hyper.surName;
	patronymic = copy_hyper.patronymic;
	predate = copy_hyper.predate;
	postdate = copy_hyper.postdate;
	books = copy_hyper.books;
	nBooks = copy_hyper.nBooks;
	bio = copy_hyper.bio;
	count++;
}
roman::roman(int) {
	count++;
	system("cls");
	cout << "Input name: ";
	cin >> name;
	cout << "Input surname: ";
	cin >> surName;
	cout << "Input patronymic: ";
	cin >> patronymic;
	bool flag = 0;
	int dd, mm, yy;
	while (!flag) {
		flag = 1;
		cout << "Input predate(dd mm yy): ";cin >> dd >> mm >> yy;try { if (checkDate(dd, mm, yy))makeDate(this->predate, dd, mm, yy); }
		catch (const char* ex) { cout << ex << endl; flag = 0;system("pause"); }
	}
	flag = 0;
	while (!flag)
	{
		flag = 1;
		cout << "Input postdate(dd mm yy): ";cin >> dd >> mm >> yy;try { if (checkDate(dd, mm, yy))makeDate(this->postdate, dd, mm, yy); }
		catch (const char* ex) { cout << ex << endl; flag = 0;system("pause"); }
	}
	cout << "Input number of boooks: ";
	cin >> nBooks;
	if (nBooks) {
		string* newbooks = new string[nBooks];
		books = newbooks;
		for (int i = 0; i < nBooks;i++)
		{
			cout << "Name of " << i + 1 << " book: ";
			cin >> books[i];
		}
	}
	else
		books = nullptr;
	cout << "Input bio: ";
	cin >> bio;
}





void roman::setName(string name) {
	this->name = name;
}
void roman::setSurname(string surName) {
	this->surName = surName;
}
void roman::setPatronymic(string patronymic) {
	this->patronymic = patronymic;
}
void roman::setPreDate(int predate)
{
	this->predate = predate;
}
void roman::setPostDate(int postdate)
{
	this->postdate = postdate;
}
void roman::setBooks(string*& book, int& nBooks)
{
	this->books = books;
	this->nBooks = nBooks;
}
void roman::setBio(string bio)
{
	this->bio = bio;
}

string roman::getName()
{
	return this->name;
}
string roman::getSurname()
{
	return this->surName;
}
string roman::getPatronimyc()
{
	return this->patronymic;
}
int roman::getPreDate()
{
	return this->predate;
}
int roman::getPostDate()
{
	return postdate;
}
string* roman::getBooks() {
	return books;
}
int roman::getNbooks() {
	return nBooks;
}
int roman::get_id() {
	return this->id;
}
string roman::getBio()
{
	return this->bio;
}

void roman::print() {
	std::cout << "Name: " << setw(10) << name << "  |\tSurname: " << setw(10) << surName << "  |\tPatronymic: " << setw(10) << patronymic << "  |\tDates: ";
	dataflex(predate); std::cout << " - "; dataflex(postdate);
	std::cout << "  |\tBooks: ";
	if (books == nullptr)
		std::cout << "-";
	else
	{
		for (int i = 0; i < nBooks - 1;i++)
			std::cout << books[i] << ", ";
		std::cout << books[nBooks - 1];
	}
	std::cout << "\tBiography: " << bio << endl;
}


void roman::dataflex(int date)
{
	std::cout << setfill('0') << setw(2) << (date & DAY) << "." << setfill('0') << setw(2) << ((date & MONTH) >> 5) << "." << ((date & YEAR) >> 9) << setfill(' ');
}
void roman::makeDate(int& date, int dd, int mm, int yy)
{
	date = dd + (mm<< 5) + (yy << 9);
}
bool roman::checkDate(int dd, int mm, int yy)
{
	bool check=0;
	if (mm < 13 && mm>0)
		if (mm < 7)
			for (int i = 0;i < mm;i++)
				check ^= 1;
		else
			for (int i = 7;i < mm;i++)
				check ^= 1;
	else
		throw "Incorrect num of monsth or full date";
	if (dd < 1)
		throw "Month should got more 0 days or full date is incorrect";
	else
		if (check)
		{
			if (dd > 31)
				throw "In this month max 31 days";
		}
		else
			if (dd > 30)
				throw "In this month max 30 days";
	if(yy<0)
		throw "Years must be more than 0";
	else if(yy>2047)
		throw "Years must be less then 2047";
	return 1;
}





void roman::change() {
	bool flag = 1;
	int  k2;
	int ptr = 1;

	while (flag)
	{
		system("cls");
		cout << "What do u wanna edit?\n";
		print();
		switch (ptr)
		{
		case 1:cout << setw(13) << "/\\"; break;
		case 2:cout << setw(38) << "/\\"; break;
		case 3:cout << setw(63) << "/\\"; break;
		case 4:cout << setw(91) << "/\\"; break;
		case 5:cout << setw(101) << "/\\"; break;
		case 6:cout << setw(125) << "/\\"; break;
		case 7:cout << setw(145) << "/\\\n"; break;
		}
		k2 = _getch();
		switch (k2)
		{
		case 0x4B:	if (ptr - 1 >= 1) ptr--;	break;
			//printf("Left  on %s kbd\n", k2 ? "main" : "extended"); break;
		case 0x4D:if (ptr + 1 <= 7) ptr++; break;
			//printf("Right on %s kbd\n", k2 ? "main" : "extended"); break;

		case 13:
			if (ptr == 1) { string newname;cout << "\nInput new name: ";cin >> newname;setName(newname); }
			if (ptr == 2) { string newsurname;cout << "\nInput new surname: ";cin >> newsurname;setSurname(newsurname); }
			if (ptr == 3) { string newpatr;cout << "\nInput new patronymic: ";cin >> newpatr;setPatronymic(newpatr); }
			if (ptr == 4) {
				int dd, mm, yy;cout << "\nInput new date(dd mm yy): ";cin >> dd >> mm >> yy;try { if (checkDate(dd, mm, yy))makeDate(this->predate, dd, mm, yy); }
				catch (const char* ex) { cout << ex << endl;system("pause"); }
			}
			if (ptr == 5) { int dd, mm, yy;cout << "\nInput new date(dd mm yy): ";cin >> dd >> mm >> yy;try { if (checkDate(dd, mm, yy))makeDate(this->postdate, dd, mm, yy); } catch (const char* ex) { cout << ex << endl; system("pause"); } }
			if (ptr == 6) editBooks(books, nBooks);
			if (ptr == 7) editBio(bio);
			break;
		case 27: 	flag = 0;break;
		}

		if (!flag)
			break;

		//	system("pause");
	}
}

void roman::editBooks(string*& books, int& nBooks)
{
	int choice = 0;
	if (books == nullptr)
	{
		cout << "\nDo you wanna add books?\n1. Yes 0 .No\n> ";
		cin >> choice;
		if (!choice)
			return;
		else
		{

			cout << "How many books do u wanna add?\n> ";
			cin >> choice;
			string* newbooks = new string[choice];
			nBooks = choice;
			books = newbooks;
			for (int i = 0; i < choice;i++)
			{
				cout << "Name of " << i + 1 << " book: ";
				cin >> books[i];
			}

		}
	}
	else
	{

		bool flag = 1;
		int  k2;
		int ptr = 1;
		bool flag1 = 1;
		int  k3;
		int ptrUD = 1;
		while (flag)
		{
			flag1 = 1;
			system("cls");
			std::cout << "  |\tBooks:\n ";
			for (int i = 0; i < nBooks - 1;i++)
				std::cout << setw(10) << books[i] << ",";
			std::cout << setw(10) << books[nBooks - 1] << endl;
			cout << setw(ptr * 11) << "/\\    \n\n";
			cout << setw(10) << "<->   " << setw(10) << "'+'    " << setw(10) << "enter" << endl << setw(10) << "move  " << setw(10) << "add   ";
			k2 = _getch();
			switch (k2)
			{
			case 0x4B:	if (ptr - 1 >= 1) ptr--;	break;
				//printf("Left  on %s kbd\n", k2 ? "main" : "extended"); break;
			case 0x4D:if (ptr + 1 <= nBooks) ptr++; break;
				//printf("Right on %s kbd\n", k2 ? "main" : "extended"); break;
			case 43:
				addBook(books, nBooks);
				break;
			case 13:

				while (flag1)
				{
					system("cls");
					std::cout << "  |\tBooks:\n ";
					for (int i = 0; i < nBooks - 1;i++)
						std::cout << setw(10) << books[i] << ",";
					std::cout << setw(10) << books[nBooks - 1] << endl;
					cout << setw(ptr * 11) << "/\\    \n";
					cout << setw(ptr * 11) << (ptrUD == 1 ? "> edit  \n" : "  edit \n ");
					cout << setw(ptr * 11) << (ptrUD == 2 ? "> delete  \n" : "  delete \n ");



					k3 = _getch();

					switch (k3)
					{
					case 0x48:	if (ptrUD - 1 >= 1)ptrUD--;break;
						//printf("Up    on %s kbd\n", k1 ? "main" : "extended");
					case 0x50: if (ptrUD + 1 <= 2)ptrUD++;break;
						//printf("Down  on %s kbd\n", k1 ? "main" : "extended"); break;
					case 13:
						if (ptrUD == 2) {
							deleteBook(books, nBooks, ptr - 1);
						}
						else
						{
							editBook(books, ptr - 1);
						}
						flag1 = 0;
						flag = 0;
						break;
					case 27: 	flag1 = 0;break;


					}
				}

				break;
			case 27: 	flag = 0;break;
			}

			if (!flag)
				break;

		}
	}




}
void roman::addBook(string*& books, int& nBooks) {
	string* newbooks = new string[nBooks + 1];
	nBooks++;
	for (int i = 0; i < nBooks - 1;i++)
	{
		newbooks[i] = books[i];
	}
	system("cls");
	cout << "Input name of new book:\n > ";

	cin >> newbooks[nBooks - 1];
	delete[] books;
	books = newbooks;
}
void roman::deleteBook(string*& books, int& nBooks, int ptr) {
	if (nBooks - 1 == 0)
	{
		books = nullptr;
		nBooks = 0;
		return;
	}
	for (int i = ptr; i < nBooks - 1;i++)
	{
		books[i] = books[i + 1];
	}
	string* newbooks = new string[nBooks - 1];
	nBooks--;
	for (int i = 0; i < nBooks;i++)
	{
		newbooks[i] = books[i];
	}
	delete[] books;
	books = newbooks;
}

void roman::editBook(string*& books, int ptr) {
	system("cls");
	cout << "Input new name of book:\n > ";
	cin >> books[ptr];
}

void roman::editBio(string& bio)
{
	system("cls");
	cout << "Input new bio:\n > ";
	cin >> bio;
}

int roman::write(std::ofstream& outFile)
{
	outFile << name << "\n";
	outFile << surName << "\n";
	outFile << patronymic << "\n";
	outFile << predate << " ";
	outFile << postdate << " ";
	outFile << nBooks << "\n";
	for (int i = 0; i < nBooks;i++)
	{
		outFile << books[i] << "\n";
	}
	outFile << bio << "\n";
	return 1;
}

int roman::read(std::ifstream& inFile)
{
	inFile >> name;
	inFile >> surName;
	inFile >> patronymic;
	inFile >> predate;
	inFile >> postdate;
	inFile >> nBooks;
	if (nBooks) {
		string* newbooks = new string[nBooks];
		books = newbooks;
		for (int i = 0;i < nBooks;i++)
			inFile >> books[i];
	}
	inFile >> bio;
	return 1;
}