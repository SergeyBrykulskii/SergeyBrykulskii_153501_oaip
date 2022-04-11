#pragma once

#include "cassert"
#include "Position.h"

template<typename T>
class MyStack
{
private:
	T* stackPtr;
	Position* pos;
	const int size;
	int top;
public:
	MyStack(int mSize = 10);
	MyStack(const MyStack<T>& other);

	~MyStack();

	void push(const T& data, int posX = 0, int posY = 0);
	T pop();
	
	Position* getPos() const;
	
	int sizeofStack() const;
	T* getPtr() const;
	int getTop() const;
};

template<typename T>
MyStack<T>::MyStack(int mSize) : size(mSize)
{
	pos = new Position[size];
	stackPtr = new T[size];
	top = 0;
}

template<typename T>
MyStack<T>::MyStack(const MyStack<T>& other) : size(other.sizefStack())
{
	stackPtr = new T[size];

	top = other.getTop();

	for (int i = 0; i < top; i++)
	{
		pos[i] = other.getPos()[i];
		stackPtr[i] = other.getPtr()[i];
	}
}

template<typename T>
MyStack<T>::~MyStack()
{
	delete[] pos;
	delete[] stackPtr;
}

template<typename T>
void MyStack<T>::push(const T& data, int posX, int posY)
{
	assert(top < size);

	stackPtr[top] = data;
	pos[top++] = Position(posX, posY);
}

template<typename T>
T MyStack<T>::pop()
{
	assert(top > 0);

	return stackPtr[--top];
}

template<typename T>
int MyStack<T>::sizeofStack() const
{
	return size;
}

template<typename T>
T* MyStack<T>::getPtr() const
{
	return stackPtr;
}

template<typename T>
int MyStack<T>::getTop() const
{
	return top;
}

template<typename T>
Position* MyStack<T>::getPos() const
{
	return pos;
}