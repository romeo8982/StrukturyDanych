#include "stdafx.h"
#include "Tree.h"

void Tree::fill_up()
{
	root = NULL;
	int key;
	string name;
	cout << "Podaj nazwe pliku: ";
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
					file >> key;
					Link *element = new Link(key);
					Link *parent = NULL;
					if (!root)
					{
						root = element;
					}
					else
					{
						Link *helper = root;
						while (helper)
						{
							parent = helper;
							if (element->key >= helper->key)
							{
								helper = helper->right;
							}
							else
							{
								helper = helper->left;
							}
						}
						if (element->key > parent->key)
						{
							parent->right = element;
						}
						else
						{
							parent->left = element;
						}
					}
					
				}
			}
			else break;
		}
	}
	file.close();
}

void Tree::clear()
{
	int key;
	cout << "Podaj jaka liczbe ktora chcesz usunac: ";
	cin >> key;
	clear(key, root);
	size--;
}

void Tree::add()
{
	int key;
	cout << "Podaj klucz jaki chcesz dodac: ";
	cin >> key;
	Link *element = new Link(key);
	Link *parent = NULL;
	if (!root)//jesli brak korzenia to element jest korzeniem
	{
		root = element;
	}
	else
	{
		Link *helper = root;
		while (helper)//szukamy rodzica naszego elementu
		{
			parent = helper;
			if (element->key >= helper->key)//jezeli nasz klucz jest wiekszy to idziemy w prawo od korzenia
			{
				helper = helper->right;
			}
			else
			{
				helper = helper->left;//jesli nie to w lewo
			}
		}
		if (element->key > parent->key)
		{
			parent->right = element;
		}
		else
		{
			parent->left = element;
		}
	}
	size++;
}

void Tree::find()
{
	int key;
	cout << "Podaj liczbe jaka chcesz wyszukac: ";
	cin >> key;
	Link *helper = root;
	while ((helper) && (helper->key != key))
	{
		if (key < helper->key)
		{
			helper = helper->left;
		}
		else
		{
			helper=helper->right;
		}
	}
	if (helper==0)
	{
		cout << "elementu nie ma w drzewie"<< endl;
	}
	else
	{
		cout << "element jest w drzewie"<< endl;
	}
}

void Tree::fill_up_rand()
{
	root = NULL;
	size = 0;
	int x,key;
	cout << "Ile elementow chcesz wylosowac: ";
	cin >> x;
	if (x <= 0)
	{
		cout << "Nieprawidlowy rozmiar" << endl;
	}
	else
	{
		srand((unsigned int)time(NULL));
		for (int i = 0; i < x; i++)
		{
			key = (rand() % 100);
			Link *element = new Link(key);
			Link *parent = NULL;
			if (!root)
			{
				root = element;
			}
			else
			{
				Link *helper = root;
				while (helper)
				{
					parent = helper;
					if (element->key >= helper->key)
					{
						helper = helper->right;
					}
					else
					{
						helper = helper->left;
					}
				}

				if (element->key < parent->key)
					parent->left = element;
				else
					parent->right = element;
			}
			size++;
		}
	}
}

void Tree::show()
{
		print_t(root);
}

Link * Tree::mini(Link* t)
{
	if (t == NULL)
		return NULL;
	else if (t->left == NULL)//jesli nie ma lewego zwroc t
		return t;
	else
		return mini(t->left);//jesli jest lewy wywolaj funkcje dla lewego 
}

Link * Tree::clear(int x, Link * t)
{
	Link* helper;
	if (t == NULL)//jezeli brak to zwóæ nic	
		return NULL;
	else if (x < t->key)//jesli jest mniejszy od wezla to wywolaj funkcje dla lewego syna
		t->left = clear(x, t->left);
	else if (x > t->key)//jesli jest wiêkszy od wezla to wywolaj funkcje dla prawego syna
		t->right = clear(x, t->right);
	else if (t->left && t->right)//jesli ma obu synow
	{
		helper = mini(t->right);//znajdz najmniejeszego po prawej
		t->key = helper->key;
		t->right = clear(t->key, t->right);//usun najmniejszego po prawej
	}
	else
	{
		if (t != root)
		{
			helper = t;
			if (t->left == NULL)//jesli nie ma lewgo to zastap usuawany element prawym
			{
				t = t->right;
			}
			else if (t->right == NULL)//jesli nie ma prawego to zastap lewym
			{
				t = t->left;
			}
			delete helper;
		}
		else
		{
			helper = t;
			if (t->left == NULL)//jesli nie ma lewgo to zastap usuawany element prawym
			{
				root=t->right;
			}
			else if (t->right == NULL)//jesli nie ma prawego to zastap lewym
			{
				root = t->left;
			}
			delete helper;
		}
	}
	return t;
}

void Tree::test()
{
}

int Tree::_print_t(Link *tree, int is_left, int offset, int depth, char s[20][255])
{
	char b[20];
	int width = 5;

	if (!tree) return 0;

	sprintf_s(b, "(%03d)", tree->key);

	int left = _print_t(tree->left, 1, offset, depth + 1, s);
	int right = _print_t(tree->right, 0, offset + left + width, depth + 1, s);

#ifdef COMPACT
	for (int i = 0; i < width; i++)
		s[depth][offset + left + i] = b[i];

	if (depth && is_left) {

		for (int i = 0; i < width + right; i++)
			s[depth - 1][offset + left + width / 2 + i] = '-';

		s[depth - 1][offset + left + width / 2] = '.';

	}
	else if (depth && !is_left) {

		for (int i = 0; i < left + width; i++)
			s[depth - 1][offset - width / 2 + i] = '-';

		s[depth - 1][offset + left + width / 2] = '.';
	}
#else
	for (int i = 0; i < width; i++)
		s[2 * depth][offset + left + i] = b[i];

	if (depth && is_left) {

		for (int i = 0; i < width + right; i++)
			s[2 * depth - 1][offset + left + width / 2 + i] = '-';

		s[2 * depth - 1][offset + left + width / 2] = '+';
		s[2 * depth - 1][offset + left + width + right + width / 2] = '+';

	}
	else if (depth && !is_left) {

		for (int i = 0; i < left + width; i++)
			s[2 * depth - 1][offset - width / 2 + i] = '-';

		s[2 * depth - 1][offset + left + width / 2] = '+';
		s[2 * depth - 1][offset - width / 2 - 1] = '+';
	}
#endif

	return left + width + right;
}

void Tree::print_t(Link *tree)
{
	char s[20][255];
	for (int i = 0; i < 20; i++)
		sprintf_s(s[i], "%80s", " ");

	_print_t(tree, 0, 0, 0, s);

	for (int i = 0; i < 20; i++)
		printf("%s\n", s[i]);
}