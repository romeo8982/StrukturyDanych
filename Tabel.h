#pragma once
using namespace std;
class Tabel : public Struct
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