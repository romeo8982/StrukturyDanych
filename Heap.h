#pragma once
#include <iostream>

using namespace std;

class Heap
{
	int size = 0;
	int helper;
	int tab[40000];
public:
	void fill_up();
	void clear();
	void add();
	void find();
	void fill_up_rand();
	void show();
	void test();
};