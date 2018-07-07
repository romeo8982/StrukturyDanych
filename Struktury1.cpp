#include "stdafx.h"
#include "Heap.h"
#include <cstdlib>
#include "Tabel.h"
#include <ctime>
#include "double_list.h"
#include "Tree.h"
#include <string>
#include <iostream>
#include <windows.h>

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

void menu_table()
{
	Tabel _tab;
	char option;
	do {
		displayMenu("--- TABLICA ---");
		cin >> option;
		switch (option) {
		case '1': {system("cls"); _tab.fill_up(); _tab.show(); } 
				  break;
		case '2': {system("cls"); _tab.clear(); _tab.show(); }
				  break;
		case '3': {system("cls"); _tab.add(); _tab.show(); } 
				  break;
		case '4': {system("cls"); _tab.find(); _tab.show(); }
				  break;
		case '5': {system("cls"); _tab.fill_up_rand(); _tab.show(); }
				  break;
		case '6': {system("cls"); _tab.show(); }
				  break;
		}
	} while (option != '0');
}
void menu_list()
{
	Double_list _list;
	char option;
	do {
		displayMenu("--- LISTA DWUKIERUNKOWA ---");
		cin >> option;
		switch (option) {
		case '1': { system("cls"); _list.fill_up(); _list.show(); }
				  break;
		case '2': { system("cls"); _list.clear(); _list.show(); }
				  break;
		case '3': {system("cls"); _list.add(); _list.show(); }
				  break;
		case '4': { system("cls"); _list.find(); _list.show(); }
				  break;
		case '5': { system("cls"); _list.fill_up_rand(); _list.show(); }
				  break;
		case '6': {system("cls"); _list.show(); }
				  break;
		}
	} while (option != '0');
}
void menu_heap()
{
	Heap _heap;
	char option;
	do {
		displayMenu("--- KOPIEC BINARNY ---");
		cin >> option;
		switch (option) {
		case '1': {system("cls"); _heap.fill_up(); _heap.show(); }
				  break;
		case '2': {system("cls"); _heap.clear();  _heap.show(); }
				  break;
		case '3': {	system("cls"); _heap.add(); _heap.show(); } 
				  break;
		case '4': {system("cls");  _heap.find();  _heap.show(); }
				  break;
		case '5': {system("cls"); _heap.fill_up_rand();  _heap.show(); }
				  break;
		case '6': {system("cls"); _heap.show(); }
				  break;
		}
	} while (option != '0');
}
void menu_tree()
{
	Tree _tree;
	char option;
	do {
		displayMenu("--- DRZEWO PRZESZUKIWAN BST ---");
		cin >> option;
		switch (option) {
		case '1': {system("cls"); _tree.fill_up(); _tree.show(); } 
				  break;
		case '2': { system("cls"); _tree.clear();  _tree.show(); }
				  break;
		case '3': {system("cls"); _tree.add(); _tree.show(); } 
				  break;
		case '4': { system("cls"); _tree.find(); _tree.show(); }
				  break;
		case '5': { system("cls"); _tree.fill_up_rand(); _tree.show(); }
				  break;
		case '6': { system("cls"); _tree.show(); }
				  break;
		}
	} while (option != '0');
}
int main(int argc, char* argv[])
{
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
		cout << endl;
		switch (option) {
		case '1': {system("cls"); menu_table(); }
			break;
		case '2': {system("cls"); menu_list(); }
			break;
		case '3': {system("cls"); menu_heap(); }
			break;
		case '4': {system("cls"); menu_tree(); }
			break;
		}
	} while (option != '0');
	return 0;
}
