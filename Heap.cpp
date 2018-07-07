#include "stdafx.h"
#include "Heap.h"

void Heap::fill_up()
{
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
					file >> tab[i - 1];
			}
			else break;
		}
	}
	file.close();
	for (int i = 2; i <= size + 1; i++)
	{
		int leaf = i; //lisc
		int	parent = leaf / 2;//rodzic
		helper = tab[i - 1];//rozpatrywany element
		while ((parent > 0) && (tab[parent - 1] <= helper))//dopóki nie korzen lub wiekszy element
		{
			tab[leaf - 1] = tab[parent - 1];//zamiana miejscami
			leaf = parent; parent = leaf / 2;
		}
		tab[leaf - 1] = helper;
	}
}

void Heap::clear()
{
	int number;
	cout << "Podaj liczbe jaka chcesz usunac: ";
	cin >> number;
	for (int i = 0; i < size; i++)
	{
		if (tab[i] == number)
		{
			for(int j=i;j<size+1;j++)
			{
				tab[j] = tab[j + 1];
			}
			size--;
			break;
		}
	}
	//przywracanie wlasnosci kopca
	for (int i = 2; i <= size + 1; i++)//od 2 bo 1 i tak jest na swoim miejscu
	{
		int leaf = i; //lisc
		int	parent = leaf / 2;//rodzic
		helper = tab[i - 1];//rozpatrywany element
		while ((parent > 0) && (tab[parent - 1] <= helper))//dopóki nie korzen lub wiekszy element
		{
			tab[leaf - 1] = tab[parent - 1];//zamiana miejscami
			leaf = parent; parent = leaf / 2;
		}
		tab[leaf - 1] = helper;
	}
}

void Heap::add()
{
		int number;
		cout << "Podaj liczbe jaka chcesz dodac: ";
		cin >> number;
		int i, j;
		i = size++;
		j = (i - 1) / 2;
		while (i > 0 && tab[j] < number)
		{
			tab[i] = tab[j];
			i = j;
			j = (i - 1) / 2;
		}
		tab[i] = number;	
}

void Heap::find()
{
	int flaga = 0;
	int number;
	cout << "Podaj liczbe ktora chcesz znalezc: ";
	cin >> number;
	for (int i = 0; i < size; i++)
	{
		if (tab[i] == number)
		{
			cout << "Podana liczba znajduje sie w kopcu" << endl;
			flaga = 1;
			break;
		}
	}
	if (flaga == 0)
	{
		cout << "Twojej liczby nie ma w kopcu" << endl;
	}
}

void Heap::fill_up_rand()
{
	cout << "Podaj liczbe elementow jaka chcesz wylosowac: ";
	cin >> size;
	if (size <= 0)
	{
		cout << "Nieprawidlowy rozmiar" << endl;
	}
	else
	{
		srand((unsigned int)time(NULL));
		for (int i = 0; i <= size; i++)
		{
			tab[i] = rand() % 10;
		}
		for (int i = 2; i <= size + 1; i++)//od 2 bo 1 i tak jest na swoim miejscu
		{
			int leaf = i; //lisc
			int	ancestor = leaf / 2;//przodek
			helper = tab[i - 1];//rozpatrywany element
			while ((ancestor > 0) && (tab[ancestor - 1] <= helper))//dopóki nie korzen lub wiekszy element
			{
				tab[leaf - 1] = tab[ancestor - 1];//zamiana miejscami
				leaf = ancestor; ancestor = leaf / 2;
			}
			tab[leaf - 1] = helper;
		}
	}
}

void Heap::show()
{
	int cnt = 0;
	int j = 0;
	int sum = 0;
	for (signed i = 0; i < size; i++)
	{
		cout << tab[i] << endl;
		if (i == 0)
		{
			cout << "----------------------" << endl;
			++j;
		}
		else
		{
			if (cnt == pow(2, j))
			{
				cout << "----------------------" << endl;
				++j;
				cnt = 0;
			}
		}
		++cnt;
	}
}

void Heap::test()
{
}
