//#include "myStack.h"
//
//template<typename T>
//MyStack<T>::MyStack(int mSize) : size(mSize)
//{
//	stackPtr = new T[size];
//	top = 0;
//}
//
//template<typename T>
//MyStack<T>::MyStack(const MyStack<T>& other) : size(other.sizefStack())
//{
//	stackPtr = new T[size];
//
//	top = other.getTop();
//
//	for (int i = 0; i < top; i++)
//	{
//		stackPtr[i] = other.getPtr()[i];
//	}
//}
//
//template<typename T>
//MyStack<T>::~MyStack()
//{
//	delete[] stackPtr;
//}
//
//template<typename T>
//void MyStack<T>::push(const T& data)
//{
//	assert(top < size);
//
//	stackPtr[top++] = data;
//}
//
//template<typename T>
//T MyStack<T>::pop()
//{
//	assert(top > 0);
//
// 	stackPtr[top--];
//}
//
//template<typename T>
//const T& MyStack<T>::peek(int num) const
//{
//	assert(num <= top);
//
//	return stackPtr[top - num];
//}
//
//template<typename T>
//int MyStack<T>::sizeofStack() const
//{
//	return size;
//}
//
//template<typename T>
//T* MyStack<T>::getPtr() const
//{
//	return stackPtr;
//}
//
//template<typename T>
//int MyStack<T>::getTop() const
//{
//	return top;
//}