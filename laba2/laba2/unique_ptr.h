#pragma once

//------------------------------------------------------------------
// implementation of unique pointer
//------------------------------------------------------------------

template<class T>
class Unique_ptr
{
private:
	T* ptr = nullptr;

public:
	explicit Unique_ptr(T* ptr) noexcept;
	explicit Unique_ptr() noexcept;

	Unique_ptr(const Unique_ptr&) = delete;
	Unique_ptr& operator=(const Unique_ptr&) = delete;

	Unique_ptr& operator=(Unique_ptr&& other) noexcept;
	Unique_ptr(Unique_ptr&& other) noexcept;
	
	explicit operator bool() const noexcept;

	T* get() const noexcept;
	T* release();
	void reset(T* p = nullptr) noexcept;
	void swap(Unique_ptr& right) noexcept;

	T& operator*() const noexcept;
	T* operator->() const noexcept;
	
	~Unique_ptr();
};
 
#include "unique_ptr.h"

template<class T>
Unique_ptr<T>::Unique_ptr(T* ptr) noexcept : ptr(ptr) {}

template<class T>
Unique_ptr<T>::Unique_ptr() noexcept : ptr(nullptr) {}


template<class T>
Unique_ptr<T>::~Unique_ptr()
{
	delete ptr;
}

template<class T>
Unique_ptr<T>::Unique_ptr(Unique_ptr&& other) noexcept
	: ptr(other.release()) {}

template<class T>
Unique_ptr<T>& Unique_ptr<T>::operator = (Unique_ptr&& other) noexcept {
	reset(other.release());
	return *this;
}

template<class T>
Unique_ptr<T>::operator bool() const noexcept
{
	return ptr;
}

template<class T>
T* Unique_ptr<T>::get() const noexcept {
	return ptr;
}

template<class T>
T* Unique_ptr<T>::release() {
	T* tmp = ptr;
	ptr = nullptr;
	return tmp;
}

template<class T>
void Unique_ptr<T>::reset(T* p) noexcept {
	delete ptr;
	ptr = p;
}

template<class T>
void Unique_ptr<T>::swap(Unique_ptr& right) noexcept
{
	T* tmp = data;
	data = right;
	right = tmp;
}

template<class T>
T& Unique_ptr<T>::operator*() const noexcept {
	return *data;
}

template<class T>
T* Unique_ptr<T>::operator->() const noexcept {
	return data;
}