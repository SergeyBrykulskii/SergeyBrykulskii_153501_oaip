#pragma once

#include "shared_ptr.h"
#include "weak_ptr.h"

struct node
{
	int data;
	Shared_ptr<node> next;
	Weak_ptr<node> previous;
};

class DoubList
{
private:
	int length;
	node* root;
public:
	DoubList();
	~DoubList();

	void push_back(int data);
	void pop_back();
	int getLength() const;
	int getData(int pos) const;

	void insert(int pos, int data);
	void erase(int pos);
};