#pragma once

#include "cBlock.h"
#include "shared_ptr.h"
//------------------------------------------------------------------
// implementation of weak pointer
//------------------------------------------------------------------

template<typename T>
class Weak_ptr
{
private:
	CBlock<T>* cptr;
public:
	Weak_ptr();
	Weak_ptr(const Shared_ptr<T>& sptr);


	Weak_ptr<T>& operator=(const Weak_ptr<T>& wptr);
	Weak_ptr<T>& operator=(const Shared_ptr<T>& sptr) noexcept;

	Weak_ptr<T>& operator=(Weak_ptr<T>&& wptr) noexcept;

	bool expired();
	void reset() noexcept;
	void swap(Weak_ptr& wptr) noexcept;
	CBlock<T>* getPtr();
	Shared_ptr<T> lock();

	~Weak_ptr();
};

template<typename T>
Weak_ptr<T>::Weak_ptr() : cptr(nullptr) {}

template<typename T>
Weak_ptr<T>::Weak_ptr(const Shared_ptr<T>& sptr)
{
	cptr = sptr.cptr;
	if (cptr)
	{
		++cptr->weak_count;
	}
}

template<typename T>
CBlock<T>* Weak_ptr<T>::getPtr() 
{
	return cptr;
}

template<typename T>
Weak_ptr<T>& Weak_ptr<T>::operator=(const Weak_ptr<T>& wptr)
{
	if (cptr)
	{
		--cptr->weak_count;
	}

	cptr = wptr.cptr;

	if (cptr)
	{
		++cptr->weak_count;
	}

	return *this;
}

template<typename T>
Weak_ptr<T>& Weak_ptr<T>::operator=(const Shared_ptr<T>& sptr) noexcept
{
	if (cptr)
	{
		--cptr->weak_count;
	}

	cptr = sptr.cptr;

	if (cptr)
	{
		++cptr->weak_count;
	}

	return *this;
}


template<typename T>
Weak_ptr<T>& Weak_ptr<T>::operator=(Weak_ptr<T>&& wptr) noexcept
{
	if (this->cptr)
	{
		--cptr->weak_count;
	}

	cptr = w.cptr;
	wptr.cptr = nullptr;

	return *this;
}

template<typename T>
void Weak_ptr<T>::swap(Weak_ptr& wptr) noexcept
{
	std::swap(cptr, wptr.cptr);
}

template<typename T>
bool Weak_ptr<T>::expired()
{
	return (!cptr || cptr->shared_count <= 0);
}

template<typename T>
void Weak_ptr<T>::reset() noexcept
{
	if (cptr)
	{
		--cptr->Weak_count;
	}
	cptr = nullptr;
}

template<typename T>
Shared_ptr<T> Weak_ptr<T>::lock()
{
	if (expired())
		return Shared_ptr<T>();
	else
		return Shared_ptr<T>(*this);
}

template<typename T>
Weak_ptr<T>::~Weak_ptr()
{
	if (!cptr)
	{
		return;
	}

	--cptr->weak_count;

	if (cptr->shared_count <= 0 && cptr->weak_count <= 0)
	{
		delete cptr;
		cptr = nullptr;
	}
}