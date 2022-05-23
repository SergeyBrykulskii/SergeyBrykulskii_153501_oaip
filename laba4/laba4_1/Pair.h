#pragma once

template<class T1, class T2>
struct Pair
{
	T1 first;
	T2 second;
	
	Pair(T1 first, T2 second) : first(first), second(second) {}
	
	bool operator==(const Pair& other) const
	{
		return first == other.first && second == other.second;
	}
	
	bool operator!=(const Pair& other) const
	{
		return !(*this == other);
	}
	
	bool operator<(const Pair& other) const
	{
		return first < other.first || (first == other.first && second < other.second);
	}
	
	bool operator>(const Pair& other) const
	{
		return other < *this;
	}
	
	bool operator<=(const Pair& other) const
	{
		return !(other < *this);
	}
	
	bool operator>=(const Pair& other) const
	{
		return !(*this < other);
	}
	
	Pair& operator=(const Pair& other)
	{
		first = other.first;
		second = other.second;
		return *this;
	}
};