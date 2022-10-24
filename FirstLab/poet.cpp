#include "libs.h"
#define DAY 0x1f
#define MONTH 0x1e0
#define YEAR 0xffe00

poet::poet() : name("name"), surName("surname"), patronymic("patronymic"), predate(0),postdate(1), books(nullptr), nBooks(0) { count++; }
poet::~poet() { count--; }
poet::poet(string name, string surName, string patronymic, int predate,int postdate, string* books, int nBooks)
{
	this->name = name;
	this->surName = surName;
	this->patronymic = patronymic;
	this->predate = predate;
	this->postdate = postdate;
	this->books = books;
	this->nBooks = nBooks;
	count++;
}
poet::poet(const poet& copy_hyper)
{
	name = copy_hyper.name;
	surName = copy_hyper.surName;
	patronymic = copy_hyper.patronymic;
	predate = copy_hyper.predate;
	postdate = copy_hyper.postdate;
	books = copy_hyper.books;
	nBooks = copy_hyper.nBooks;
	count++;
}
poet::poet(int) {
	count++;
		system("cls");
		cout << "Input name: ";
		cin >> name;
		cout << "Input surname: ";
		cin >> surName;
		cout << "Input patronymic: ";
		cin >> patronymic;
		bool flag=0;
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

}

void poet::setName(string name) {
	this->name = name;
}
void poet::setSurname(string surName) {
	this->surName = surName;
}
void poet::setPatronymic(string patronymic) {
	this->patronymic = patronymic;
}
void poet::setPreDate(int predate)
{ 
	this->predate = predate;
}
void poet::setPostDate(int postdate)
{
	this->postdate = postdate;
}
void poet::setBooks(string*& book,int& nBooks)
{
	this->books = books;
	this->nBooks = nBooks;
}

string poet::getName()
{
	return this->name;
}
string poet::getSurname()
{
	return this->surName;
}
string poet::getPatronimyc()
{
	return this->patronymic;
}
int poet::getPreDate()
{
	return this->predate;
}
int poet::getPostDate()
{
	return postdate;
}
string* poet::getBooks() {
	return books;
}
int poet::getNbooks() {
	return nBooks;
}
int poet::get_id() {
	return this->id;
}


void poet::print() {
	std::cout << "Name: " << setw(10) << name << "  |\tSurname: " << setw(10) << surName << "  |\tPatronymic: " << setw(10) << patronymic << "  |\tDates: ";
	dataflex(predate); std::cout << " - "; dataflex(postdate);
	std::cout<< "  |\tBooks: ";
	if (nBooks == 0)
		std::cout << "-" << endl;
	else
	{
		for (int i = 0; i < nBooks - 1;i++)
			std::cout << books[i] << ", ";
		std::cout << books[nBooks - 1] << endl;
	}

}


void poet::dataflex(int date)
{
	std::cout << setfill('0') << setw(2) << (date & DAY) << "."<< setfill('0') << setw(2) << ((date & MONTH) >> 5) << "." << ((date & YEAR) >> 9) << setfill(' ');
}
void poet::makeDate(int& date, int dd, int mm, int yy)
{
	date = dd + (mm<< 5) + (yy << 9);
}
bool poet::checkDate(int dd, int mm, int yy)
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


void poet::change() {
	
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
		case 1:cout<< setw(13) << "/\\"; break;
		case 2:cout << setw(38) << "/\\"; break;
		case 3:cout << setw(63) << "/\\"; break;
		case 4:cout << setw(91) << "/\\"; break;
		case 5:cout << setw(101) << "/\\"; break;
		case 6:cout << setw(130) << "/\\\n"; break;
			break;
		}
		k2 = _getch();
		switch (k2)
		{
		case 0x4B:	if (ptr - 1 >= 1) ptr--;	break;
			//printf("Left  on %s kbd\n", k2 ? "main" : "extended"); break;
		case 0x4D:if (ptr + 1 <= 6) ptr++; break;
			//printf("Right on %s kbd\n", k2 ? "main" : "extended"); break;

		case 13:
			if (ptr == 1) { string newname;cout << "\nInput new name: ";cin >> newname;setName(newname); }
			if (ptr == 2) { string newsurname;cout << "\nInput new surname: ";cin >> newsurname;setSurname(newsurname); }
			if (ptr == 3) { string newpatr;cout << "\nInput new patronymic: ";cin >> newpatr;setPatronymic(newpatr); }
			if (ptr == 4) { int dd, mm, yy;cout << "\nInput new date(dd mm yy): ";cin >> dd >> mm >> yy;try{if (checkDate(dd, mm, yy))makeDate(this->predate, dd, mm, yy); }catch (const char* ex) { cout << ex << endl;system("pause") ; }
			}
			if (ptr == 5) { int dd, mm, yy;cout << "\nInput new date(dd mm yy): ";cin >> dd >> mm >> yy;try { if (checkDate(dd, mm, yy))makeDate(this->postdate, dd, mm, yy); } catch (const char* ex) { cout << ex << endl; system("pause"); } }
			if (ptr == 6) editBooks(books, nBooks);
			break;
		case 27: 	flag = 0;break;
		}

		if (!flag)
			break;

	//	system("pause");
	}
}

void poet::editBooks(string*& books, int& nBooks)
{
	int choice = 0;
	if(books==nullptr)
	{
		cout << "Do you wanna add books?\n1. Yes 0 .No\n> ";
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
			cout << setw(ptr* 11) << "/\\    \n\n";
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
							editBook(books,  ptr - 1);
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
void poet::addBook(string*& books, int& nBooks) {
	string* newbooks = new string[nBooks + 1];
	nBooks++;
	for (int i = 0; i < nBooks-1;i++)
	{
		newbooks[i] = books[i];
	}
	system("cls");
	cout << "Input name of new book:\n > ";

	cin >> newbooks[nBooks - 1];
	delete[] books;
	books = newbooks;
}
void poet::deleteBook(string*& books, int& nBooks,int ptr) {
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

void poet::editBook(string*& books, int ptr) {
	system("cls");
	cout << "Input new name of book:\n > ";
	cin >> books[ptr];
}



int poet::write(std::ofstream& outFile)
{
	outFile << name <<"\n";
	outFile << surName << "\n";
	outFile << patronymic << "\n";
	outFile << predate << " ";
	outFile << postdate << " ";
	outFile << nBooks << "\n";
	for (int i = 0; i < nBooks;i++)
	{
		outFile << books[i] << "\n";
	}
	return 1;
}

int poet::read(std::ifstream& inFile)
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
			for (int i = 0; i < nBooks;i++)
			{
				inFile>> books[i];
			}
		}
		return 1;
}