#include "libs.h"


fantast::fantast() : name("name"), surName("surname"), patronymic("patronymic"), books(nullptr), bbook(nullptr), nBooks(0){ count++; }
fantast::~fantast() { count--; }
fantast::fantast(string name, string surName, string patronymic, string* books, bool* bbook, int nBooks)
{
	this->name = name;
	this->surName = surName;
	this->patronymic = patronymic;
	this->books = books;
	this->bbook = bbook;
	this->nBooks = nBooks;
	count++;
}
fantast::fantast(const fantast& copy_hyper)
{
	name = copy_hyper.name;
	surName = copy_hyper.surName;
	patronymic = copy_hyper.patronymic;
	books = copy_hyper.books;
	bbook = copy_hyper.bbook;
	nBooks = copy_hyper.nBooks;
	count++;
}
fantast::fantast(int)
{
	count++;
	system("cls");
	cout << "Input name: ";
	cin >> name;
	cout << "Input surname: ";
	cin >> surName;
	cout << "Input patronymic: ";
	cin >> patronymic;
	cout << "Input number of boooks: ";
	cin >> nBooks;
	if (nBooks) {
		string* newbooks = new string[nBooks];
		bool* newbbook = new bool[nBooks];
		bbook = newbbook;
		books = newbooks;
		for (int i = 0; i < nBooks;i++)
		{
			cout << "Name of " << i + 1 << " book & film(0/1): ";
			cin >> books[i];
			cin >> bbook[i];
		}
	}
	else {
		books = nullptr;
		bbook = nullptr;
	}
	

}


void fantast::setName(string name) {
	this->name = name;
}
void fantast::setSurname(string surName) {
	this->surName = surName;
}
void fantast::setPatronymic(string patronymic) {
	this->patronymic = patronymic;
}
void fantast::setBooks(string*& book, int& nBooks)
{
	this->books = books;
	this->nBooks = nBooks;
}
void fantast::setBBook(bool*& bbook)
{
	this->bbook = bbook;
}

string fantast::getName()
{
	return this->name;
}
string fantast::getSurname()
{
	return this->surName;
}
string fantast::getPatronimyc()
{
	return this->patronymic;
}
string* fantast::getBooks() {
	return books;
}
bool* fantast::getBBook()
{
	return this->bbook;
}
int fantast::getNbooks() {
	return nBooks;
}
int fantast::get_id() {
	return this->id;
}


void fantast::print() {
	std::cout<< "Name: " <<setw(10) <<name << "  |\tSurname: " << setw(10) << surName << "  |\tPatronymic: " << setw(10) << patronymic << "  |\tBooks[film]: ";
	if (books == nullptr)
		std::cout << "-" << std::endl;
	else
	{
		for (int i = 0; i < nBooks - 1;i++)
		{
			std::cout << books[i] << "[" << (bbook[i] == 1 ? "yes" : "no") << "]" << ", ";
		}
			

		std::cout << books[nBooks - 1] << "[" << (bbook[nBooks-1] == 1 ? "yes" : "no") << "]" << endl;
	}
}







void fantast::change() {
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
		case 4:cout << setw(91) << "/\\\n"; break;
		}
		k2 = _getch();
		switch (k2)
		{
		case 0x4B:	if (ptr - 1 >= 1) ptr--;	break;
			//printf("Left  on %s kbd\n", k2 ? "main" : "extended"); break;
		case 0x4D:if (ptr + 1 <= 4) ptr++; break;
			//printf("Right on %s kbd\n", k2 ? "main" : "extended"); break;

		case 13:
			if (ptr == 1) { string newname;cout << "\nInput new name: ";cin >> newname;setName(newname); }
			if (ptr == 2) { string newsurname;cout << "\nInput new surname: ";cin >> newsurname;setSurname(newsurname); }
			if (ptr == 3) { string newpatr;cout << "\nInput new patronymic: ";cin >> newpatr;setPatronymic(newpatr); }
			if (ptr == 4) editBooks(books, nBooks, bbook);
			break;
		case 27: 	flag = 0;break;
		}

		if (!flag)
			break;

		//	system("pause");
	}

}

