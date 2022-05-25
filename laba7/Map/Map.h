#pragma once

#include <functional>
#include <list>

template<class Key, class T, class Compare = std::less<Key>>
class Map
{
private:
	
	struct Node
	{
		std::pair<const Key, T> data;
		Node* left;
		Node* right;
		Node* parent;
		short height;
		
		Node(Key key, T data) : data(std::pair<const Key, T>(key, data)), left(nullptr), right(nullptr), height(1), parent(nullptr) {}
	};

	std::list<std::pair<const Key, T>> list_of_nodes;
	
	Node* root;
	int treeSize;
	int* countOfEachDepth;

	short height(Node* p)
	{
		return p ? p->height : 0;
	}

	short bfactor(Node* p)
	{
		return height(p->right) - height(p->left);
	}

	void fixheight(Node* p)
	{
		short hl = height(p->left);
		short hr = height(p->right);
		p->height = (hl > hr ? hl : hr) + 1;
	}

	Node* rotateright(Node* p) // правый поворот вокруг p
	{
		Node* q = p->left;
		p->left = q->right;
		q->right = p;

		if (p->left != nullptr)
			p->left->parent = p;

		q->parent = p->parent;
		p->parent = q;

		if (p == root)
			root = q;

		fixheight(p);
		fixheight(q);
		return q;
	}

	Node* rotateleft(Node* q) // левый поворот вокруг q
	{
		Node* p = q->right;
		q->right = p->left;
		p->left = q;

		if (q->right != nullptr)
			q->right->parent = q;

		p->parent = q->parent;
		q->parent = p;

		if (q == root)
			root = p;

		fixheight(q);
		fixheight(p);
		return p;
	}

	Node* balance(Node* p) // балансировка узла p
	{
		fixheight(p);

		if (bfactor(p) == 2)
		{
			if (bfactor(p->right) < 0)
				p->right = rotateright(p->right);
			return rotateleft(p);
		}
		if (bfactor(p) == -2)
		{
			if (bfactor(p->left) > 0)
				p->left = rotateleft(p->left);
			return rotateright(p);
		}
		return p; // балансировка не нужна
	}

	Node* findmin(Node* p) // поиск узла с минимальным ключом в дереве p 
	{
		return p->left ? findmin(p->left) : p;
	}

	Node* removemin(Node* p) // удаление узла с минимальным ключом из дерева p
	{
		if (p->left == nullptr)
			return p->right;
		p->left = removemin(p->left);
		if (p->left != nullptr)
		{
			p->left->parent = p;
		}
		return balance(p);
	}
public:
	Map() : root(nullptr), treeSize(0) {}


	void getSize()
	{
		return treeSize;
	}

	int* getCountOfEachDepth()
	{
		return countOfEachDepth;
	}

	void inContOfDepth(int size)
	{
		countOfEachDepth = new int[size]();
	}

	Node* getRoot()
	{
		return root;
	}

	Node* insert(Node* p, Key key, T k) // вставка ключа k в дерево с корнем p
	{
		if (this->find(root, key) != nullptr)
		{
			return nullptr;
		}
		
		if (!p)
		{
			treeSize++;
			if (root == nullptr)
			{
				root = new Node(key, k);
				root->parent = nullptr;
				list_of_nodes.push_back(std::pair<const Key, T>(key, k));
				list_of_nodes.sort();
				return root;
			}
			else
			{
				return new Node(key, k);
			}
		}

		if (key < p->data.first)
		{
			p->left = insert(p->left, key, k);
			if (p->left != nullptr)
				p->left->parent = p;
		}
		else
		{
			p->right = insert(p->right, key, k);
			if (p->right != nullptr)
				p->right->parent = p;
		}

		return balance(p);
	}

