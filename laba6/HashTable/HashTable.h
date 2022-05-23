#pragma once

#include <functional>
#include "List.h"
#include <ctime>
//#include <vector>
//#include <forward_list>
//#include <list>
//#include <stdexcept>

template<typename Key, typename T, typename Hash = std::hash<Key>, typename KeyEqual = std::equal_to<Key>>
class HashTable {
private:
    int size = 50;
    int count;
    List<std::pair<const Key, T>*>* table;
    int hash(Key key) {
        return Hash()(key) % size;
    }
public:
    HashTable(int size = 50)
    {
        this->size = size;
        count = 0;
        table = new List<std::pair<const Key, T>*>[size];

    }
    ~HashTable()
    {
        delete[] table;
    }

    void insert(Key key, T data)
    {
        int index = hash(key);
        table[index].push_back(new std::pair<const Key, T>(key, data));
        count++;
    }

    bool find(Key key, T data)
    {
        auto& bucket = table[hash(key)];
        Node<std::pair<const Key, T>*>* temp = bucket.GetFirst();
        while (temp != nullptr) {
            if (temp->item->second == data) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    void remove(Key key, T data) {
        int index = hash(key);
        table[index].Remove(&std::pair<Key, T>(key, data));
    }

    int findMax()
    {
        int max = 0, id = 0;

        for (int i = 0; i < size; i++)
        {
            Node<std::pair<const Key, T>*>* temp = table[i].GetFirst();
            while (temp != nullptr)
            {
                if (temp->item->second > max)
                {
                    max = temp->item->second;
                    id = i;
                }
                temp = temp->next;
            }
        }

        return id;
    }
	
    List<std::pair<const Key, T>*>& operator[](int index)
	{
		return table[index];
	}
	
    int getSize()
    {
		return size;
    }
	
	// rehash
	void rehash()
	{
		int oldSize = size;
		size = size * 2;
		List<std::pair<const Key, T>*>* oldTable = table;
		table = new List<std::pair<const Key, T>*>[size];
		for (int i = 0; i < oldSize; i++)
		{
			Node<std::pair<const Key, T>*>* temp = oldTable[i].GetFirst();
			while (temp != nullptr)
			{
				insert(temp->item->first, temp->item->second);
				temp = temp->next;
			}
		}
		delete[] oldTable;
	}
	
	QString GetBucket(int index)
	{
		QString str;
		Node<std::pair<const Key, T>*>* temp = table[index].GetFirst();
		while (temp != nullptr)
		{
			str += QString::number(temp->item->first) + " ";
			temp = temp->next;
		}
		return str;
	}
};


