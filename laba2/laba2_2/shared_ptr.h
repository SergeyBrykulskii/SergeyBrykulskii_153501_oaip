#pragma once

//------------------------------------------------------------------
// implementation of shared pointer
//------------------------------------------------------------------

#include "cBlock.h"

template<typename T>
class Shared_ptr
{
private:

	CBlock<T>* cptr = nullptr;

	template<class T> friend class Weak_ptr;

public:

	Shared_ptr();
	Shared_ptr(T* cptr);

	explicit Shared_ptr(Weak_ptr<T>& ptr);

	Shared_ptr(const Shared_ptr& sptr);

	Shared_ptr<T>& operator=(Shared_ptr<T>& sptr);

	Shared_ptr(Shared_ptr&& sptr) noexcept;

	Shared_ptr<T>& operator=(Shared_ptr<T>&& sptr) noexcept;

	T& operator*() const;
	T* operator->() const;

	size_t use_count() const;
	bool unique() const noexcept;
	void reset(T* ptr);
	T* get() const noexcept;

	void swap(const Shared_ptr<T>& sptr);

	~Shared_ptr();
};

template<typename T>
Shared_ptr<T>::Shared_ptr() : cptr(nullptr) {};

template<typename T>
Shared_ptr<T>::Shared_ptr(T* ptr) : cptr(new CBlock<T>)
{
	cptr->ptr = ptr;
	++cptr->shared_count;
};

template<typename T>
Shared_ptr<T>::Shared_ptr(Weak_ptr<T>& ptr) : cptr(ptr.getPtr())
{
	if (cptr)
	{
		++cptr->shared_count;
	}
}

template<typename T>
Shared_ptr<T>::Shared_ptr(const Shared_ptr& sptr)
{
	cptr = sptr.cptr;
	if (cptr)
	{
		++cptr->shared_count;
	}
}

template<typename T>
Shared_ptr<T>& Shared_ptr<T>::operator=(Shared_ptr<T>& sptr)
{
	if (cptr)
	{
		--cptr->shared_count;
	}
	cptr = sptr.cptr;
	if (cptr)
	{
		++cptr->shared_count;
	}
	return *this;
}

template<typename T>
Shared_ptr<T>::Shared_ptr(Shared_ptr&& sptr) noexcept
{
	cptr = sptr.cptr;
	if (cptr)
	{
		cptr->ptr = sptr.cptr->ptr;
	}
	sptr.cptr->ptr = nullptr;
}

template<typename T>
Shared_ptr<T>& Shared_ptr<T>::operator=(Shared_ptr<T>&& sptr) noexcept
{
	if (this->cptr)
	{
		--cptr->shared_count;
	}
	cptr = sptr.cptr;
	if (cptr)
	{
		cptr->ptr = sptr.cptr->ptr;
	}
	sptr.cptr = nullptr;
	return *this;
}

template<typename T>
T& Shared_ptr<T>:: operator*() const
{
	return *(cptr->ptr);
}

template<typename T>
T* Shared_ptr<T>::operator->() const
{
	return cptr->ptr;
}

template<typename T>
size_t Shared_ptr<T>::use_count() const
{
	if (cptr)
		return cptr->shared_count;

	return 0;
}

template<typename T>
bool Shared_ptr<T>::unique() const noexcept
{
	return this->use_count() == 1;
}

template<typename T>
void Shared_ptr<T>::reset(T* ptr)
{
	delete cptr->ptr;
	cptr->ptr = ptr;
}

template<typename T>
T* Shared_ptr<T>::get() const noexcept
{
	if (cptr)
		return cptr->ptr
	else
		return nullptr;
}

template<typename T>
void Shared_ptr<T>::swap(const Shared_ptr<T>& sptr)
{
	std::swap(cptr, sptr.cptr);
}
template<typename T>
Shared_ptr<T>::~Shared_ptr() {

	if (!cptr || !cptr->ptr) {
		return;
	}

	--cptr->shared_count;

	if (cptr->shared_count <= 0) {
		delete cptr->ptr;
		cptr->ptr = nullptr;
		if (cptr->weak_count <= 0) {
			delete cptr;
			cptr = nullptr;
		}
	}
}