	Node* remove(Node* p, Key key) // удаление ключа k из дерева p
	{
		if (!p) return 0;

		if (key < p->data.first)
		{
			p->left = remove(p->left, key);
			if (p->left != nullptr)
				p->left->parent = p;
		}
		else if (key > p->data.first)
		{

			p->right = remove(p->right, key);
			if (p->right != nullptr)
				p->right->parent = p;

		}
		else //  k == p->key 
		{
			Node* q = p->left;
			Node* r = p->right;

			list_of_nodes.remove(p->data);
			
			delete p;

			if (p == root)
			{
				root = nullptr;
			}

			p = nullptr;

			if (!r)
			{
				if (root == nullptr)
					root = q;
				return q;
			}

			Node* min = findmin(r);
			min->right = removemin(r);

			if (min->right != nullptr)
				min->right->parent = min;

			min->left = q;

			if (min->left != nullptr)
				min->left->parent = min;

			if (root == nullptr)
			{
				root = min;
				root->parent = nullptr;
			}
			treeSize--;
			return balance(min);
		}
		return balance(p);
	}

	Node* find(Node* p, Key key) // поиск ключа k в дереве p
	{
		if (!p) return nullptr;

		if (key < p->data.first)
		{
			if (p->left == nullptr)
				return nullptr;
			return find(p->left, key);
		}
		else if (key > p->data.first)
		{
			if (p->right == nullptr)
				return nullptr;
			return find(p->right, key);
		}
		else
		{
			return p;
		}
	}

	struct Iterator
	{
		Node* current;
		Node* root;
		
		Iterator(Node* root) : current(root), root(root) {}
		Iterator(Node* root, Node* current) : current(current), root(root) {}
		
		Iterator& operator++()
		{
			if (current->right != nullptr)
			{
				current = current->right;
				while (current->left != nullptr)
				{
					current = current->left;
				}
			}
			else
			{
				Node* p = current;
				while (p->parent != nullptr && p->parent->right == p)
				{
					p = p->parent;
				}
				current = p->parent;
			}
			return *this;
		}
		
		Iterator operator++(int)
		{
			Iterator tmp = *this;
			++*this;
			return tmp;
		}

		bool operator==(const Iterator& other)
		{
			return current == other.current;
		}
		
		bool operator!=(const Iterator& other)
		{
			return current != other.current;
		}
		
		std::pair<const Key, T>& operator*()
		{
			return current->data;
		}
		
		std::pair<const Key, T>* operator->()
		{
			return &current->data;
		}
	};

	struct constIterator
	{
		Node* current;
		Node* root;

		constIterator(Node* root) : current(root), root(root) {}
		constIterator(Node* root, Node* current) : current(current), root(root) {}

		constIterator& operator++()
		{
			if (current->right != nullptr)
			{
				current = current->right;
				while (current->left != nullptr)
				{
					current = current->left;
				}
			}
			else
			{
				Node* p = current;
				while (p->parent != nullptr && p->parent->right == p)
				{
					p = p->parent;
				}
				current = p->parent;
			}
			return *this;
		}

		constIterator operator++(int)
		{
			constIterator tmp = *this;
			++*this;
			return tmp;
		}

		bool operator==(const constIterator& other)
		{
			return current == other.current;
		}
		
		bool operator!=(const constIterator& other)
		{
			return current != other.current;
		}
		
		const std::pair<const Key, T>& operator*()
		{
			return current->data;
		}
	};
	
	struct reverseIterator
	{
		Node* current;
		Node* root;

		reverseIterator(Node* root) : current(root), root(root) {}
		reverseIterator(Node* root, Node* current) : current(current), root(root) {}

		reverseIterator& operator++()
		{
			if (current->left != nullptr)
			{
				current = current->left;
				while (current->right != nullptr)
				{
					current = current->right;
				}
			}
			else
			{
				Node* p = current;
				while (p->parent != nullptr && p->parent->left == p)
				{
					p = p->parent;
				}
				current = p->parent;
			}
			return *this;
		}

		reverseIterator operator++(int)
		{
			reverseIterator tmp = *this;
			++*this;
			return tmp;
		}