void fantast::editBooks(string*& books, int& nBooks, bool*& bbook)
{
	int choice = 0;
	if (books == nullptr)
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
			bool* newbbook = new bool[choice];
			nBooks = choice;
			bbook = newbbook;
			books = newbooks;
			for (int i = 0; i < choice;i++)
			{
				cout << "Name of " << i + 1 << " book & film(0/1): ";
				cin >> books[i];
				cin >> bbook[i];
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
			std::cout << "  |\tBooks[film]:\n ";
			for (int i = 0; i < nBooks - 1;i++)
				std::cout << setw(10) << books[i] << "[" << (bbook[i] == 1 ? "yes" : "no ") << "]" << ", ";
			std::cout <<setw(10)<< books[nBooks - 1] << "[" << (bbook[nBooks - 1] == 1 ? "yes" : "no") << "]" << endl;
			cout << setw(ptr * 16) << "/\\    \n\n";
			cout << setw(10) << "<->   " << setw(10) << "'+'    " << setw(10) << "enter" << endl << setw(10) << "move  " << setw(10) << "add   ";
			k2 = _getch();
			switch (k2)
			{
			case 0x4B:	if (ptr - 1 >= 1) ptr--;	break;
				//printf("Left  on %s kbd\n", k2 ? "main" : "extended"); break;
			case 0x4D:if (ptr + 1 <= nBooks) ptr++; break;
				//printf("Right on %s kbd\n", k2 ? "main" : "extended"); break;
			case 43:
				addBook(books, nBooks,bbook);
				break;
			case 13:

				while (flag1)
				{
					system("cls");
					std::cout << "  |\tBooks[film]:\n ";
					for (int i = 0; i < nBooks - 1;i++)
						std::cout << setw(10) << books[i] << "[" << (bbook[i] == 1 ? "yes" : "no ") << "]" << ", ";
					std::cout <<setw(10)<< books[nBooks - 1] << "[" << (bbook[nBooks - 1] == 1 ? "yes" : "no") << "]" << endl;
					cout << setw(ptr * 16) << "/\\    \n";
					cout << setw(ptr * 16) << (ptrUD == 1 ? "> edit  \n" : "  edit \n ");
					cout << setw(ptr * 16) << (ptrUD == 2 ? "> delete  \n" : "  delete \n ");

					k3 = _getch();

					switch (k3)
					{
					case 0x48:	if (ptrUD - 1 >= 1)ptrUD--;break;
						//printf("Up    on %s kbd\n", k1 ? "main" : "extended");
					case 0x50: if (ptrUD + 1 <= 2)ptrUD++;break;
						//printf("Down  on %s kbd\n", k1 ? "main" : "extended"); break;
					case 13:
						if (ptrUD == 2) {
							deleteBook(books, nBooks,bbook, ptr - 1);
						}
						else
						{
							editBook(books,bbook, ptr - 1);
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
void fantast::addBook(string*& books, int& nBooks, bool*& bbook) {
	string* newbooks = new string[nBooks + 1];
	bool* newbbook = new bool[nBooks + 1];
	nBooks++;
	for (int i = 0; i < nBooks - 1;i++)
	{
		newbooks[i] = books[i];
		newbbook[i] = bbook[i];
	}
	system("cls");
	cout << "Input name of new book & film(0/1):\n > ";

	cin >> newbooks[nBooks - 1];
	cin >> newbbook[nBooks - 1];
	delete[] books;
	delete[] bbook;
	books = newbooks;
	bbook = newbbook;
}
void fantast::deleteBook(string*& books, int& nBooks,bool*& bbook, int ptr) {
	if (nBooks - 1 == 0)
	{
		books = nullptr;
		bbook = nullptr;
		nBooks = 0;
		return;
	}
	for (int i = ptr; i < nBooks - 1;i++)
	{
		books[i] = books[i + 1];
		bbook[i] = bbook[i + 1];
	}
	string* newbooks = new string[nBooks - 1];
	bool* newbbook = new bool[nBooks - 1];
	nBooks--;
	for (int i = 0; i < nBooks;i++)
	{
		newbooks[i] = books[i];
		newbbook[i] = bbook[i];
	}
	delete[] books;
	delete[] bbook;
	bbook = newbbook;
	books = newbooks;
}

void fantast::editBook(string*& books, bool*& bbook, int ptr) {
	system("cls");
	cout << "Input new name of book & film(0/1):\n > ";
	cin >> books[ptr];
	cin >> bbook[ptr];
}

int fantast::write(std::ofstream& outFile)
{
	outFile << name << "\n";
	outFile << surName << "\n";
	outFile << patronymic << "\n";
	outFile << nBooks << "\n";
	for (int i = 0; i < nBooks;i++)
	{
		outFile << books[i] << "\n";
		outFile << bbook[i] << "\n";
	}
	return 1;
}


int fantast::read(std::ifstream& inFile)
{
	inFile >> name;
	inFile >> surName;
	inFile >> patronymic;
	inFile >> nBooks;
	if (nBooks) {
		string* newbooks = new string[nBooks];
		bool* newbbook = new bool[nBooks];
		bbook = newbbook;
		books = newbooks;
		for (int i = 0;i < nBooks;i++)
		{
			inFile >> books[i];
			inFile >> bbook[i];
		}
	}
	return 1;
}