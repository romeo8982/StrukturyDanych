#include "stdafx.h"
#include "DoubleList.h"


void DoubleList::fill_up()
{
	tail = head = NULL;
	size = 0;
	int key;
	string name;
	cout << "Podaj nazwe pliku: " << endl;
	cin >> name;
	ifstream file;
	file.open(name.c_str());
	if (file.good())
	{
		for (int i = 0;; i++)
		{
			if (file.good())
			{
				if (i == 0)
				{
					file >> size;
				}
				else
				{
					if (tail)
					{
						file >> key;
						tail->next = new Link(key);
						tail->next->prev = tail;
						tail = tail->next;	
					}
					else
					{
						file >> key;
						head = new Link(key);
						tail = head;
						
					}
				}
			}
			else break;
		}
	}
	file.close();
}

void DoubleList::clear()
{
	int key;
	cout << "Podaj jaka liczbe chcesz usunac: ";
	cin >> key;
	Link *help = head;
	while (help)
	{
		if (help->key == key)
		{

			if (size==1)
			{
				head = tail = NULL;
				cout << "Usunieto wszystkie elementy lista jest pusta" << endl;
				size--;
				break;
			}
			else if(head->key==key)
			{
				head = head->next;
				head->prev = NULL;
				size--;
				break;
			}
			else if (tail->key == key)
			{
				tail = tail->prev;
				tail->next = NULL;
				size--;
				break;
			}
			else
			{
				help->next->prev = help->prev;
				help->prev->next = help->next;
				size--;
				break;
			}
		}
	help = help->next;
	}

}

void DoubleList::add()
{
	int position;
	int key2;
	cout << "Podaj pozycje: ";
	cin >> position;
	if (position < 0 || position >size)
	{
		cout << "Niezgodna pozycja"<<endl;
	}
	else
	{
		cout << "Podaj klucz: ";
		cin >> key2;
		if (position < size)
		{
			if (position == 0)
			{
				if (head)
				{
					head->prev = new Link(key2);
					head->prev->next = head;
					head = head->prev;
				}
				else
				{
					head = new Link(key2);
					tail = head;
				}
				size++;
			}
			else if (position <= size / 2)
			{
				Link *help = head;
				for (int i = 1; i < position; i++)
				{
					help = help->next;
				}
				Link *newlink = new Link(key2);
				newlink->next = help->next;
				newlink->prev = help;
				help->next = newlink;
				newlink->next->prev = newlink;
				size++;
			}
			else
			{
				Link *help = tail;
				for (int i = size - 1; i > position; i--)
				{
					help = help->prev;
				}
				Link *helper;
				helper = new Link(key2);
				helper->next = help;
				helper->prev = help->prev;
				help->prev = helper;
				helper->prev->next = helper;
				size++;
			}
		}
		else
		{
			if (tail)
			{
				tail->next = new Link(key2);
				tail->next->prev = tail;
				tail = tail->next;
			}
			else
			{
				head = new Link(key2);
				tail = head;
			}
			size++;
		}
	}
}

void DoubleList::find()
{
	bool flaga = true;
	int key;
	cout << "Podaj jaka liczbe chcesz znalezc: ";
	cin >> key;
	Link *help = head;
	while (help)
	{
		if (help->key == key)
		{
			cout << "Klucz znajduje sie w strukturze" << endl;
			flaga = false;
			break;
		}
		help = help->next;
	}
	if (flaga)
	{
		cout << "Podanego klucza nie ma w liscie" << endl;
	}
}

void DoubleList::fill_up_rand()
{
	int key = 0;
	int _size = 0;
	cout << "Ile losowych liczb mam wpisac do listy: ";
	cin >> _size;
	if (_size < 0)
	{
		cout << "Nieprawidlowy rozmiar" << endl;
	}
	else
	{
		srand((unsigned int)time(NULL));
		for (int i = 0; i < _size; i++)
		{
			key = (rand() % 10);
			if (tail)
			{
				tail->next = new Link(key);
				tail->next->prev = tail;
				tail = tail->next;
			}
			else
			{
				head = new Link(key);
				tail = head;
			}
			size++;
		}
	}
}

void DoubleList::show()
{
	cout << endl << "-------------------------------" << endl;
	Link *element = head;
	while (element)
	{
		cout << element->key<<" ";
		element = element->next;
	}
	cout<< endl << "Od poczatku" << endl << "-------------------------------" << endl;
	element = tail;
	while (element)
	{
		cout << element->key<<" ";
		element = element->prev;
	}
	cout << endl << "Od konca" << endl << "-------------------------------" << endl;
}

void DoubleList::test()
{}
