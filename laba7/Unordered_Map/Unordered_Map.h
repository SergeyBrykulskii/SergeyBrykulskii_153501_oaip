#pragma once

#include <functional>
#include <ctime>
#include <forward_list>


template<typename Key, typename T, typename Hash = std::hash<Key>, typename KeyEqual = std::equal_to<Key>>
class Unordered_Map {
private:
    int size;
    int count;
    std::forward_list<std::pair<const Key, T>>* table;
    std::list<std::pair<const Key, T>> iteratorList;
	
    int hash(Key key) {
        return Hash()(key) % size;
    }
public:
    Unordered_Map(int size = 10)
    {
        this->size = size;
        count = 0;
        table = new std::forward_list<std::pair<const Key, T>>[size];

    }
    ~Unordered_Map()
    {
        delete[] table;
    }

    std::forward_list<std::pair<const Key, T>>* getTable()
	{
		return table;
	}
	
    void insert(Key key, T data)
    {
        if (double(count) / size > 0.75)
            this->rehash();

        int index = hash(key);
        iteratorList.push_back(std::pair<const Key, T>(key, data));
        table[index].push_front(std::pair<const Key, T>(key, data));
        count++;
    }

    /*List<std::pair<const Key, T>*>& operator[](int index)
    {
        return table[index];
    }*/

    int getSize()
    {
        return size;
    }

    // rehash
    void rehash()
    {
        int oldSize = size;
        size = size * 2;
		
        std::forward_list<std::pair<const Key, T>>* oldTable = table;
        table = new std::forward_list<std::pair<const Key, T>>[size];
        for (int i = 0; i < oldSize; i++)
        {
            for(auto it = oldTable[i].begin(); it != oldTable[i].end(); it++)
			{
				insert(it->first, it->second);
			}
        }
        delete[] oldTable;
    }
	
    bool find(const Key key)
	{
		auto& bucket = table[hash(key)];
		for (auto it = bucket.begin(); it != bucket.end(); it++)
		{
			if (it->first == key)
			{
				return true;
			}
		}
		return false;
	}
	
    void clear()
    {
        iteratorList.clear();
		
        for (int i = 0; i < size; i++)
		{
			table[i].clear();
		}
		count = 0;
    }

	void erase(const Key key)
	{
        auto flag = find(key);
        if (flag)
        {
			
		    int index = hash(key);

            for (auto it : table[index])
            {
			    if (it.first == key)
				{
					table[index].remove(it);
                    iteratorList.remove(it);
					count--;
					break;
				}
            }
        }
	}

	bool contains(const Key& key)
	{
		return find(key);
	}
	
	T& operator[](const Key& key)
	{
		auto& bucket = table[hash(key)];
		for (auto it = bucket.begin(); it != bucket.end(); it++)
		{
			if (it->first == key)
			{
				return it->second;
			}
		}
		return nullptr;
	}
	
	typename std::list<std::pair<const Key, T>>::iterator begin()
	{
		return iteratorList.begin();
	}
	
	typename std::list<std::pair<const Key, T>>::iterator end()
	{
		return iteratorList.end();
	}
	
	typename std::list<std::pair<const Key, T>>::const_iterator cbegin()
	{
		return iteratorList.cbegin();
	}
	
	typename std::list<std::pair<const Key, T>>::const_iterator cend()
	{
		return iteratorList.cend();
	}
	
	typename std::list<std::pair<const Key, T>>::reverse_iterator rbegin()
	{
		return iteratorList.rbegin();
	}
	
	typename std::list<std::pair<const Key, T>>::reverse_iterator rend()
	{
		return iteratorList.rend();
	}
	
	typename std::list<std::pair<const Key, T>>::const_reverse_iterator crbegin()
	{
		return iteratorList.crbegin();
	}
	
	typename std::list<std::pair<const Key, T>>::const_reverse_iterator crend()
	{
		return iteratorList.crend();
	}
};


