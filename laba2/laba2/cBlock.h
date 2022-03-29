#pragma once

template<typename T>
class CBlock
{
public:
	size_t shared_count = 0;
	size_t weak_count = 0;
	T* ptr;
};

