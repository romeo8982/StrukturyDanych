#pragma once
#include <iostream>
using namespace std;
class Tabel
{
	int *tab;
	int size;
public:	
	void fill_up();
	void clear();
	void add();
	void find();
	void fill_up_rand();
	void show();
	void test();
	~Tabel();
};