		bool operator==(const reverseIterator& other)
		{
			return current == other.current;
		}
		
		bool operator!=(const reverseIterator& other)
		{
			return current != other.current;
		}
		
		std::pair<const Key, T>& operator*()
		{
			return current->data;
		}
	};
	
	struct constReverseIterator
	{
		Node* current;
		Node* root;

		constReverseIterator(Node* root) : current(root), root(root) {}
		constReverseIterator(Node* root, Node* current) : current(current), root(root) {}

		constReverseIterator& operator++()
		{
			if (current->left != nullptr)
			{
				current = current->left;
				while (current->right != nullptr)
				{
					current = current->right;
				}
			}
			else
			{
				Node* p = current;
				while (p->parent != nullptr && p->parent->left == p)
				{
					p = p->parent;
				}
				current = p->parent;
			}
			return *this;
		}

		constReverseIterator operator++(int)
		{
			constReverseIterator tmp = *this;
			++*this;
			return tmp;
		}

		bool operator==(const constReverseIterator& other)
		{
			return current == other.current;
		}

		bool operator!=(const constReverseIterator& other)
		{
			return current != other.current;
		}

		const std::pair<const Key, T>& operator*()
		{
			return current->data;
		}
	};
	
	struct ListIterator {
		typedef typename std::list<std::pair<Key, T>>::iterator iterator;
		iterator it;
		ListIterator(iterator it) : it(it) {}
		
		std::pair<Key, T> operator*() {
			return *it;
		}
		ListIterator operator++() {
			++it;
			return *this;
		}
		ListIterator operator++(int) {
			ListIterator tmp = *this;
			++it;
			return tmp;
		}
		bool operator==(const ListIterator& other) {
			return it == other.it;
		}
		bool operator!=(const ListIterator& other) {
			return it != other.it;
		}
	};

	struct constListIterator {
		typedef typename std::list<std::pair<Key, T>>::const_iterator iterator;
		iterator it;
		constListIterator(iterator it) : it(it) {}
		
		std::pair<Key, T> operator*() {
			return *it;
		}
		constListIterator operator++() {
			++it;
			return *this;
		}
		constListIterator operator++(int) {
			constListIterator tmp = *this;
			++it;
			return tmp;
		}
		bool operator==(const constListIterator& other) {
			return it == other.it;
		}
		bool operator!=(const constListIterator& other) {
			return it != other.it;
		}
	};
	
	Iterator begin()
	{
		if (root == nullptr)
			return Iterator(root);
		Node* p = root;
		while (p->left != nullptr)
		{
			p = p->left;
		}
		return Iterator(root, p);
	}

	Iterator end()
	{
		return nullptr;
	}
	
	constIterator cbegin() const
	{
		if (root == nullptr)
			return constIterator(root);
		Node* p = root;
		while (p->left != nullptr)
		{
			p = p->left;
		}
		return constIterator(root, p);
	}
	
	constIterator cend() const
	{
		return nullptr;
	}
	
	reverseIterator rbegin()
	{
		if (root == nullptr)
			return reverseIterator(root);
		Node* p = root;
		while (p->right != nullptr)
		{
			p = p->right;
		}
		return reverseIterator(root, p);
	}
	
	reverseIterator rend()
	{
		return nullptr;
	}
	
	constReverseIterator crbegin() const
	{
		if (root == nullptr)
			return constReverseIterator(root);
		Node* p = root;
		while (p->right != nullptr)
		{
			p = p->right;
		}
		return constReverseIterator(root, p);
	}
	
	constReverseIterator crend() const
	{
		return nullptr;
	}

	ListIterator lbegin()
	{
		return ListIterator(list.begin());
	}
	
	ListIterator lend()
	{
		return ListIterator(list.end());
	}

	constListIterator clbegin() const
	{
		return constListIterator(list.cbegin());
	}
	
	constListIterator clend() const
	{
		return constListIterator(list.cend());
	}
};