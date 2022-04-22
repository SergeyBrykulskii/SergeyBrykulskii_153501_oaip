template<typename T>
class ListOnArray
{
public:
	ListOnArray();
	~ListOnArray();

	void push_back(T* data);
	void Add(T* item);
	void Remove(T* item);
	void Clear();

	T* GetFirst();
	T* GetLast();
	T* GetNext(T* item);
	T* GetPrev(T* item);
	T* Get(int index);

	int GetCount();
	bool Contains(T* item);

	T& operator[](int index);
private:
	struct Node
	{
		T* item;
		Node* next;
		Node* prev;
	};

	Node** m_nodes;
	int capacity, size;

	Node* first;
	Node* last;
	int count;
};

template<typename T>
ListOnArray<T>::ListOnArray()
{
	capacity = 100;
	size = 0;
	m_nodes = new Node * [100];
	first = nullptr;
	last = nullptr;
	count = 0;
}

template<typename T>
ListOnArray<T>::~ListOnArray()
{
	Clear();
}

template<typename T>
void ListOnArray<T>::push_back(T* data)
{
	if (size == capacity)
	{
		capacity *= 2;
		Node** temp = new Node * [capacity];
		for (int i = 0; i < count; i++)
		{
			temp[i] = m_nodes[i];
		}
		delete[] m_nodes;
		m_nodes = temp;
	}

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

	m_nodes[size] = node;
	last = node;
	size++;
	count++;
}

template<typename T>
void ListOnArray<T>::Add(T* item)
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
void ListOnArray<T>::Remove(T* item)
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
void ListOnArray<T>::Clear()
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
T* ListOnArray<T>::Get(int index)
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
T* ListOnArray<T>::GetFirst()
{
	return first->item;
}

template<typename T>
T* ListOnArray<T>::GetLast()
{
	return last->item;
}

template<typename T>
T* ListOnArray<T>::GetNext(T* item)
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
T* ListOnArray<T>::GetPrev(T* item)
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
int ListOnArray<T>::GetCount()
{
	return count;
}

template<typename T>
bool ListOnArray<T>::Contains(T* item)
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
T& ListOnArray<T>::operator[](int index)
{
	Node* node = first;
	for (int i = 0; i < index; i++)
	{
		node = node->next;
	}

	return *(node->item);
}