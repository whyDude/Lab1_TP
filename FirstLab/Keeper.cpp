#pragma warning( disable : 6386 )
#pragma warning( disable : 26451 )
#include "libs.h"

using namespace std;

Keeper::Keeper() : m_size(0), head(nullptr) {}

Keeper::Keeper(int size) : head(nullptr) { this->m_size = size; }

Keeper::~Keeper()
{
	if (head != NULL)
	{
		Elem* buffer;
		while (head->next != NULL)
		{
			buffer = head;
			head = head->next;
			buffer->m_data->~library();
			delete(buffer);
		}
		head->m_data->~library();
		delete(head);
	}
}

library* Keeper::operator[](const int index)
{
		int counter = 0;

		Elem* current = this->head;

		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->m_data;
			}
			current = current->next;
			counter++;
		}

}


int Keeper::get_size() { return m_size; }

void Keeper::insert(library* new_data)
{
	Elem* tmp;
	tmp = new Elem;
	if (m_size == 0)
	{
		tmp->m_data = new_data;
		tmp->next = 0;
		++m_size;
	}
	else
	{
		tmp->m_data = new_data;
		tmp->next = head;
		++m_size;
	}
	head = tmp;
}





void Keeper::save()
{
	sortID();
	ofstream outFile;
	string stra1 = ".\\data\\poet.txt";
	string stra2 = ".\\data\\roman.txt";
	string stra3 = ".\\data\\fantast.txt";
	int counter = 0, temp = 0;

	system("cls");
	for (int j = 0;j < 3;j++)
	{
		Elem* buffer = head;
		for (int i = 0;i < m_size;i++)
		{
			if (buffer->m_data->get_id() == j)
				counter++;
			buffer = buffer->next;
		}
		switch (j)
		{
		case 0:outFile.open(stra1, ios_base::out);break;
		case 1:outFile.open(stra2, ios_base::out);break;
		case 2:outFile.open(stra3, ios_base::out);
		}
		if (!outFile.is_open())
		{
			cout << "Error" << endl;
			return;
		}
		buffer = head;
		outFile << counter << "\n";
		for (int i = 0; i < temp;i++)
			buffer = buffer->next;
		for (int i = temp; i < temp + counter;i++) {
			buffer->m_data->write(outFile);
			buffer = buffer->next;
		}
		outFile.close();
		temp = temp + counter;
		counter = 0;
	}
}



void Keeper::load()
{
	int n;
	ifstream inFile;
	string stra1 = ".\\data\\poet.txt";
	string stra2 = ".\\data\\roman.txt";
	string stra3 = ".\\data\\fantast.txt";
	for (int j = 0;j < 3;j++)
	{
		library* buffer;
		switch (j)
		{
		case 0:
			inFile.open(stra1, ios_base::in);
			if (!inFile.is_open())
			{
				cout << "Error" << endl;
				return;
			}
			inFile >> n;
			for (int i = 0; i < n;i++) {
				poet* buf;
				buf = new poet();
				buf->read(inFile);
				buffer = buf;
				insert(buffer);
			}
			break;
		case 1:
			inFile.open(stra2, ios_base::in);
			if (!inFile.is_open())
			{
				cout << "Error" << endl;
				return;
			}
			inFile >> n;
			for (int i = 0; i < n;i++) {
				roman* buf;
				buf = new roman();
				buf->read(inFile);
				buffer = buf;
				insert(buffer);
			}
			break;
		case 2:
			inFile.open(stra3, ios_base::in);
			if (!inFile.is_open())
			{
				cout << "Error" << endl;
				return;
			}
			inFile >> n;
			for (int i = 0; i < n;i++) {
				fantast* buf;
				buf = new fantast();
				buf->read(inFile);
				buffer = buf;
				insert(buffer);
			}
			break;
		}
		
		inFile.close();
	}
	//delete(buffer);
}

Elem* Keeper::merge(Elem* a, Elem* b)
{
	Elem tmp;
	Elem* xhead = &tmp;
	Elem* c = xhead;
		// �������
		while ((a != 0) && (b != 0))
		{
			if (a->m_data->get_id() < b->m_data->get_id())
			{
				c->next = a;
				c = a;
				a = a->next;
			}
			else
			{
				c->next = b;
				c = b;
				b = b->next;
			}
		}
		// ������������ ���������� "�����"
		c->next = (a == 0) ? b : a;
		return xhead->next;
}
Elem* Keeper::mergeSort(Elem* c)
{
		if (c == 0 || c->next == 0) // ����������� ������
			return c;
		Elem* a = c; // a ������ ������ ������ �����
		Elem* b = c->next; // ��������� ���������

		while ((b != 0) && (b->next != 0))
		{
			c = c->next; // ������ ��������� ������ ���� ���
			b = b->next->next; // ������ - ��� ����
		}
		b = c->next; // � b �������� ������ ������ ����� ������
		c->next = 0; // ��������� ����� - ����� ������ ����� �����
		// ���������� �������� �� �� ��������� � ������� ����� ������

		return merge(mergeSort(a), mergeSort(b));
}

void Keeper::sortID()
{
	head = mergeSort(head);
}




void Keeper::pop_front()
{
	Elem* temp = head;
	head = head->next;
	delete temp;
	m_size--;

}
void Keeper::clear()
{
	while (m_size)
	{
		pop_front();
	}
}
void Keeper::remove(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Elem* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->next;
		}
		Elem* toDelete = previous->next;
		previous->next = toDelete->next;
		delete toDelete;
		m_size--;
	}

}

