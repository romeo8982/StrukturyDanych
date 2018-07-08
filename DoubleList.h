#pragma once
#include <iostream>

using namespace std;

class DoubleList : public Struct
{
	struct Link
	{
		Link *next;
		Link *prev;
		int key;
		Link(int x) : key(x), next(NULL), prev(NULL)
		{}
	};
	Link *head = NULL;
	Link *tail = NULL;
	int size = 0;
public:
	void fill_up();
	void clear();
	void add();
	void find();
	void fill_up_rand();
	void show();
	void test();
};