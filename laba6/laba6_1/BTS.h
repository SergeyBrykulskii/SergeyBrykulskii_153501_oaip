#pragma once

// inplementation of AVL tree
template<class T>
struct Node
{
	T key;
	Node* left;
	Node* right;
	Node* parent;
	short height;

	Node() : key(T()), left(nullptr), right(nullptr), height(0), parent(nullptr) {}

	Node(T key) : key(key), left(nullptr), right(nullptr), height(1), parent(nullptr) {}
};

template<class T>
class AVLTree
{
private:

	Node<T>* root;
	int treeSize;
	int* countOfEachDepth;
	
	short height(Node<T>* p)
	{
		return p ? p->height : 0;
	}

	short bfactor(Node<T>* p)
	{
		return height(p->right) - height(p->left);
	}
	
	void fixheight(Node<T>* p)
	{
		short hl = height(p->left);
		short hr = height(p->right);
		p->height = (hl > hr ? hl : hr) + 1;
	}
	
	Node<T>* rotateright(Node<T>* p) // правый поворот вокруг p
	{
		Node<T>* q = p->left;
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
	
	Node<T>* rotateleft(Node<T>* q) // левый поворот вокруг q
	{
		Node<T>* p = q->right;
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
	
	Node<T>* balance(Node<T>* p) // балансировка узла p
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

	Node<T>* findmin(Node<T>* p) // поиск узла с минимальным ключом в дереве p 
	{
		return p->left ? findmin(p->left) : p;
	}

	Node<T>* removemin(Node<T>* p) // удаление узла с минимальным ключом из дерева p
	{
		if (p->left == 0)
			return p->right;
		p->left = removemin(p->left);
		if (p->left != nullptr)
		{
			p->left->parent = p;
		}
		return balance(p);
	}
public:
	AVLTree() : root(nullptr), treeSize(0) {}
	
	
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
	
	Node<T>* getRoot()
	{
		return root;
	}
	
	Node<T>* insert(Node<T>* p, T k) // вставка ключа k в дерево с корнем p
	{
	
		if (!p)
		{
			treeSize++;
			if (root == nullptr)
			{
				root = new Node<T>(k);
				return root;
			}
			else
			{
				return new Node<T>(k);
			}
		}
		
		if (k < p->key)
		{
			p->left = insert(p->left, k);
			if (p->left != nullptr)
				p->left->parent = p;
		}
		else
		{
			p->right = insert(p->right, k);
			if (p->right != nullptr)
				p->right->parent = p;
		}
		
		return balance(p);
	}

	Node<T>* remove(Node<T>* p, T k) // удаление ключа k из дерева p
	{
		if (!p) return 0;
		
		if (k < p->key)
		{
			p->left = remove(p->left, k);
			if (p->left != nullptr)
				p->left->parent = p;
		}
		else if (k > p->key)
		{
			
		  	p->right = remove(p->right, k);
			if (p->right != nullptr)
				p->right->parent = p;

		}
		else //  k == p->key 
		{
			Node<T>* q = p->left;
			Node<T>* r = p->right;
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
			
			Node<T>* min = findmin(r);
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
	
	Node<T>* find(Node<T>* p, T k) // поиск ключа k в дереве p
	{
		if (!p) return nullptr;
		
		if (k < p->key)
		{
			if (p->left == nullptr)
				return nullptr;
			return find(p->left, k);
		}
		else if (k > p->key)
		{
			if (p->right == nullptr)
				return nullptr;
			return find(p->right, k);
		}
		else
		{
			return p;
		}
	}
	
	void Calculate(Node<T>* p) 
	{	
		if (p) {
			Calculate(p->left);
			Calculate(p->right);
			countOfEachDepth[p->height - 1]++;
		}
	}
};