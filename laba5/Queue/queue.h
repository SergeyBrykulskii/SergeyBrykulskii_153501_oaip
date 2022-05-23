#pragma once

template<class T>
class Queue
{
private:
	class Node
	{
	public:
		T data;
		Node* next;
	};


	Node* head;
	Node* tail;
	size_t sizeq;
public:
	Queue();
	~Queue();

	void push(T data);
	T pop();
	bool empty() const;
	size_t size() const;
	void clear();
	T* front();
	T* back();
};


template<class T>
Queue<T>::Queue()
{
	head = nullptr;
	tail = nullptr;
	sizeq = 0;
}

template<class T>
void Queue<T>::push(T date)
{
	Node* newNode = new Node;
	newNode->data = date;

	if (sizeq == 0)
	{
		head = newNode;
		tail = newNode;
		sizeq++;
		return;
	}

	tail->next = newNode;
	tail = newNode;
	newNode->next = nullptr;
	sizeq++;
}

template<class T>
T Queue<T>::pop()
{
	if (empty())
	{
		throw std::exception("Queue is empty");
	}

	Node* temp = head;
	head = head->next;
	T data = temp->data;
	delete temp;
	sizeq--;
	return data;
}

template<class T>
size_t Queue<T>::size() const
{
	return sizeq;
}

template<class T>
bool Queue<T>::empty() const
{
	return sizeq == 0;
}

template<class T>
void Queue<T>::clear()
{
	while (!empty())
	{
		pop();
	}
}

template<class T>
T* Queue<T>::front()
{
	if (empty())
	{
		throw std::exception("Queue is empty");
	}

	return &head->data;
}

template<class T>
T* Queue<T>::back()
{
	if (empty())
	{
		throw std::exception("Queue is empty");
	}

	return &tail->data;
}

template<class T>
Queue<T>::~Queue()
{
	clear();
}