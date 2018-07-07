#pragma once
using namespace std;

struct Link
{
	Link *left;
	Link *right;
	int key;
	Link() : left(NULL), right(NULL) {};
	Link(int x) : key(x), left(NULL), right(NULL)
	{}
};
class Tree
{	
	Link* clear(int x, Link* t);
	Link* mini(Link* t);
	Link*root = NULL;
	int size = 0;
public:
	void fill_up();
	void clear();
	void add();
	void find();
	void fill_up_rand();
	void show();
	void test();
	int _print_t(Link * tree, int is_left, int offset, int depth, char s[20][255]);
	void print_t(Link * tree);
};