#pragma once

template<typename T>
class Stack
{
public:
	Stack();
	~Stack();

	void push(T data);
	T pop();
	T peek();
	bool isEmpty();
private:
	struct Node
	{
		T data;
		Node* next;
	};
	Node* head;
};

template<typename T>
Stack<T>::Stack()
{
	head = nullptr;
}

template<typename T>
Stack<T>::~Stack()
{
	while (head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

template<typename T>
void Stack<T>::push(T data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->next = head;
	head = temp;
}

template<typename T>
T Stack<T>::pop()
{
	if (isEmpty())
	{
		throw "Stack is empty";
	}
	Node* temp = head;
	head = head->next;
	T data = temp->data;
	delete temp;
	return data;
}

template<typename T>
T Stack<T>::peek()
{
	if (isEmpty())
	{
		throw "Stack is empty";
	}
	return head->data;
}

template<typename T>
bool Stack<T>::isEmpty()
{
	return head == nullptr;
}