#include "stdafx.h"
#include "Heap.h"
#include "Tabel.h"
#include "DoubleList.h"
#include "Tree.h"

using namespace std;

void displayMenu(string info)
{
	cout << endl;
	cout << info << endl;
	cout << "1.Wczytaj z pliku" << endl;
	cout << "2.Usun" << endl;
	cout << "3.Dodaj" << endl;
	cout << "4.Znajdz" << endl;
	cout << "5.Utworz losowo" << endl;
	cout << "6.Wyswietl" << endl;
	cout << "0.Powrot do menu" << endl;
	cout << "Podaj opcje:";
}

void menu(string info , Struct *structOfContainer)
{
	char option;
	do {
		displayMenu(info);
		cin >> option;
		switch (option) {
		case '1': {system("cls"); structOfContainer->fill_up(); structOfContainer->show(); }
				  break;
		case '2': {system("cls"); structOfContainer->clear(); structOfContainer->show(); }
				  break;
		case '3': {system("cls"); structOfContainer->add(); structOfContainer->show(); }
				  break;
		case '4': {system("cls"); structOfContainer->find(); structOfContainer->show(); }
				  break;
		case '5': {system("cls"); structOfContainer->fill_up_rand(); structOfContainer->show(); }
				  break;
		case '6': {system("cls"); structOfContainer->show(); }
				  break;
		}
	} while (option != '0');

}

int main(int argc, char* argv[])
{
	Struct *structOfContainer;
	char option;
	do {
		system("cls");
		cout << endl;
		cout << "==== MENU GLOWNE ===" << endl;
		cout << "1.Tablica" << endl;
		cout << "2.Lista" << endl;
		cout << "3.Kopiec" << endl;
		cout << "4.Drzewo" << endl;
		cout << "0.Wyjscie" << endl;
		cout << "Podaj opcje:";
		cin >> option;
		system("cls");
		switch (option) {
		case '1': {
					structOfContainer = new Tabel;
					menu("--- TABLICA ---", structOfContainer);
					delete structOfContainer;
				  }
		break;
		case '2': {
					structOfContainer = new DoubleList;
					menu("--- LISTA DWUKIERUNKOWA ---", structOfContainer);
					delete structOfContainer;
				  }
		break;
		case '3': {
					structOfContainer = new Heap;
					menu("--- KOPIEC BINARNY ---", structOfContainer);
					delete structOfContainer;
			      }
		break;
		case '4': {
					structOfContainer = new Tree;
					menu("--- DRZEWO PRZESZUKIWAN BST ---", structOfContainer);
					delete structOfContainer;
				  }
		break;
		}
	} while (option != '0');
	return 0;
}
