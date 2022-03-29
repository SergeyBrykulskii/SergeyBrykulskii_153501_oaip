#include "doubList.h"
DoubList::DoubList()
{
	root = new node;
	length = 0;
}

DoubList::~DoubList() {}

void DoubList::push_back(int data)
{
	Shared_ptr<node> newNode = Shared_ptr<node>(new node);
	newNode->data = data;
	if (this->length == 0)
	{
		this->length++;

		root->next = newNode;
		newNode->previous = newNode;
		newNode->next = newNode;
	}
	else
	{
		Shared_ptr<node> current = root->next;

		for (int i = 0; i < this->length; i++)
		{
			current = current->next;
		}

		newNode->next = current;
		newNode->previous = current->previous;
		(current->previous.lock())->next = newNode;
		current->next = newNode;

		this->length++;
	}
}

void DoubList::pop_back()
{
	if (this->length == 0)
		return;
	else
	{
		if (this->length == 1)
		{
			this->root->next = Shared_ptr<node>();
			this->length--;
		}
		else
		{
			int pos = this->length;

			Shared_ptr<node> deleteNode = root->next;

			for (int i = 0; i < this->length; i++)
			{
				deleteNode = deleteNode->next;
			}

			(deleteNode->previous.lock())->next = deleteNode->next;
			deleteNode->next->previous = deleteNode->previous;
			this->length--;

		}
	}
}

int DoubList::getLength() const
{
	return this->length;
}
int DoubList::getData(int pos) const
{
	Shared_ptr<node> current = root->next;

	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}

	return current->data;
}

void DoubList::insert(int pos, int data)
{
	Shared_ptr<node> insertNode = Shared_ptr<node>(new node);

	insertNode->data = data;

	if (this->length == 0)
	{
		this->length++;

		root->next = insertNode;
		insertNode->previous = insertNode;
		insertNode->next = insertNode;
	}
	else
	{
		Shared_ptr<node> current = root->next;

		for (int i = 0; i < pos; i++)
		{
			current = current->next;
		}

		insertNode->next = current;
		insertNode->previous = current->previous;
		(current->previous.lock())->next = insertNode;

		this->length++;
	}
}

void DoubList::erase(int pos)
{
	if (this->length == 0)
	{
		return;
	}
	else
	{
		if (this->length == 1)
		{
			this->root->next = Shared_ptr<node>();
			this->length--;
		}
		else
		{
			Shared_ptr<node> deleteNode = root->next;

			for (int i = 0; i < pos; i++)
			{
				deleteNode = deleteNode->next;
			}

			(deleteNode->previous.lock())->next = deleteNode->next;
			deleteNode->next->previous = deleteNode->previous;
			this->length--;
		}
	}
}
