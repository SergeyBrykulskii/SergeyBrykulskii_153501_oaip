#pragma once

template<typename T>
class List
{
public:
	List();
	~List();

	void push_back(T data);
	void Add(T item);
	void Remove(T item);
	void Clear();
	void moveBlock(int from, int to, int position);
	
	T GetFirst();
	T GetLast();
	T GetNext(T item);
	T GetPrev(T item);
	T Get(int index);

	int size();
	bool contains(T item);

	T& operator[](int index);
private:
	struct Node
	{
		T item;
		Node* next;
		Node* prev;
	};
	
	Node* getNode(int index)
	{
		Node* node = first;
		for (int i = 0; i < index; i++)
		{
			node = node->next;
		}

		return node;
	}

	Node* first;
	Node* last;
	int count;
};

template<typename T>
List<T>::List()
{
	first = nullptr;
	last = nullptr;
	count = 0;
}

template<typename T>
List<T>::~List()
{
	Clear();
}

template<typename T>
void List<T>::push_back(T data)
{
	Node* node = new Node();
	node->item = data;
	node->next = nullptr;
	node->prev = last;

	if (last != nullptr)
	{
		last->next = node;
	}
	else
	{
		first = node;
	}

	last = node;
	count++;
}

template<typename T>
void List<T>::Add(T item)
{
	Node* node = new Node();
	node->item = item;
	node->next = nullptr;
	node->prev = nullptr;

	if (first == nullptr)
	{
		first = node;
		last = node;
	}
	else
	{
		node->prev = last;
		last->next = node;
		last = node;
	}

	count++;
}

template<typename T>
void List<T>::Remove(T item)
{
	Node* node = first;
	while (node != nullptr)
	{
		if (node->item == item)
		{
			if (node->prev != nullptr)
			{
				node->prev->next = node->next;
			}
			else
			{
				first = node->next;
			}

			if (node->next != nullptr)
			{
				node->next->prev = node->prev;
			}
			else
			{
				last = node->prev;
			}

			delete node;
			count--;
			break;
		}

		node = node->next;
	}
}

template<typename T>
void List<T>::Clear()
{
	Node* node = first;
	while (node != nullptr)
	{
		Node* next = node->next;
		delete node;
		node = next;
	}

	first = nullptr;
	last = nullptr;
	count = 0;
}

template<typename T>
T List<T>::Get(int index)
{
	if (index < 0 || index >= count)
	{
		return nullptr;
	}

	Node* node = first;
	for (int i = 0; i < index; i++)
	{
		node = node->next;
	}

	return node->item;
}

template<typename T>
T List<T>::GetFirst()
{
	return first->item;
}

template<typename T>
T List<T>::GetLast()
{
	return last->item;
}

template<typename T>
T List<T>::GetNext(T item)
{
	Node* node = first;
	while (node != nullptr)
	{
		if (node->item == item)
		{
			return node->next->item;
		}

		node = node->next;
	}

	return nullptr;
}

template<typename T>
T List<T>::GetPrev(T item)
{
	Node* node = first;
	while (node != nullptr)
	{
		if (node->item == item)
		{
			return node->prev->item;
		}

		node = node->next;
	}

	return nullptr;
}

template<typename T>
int List<T>::size()
{
	return count;
}

template<typename T>
bool List<T>::contains(T item)
{
	Node* node = first;
	while (node != nullptr)
	{
		if (node->item == item)
		{
			return true;
		}

		node = node->next;
	}

	return false;
}
template<typename T>
T& List<T>::operator[](int index)
{
	Node* node = first;
	for (int i = 0; i < index; i++)
	{
		node = node->next;
	}

	return node->item;
}

template<typename T>
void List<T>::moveBlock(int posFrom, int posTo, int position)
{
	if (posFrom < 0 || posFrom >= posTo || posTo >= count || position < 0 || position > count)
	{
		return;
	}
	
	Node* from = getNode(posFrom);
	Node* to = getNode(posTo);
	
	if (from->prev != nullptr && to->next != nullptr)
	{
		from->prev->next = to->next;
		to->next->prev = from->prev;
	}
	else if (from->prev == nullptr)
	{
		first = to->next;
		first->prev = nullptr;
	} else if (to->next == nullptr)
	{
		last = from->prev;
		last->next = nullptr;
	}
	
	Node* in = getNode(position);
	
	if (in->next != nullptr && in->prev != nullptr)
	{
		from->prev = in->prev;
		in->prev->next = from;
		to->next = in;
		in->prev = to;
	}
	else if (in->next == nullptr)
	{
		last = from;
		last->next = nullptr;
		to->next = in;
		in->prev = to;
	}
	else if (in->prev == nullptr)
	{
		first = from;
		first->prev = nullptr;
		to->next = in;
		in->prev = to;
	}
}