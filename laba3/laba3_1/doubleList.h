#pragma once

template<typename T>
class DoubleList
{
public:
	DoubleList();
	~DoubleList();

	void Add(T* item);
	void Remove(T* item);
	void Clear();
	T* GetFirst();
	T* GetLast();
	T* GetNext(T* item);
	T* GetPrev(T* item);
	int GetCount();
	bool Contains(T* item);
private:
	struct Node
	{
		T* item;
		Node* next;
		Node* prev;
	};

	Node* first;
	Node* last;
	int count;
};

template<typename T>
DoubleList<T>::DoubleList()
{
	first = nullptr;
	last = nullptr;
	count = 0;
}

template<typename T>
DoubleList<T>::~DoubleList()
{
	Clear();
}

template<typename T>
void DoubleList<T>::Add(T* item)
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
void DoubleList<T>::Remove(T* item)
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
void DoubleList<T>::Clear()
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
T* DoubleList<T>::GetFirst()
{
	return first->item;
}

template<typename T>
T* DoubleList<T>::GetLast()
{
	return last->item;
}

template<typename T>
T* DoubleList<T>::GetNext(T* item)
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
T* DoubleList<T>::GetPrev(T* item)
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
int DoubleList<T>::GetCount()
{
	return count;
}

template<typename T>
bool DoubleList<T>::Contains(T* item)
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