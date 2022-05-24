#pragma once

#include <functional>

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
		
		//Node() : data(), left(nullptr), right(nullptr), height(0), parent(nullptr) {}

		Node(Key key, T data) : data(std::pair<const Key, T>(key, data)), left(nullptr), right(nullptr), height(1), parent(nullptr) {}
	};

	

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

	Node* rotateright(Node* p) // ������ ������� ������ p
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

	Node* rotateleft(Node* q) // ����� ������� ������ q
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

	Node* balance(Node* p) // ������������ ���� p
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
		return p; // ������������ �� �����
	}

	Node* findmin(Node* p) // ����� ���� � ����������� ������ � ������ p 
	{
		return p->left ? findmin(p->left) : p;
	}

	Node* removemin(Node* p) // �������� ���� � ����������� ������ �� ������ p
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

	Node* insert(Node* p, Key key, T k) // ������� ����� k � ������ � ������ p
	{

		if (!p)
		{
			treeSize++;
			if (root == nullptr)
			{
				root = new Node(key, k);
				return root;
			}
			else
			{
				return new Node(key, k);
			}
		}

		if (key < p->data->first)
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

	Node* remove(Node* p, Key key, T k) // �������� ����� k �� ������ p
	{
		if (!p) return 0;

		if (key < p->data->first)
		{
			p->left = remove(p->left, key, k);
			if (p->left != nullptr)
				p->left->parent = p;
		}
		else if (key > p->data->key)
		{

			p->right = remove(p->right, key, k);
			if (p->right != nullptr)
				p->right->parent = p;

		}
		else //  k == p->key 
		{
			Node* q = p->left;
			Node* r = p->right;
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
				root = min;
			treeSize--;
			return balance(min);
		}
		return balance(p);
	}

	Node* find(Node* p, T key) // ����� ����� k � ������ p
	{
		if (!p) return nullptr;

		if (key < p->data->first)
		{
			if (p->left == nullptr)
				return nullptr;
			return find(p->left, key);
		}
		else if (key > p->data->first)
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
		Iterator& operator--()
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
		
		Iterator operator++(int)
		{
			Iterator tmp = *this;
			++*this;
			return tmp;
		}
		
		Iterator operator--(int)
		{
			Iterator tmp = *this;
			--*this;
			return tmp;
		}
	};
};