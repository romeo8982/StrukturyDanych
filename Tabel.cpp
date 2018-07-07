#include "stdafx.h"
#include "Tabel.h"
void Tabel::fill_up()
{
	string name;
	cout << "Podaj nazwe pliku: " << endl;
	cin >> name;
	ifstream file;
	file.open(name.c_str());
	if (file.good())
	{
		for(int i=0;;i++)
		{
			if (file.good())
			{
				if (i == 0)
				{
					file >> size;
					tab = new int[size];
				}
			else
				file >> tab[i-1];
			}
			else break;
		}
	}
	file.close();
}
void Tabel::clear()
{
	int position;
	cout << "Podaj pozycje: ";
	cin >> position;
	if (position < 0 || position >size)
	{
		cout << "Niezgodna pozycja";
	}
	else
	{
		size = size - 1;
		int i;
		int *copy = new int[size];
		for (i=0; i < position; i++)
		{
			copy[i] = tab[i];
		}
		for (i = i + 1; i <= size; i++)
		{
			copy[i-1] = tab[i];
		}
		tab = new int[size];
		for (int i = 0; i < size; i++)
		{
			tab[i] = copy[i];
		}
	}
}
void Tabel::add()
{
	int position;
	int number;
	cout << "Podaj pozycje: ";
	cin >> position;
	if (position < 0 || position >size)
	{
		cout << "Niezgodna pozycja";
	}
	else
	{
	cout << "Podaj wartosc: ";
	cin >> number;
		size = size + 1;
		int i=0;
		int *copy = new int[size];
		for (i; i < position; i++)
		{
			copy[i] = tab[i];
		}
		copy[position] = number;
		for(i=i+1;i<=size;i++)
		{
			copy[i] = tab[i-1];
		}
		tab = new int[size];
		for (int i = 0; i < size; i++)
		{
			tab[i] = copy[i];
		}
	}
}
void Tabel::find()
{
	int flaga = 0;
	int number;
	cout << "Podaj liczbe ktora chcesz znalezc: ";
	cin >> number;
	for (int i = 0; i < size; i++)
	{
		if (tab[i] == number)
		{
			cout << "Podana liczba znajduje sie w tablicy" << endl;
			//cout << "Twoja liczba znajduje sie na " << i + 1 << " pozycji" << endl;
			flaga = 1;
			break;
		}
	}
	if (flaga == 0)
	{
		cout << "Twojej liczby nie ma w tablicy" << endl;
	}
}
void Tabel::fill_up_rand()
{
	cout << "Podaj wielkosc tablicy ";
	cin >> size;
	if (size <= 0)
	{
		cout << "Nieprawidlowy rozmiar" << endl;
	}
	tab = new int[size];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < size; i++)
	{
		tab[i] = (rand() % 10);
	}
}
void Tabel::show()
{
	for (int i = 0; i < size; i++)
	{
		cout << tab[i] << " ";
	}
}
void Tabel::test()
{
	int _size;
	string name;
	cout << "Podaj nazwe pliku: " << endl;
	cin >> name;
	cout << "Podaj ilosc liczb jaka chcesz wylosowac: " << endl;
	cin >> _size;
	fstream file(name, ios::out);
	if (file.good())
	{
		for (int i = 0; i < _size + 1; i++)
		{
			if (i == 0)
			{
				file << _size << " ";
			}
			else
			{
				file << (rand() % 99) << " ";
			}
		}
	}
	file.close();
}
Tabel::~Tabel()
{
	delete tab;
}
