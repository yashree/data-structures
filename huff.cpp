
#include "huff.h"
#include <iostream>
#include <string>
using namespace std;

template<typename E>
inline void swap(E A[], int i, int j) {
	E temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

template <typename E>
LeafNode<E>::LeafNode(const E& val, int freq)
{
	it = val; wgt = freq;
}

template <typename E>
int LeafNode<E>::weight() { return wgt; }

template <typename E>
E LeafNode<E>::val() { return it; }

template <typename E>
bool LeafNode<E>::isLeaf() { return true; }



template <typename E>
IntlNode<E>::IntlNode(HuffNode<E>* l, HuffNode<E>* r)
{
	wgt = l->weight() + r->weight();
	lc = l;
	rc = r;
}

template <typename E>
int IntlNode<E>::weight() { return wgt; }

template <typename E>
bool IntlNode<E>::isLeaf() { return false; }
template <typename E>
void HuffTree<E>::traverse(HuffNode<E>* node) {

	if (node == NULL)return;
	if (node->isLeaf())
		cout << ((LeafNode<E>*)node)->val() << " " ;
	else {
		traverse(((IntlNode<E>*)node)->left());
		traverse(((IntlNode<E>*)node)->right());
	}
}

template <typename E>
HuffNode<E>* IntlNode<E>::left() const { return lc; }

template <typename E>
void IntlNode<E>::setLeft(HuffNode<E>* b)
{
	lc = (HuffNode<E>*)b;
}
template <typename E>
HuffNode<E>* IntlNode<E>::right() const { return rc; }

template <typename E>
void IntlNode<E>::setRight(HuffNode<E>* b)
{
	rc = (HuffNode<E>*) b;
}

template <typename E>
HuffTree<E>::HuffTree(E& val, int freq)
{
	Root = new LeafNode<E>(val, freq);
}
template <typename E>
HuffTree<E>::HuffTree(HuffTree<E>* l, HuffTree<E>* r)
{
	Root = new IntlNode<E>(l->root(), r->root());
}
template <typename E>
HuffNode<E>* HuffTree<E>::root() { return Root; }

template <typename E>
int HuffTree<E>::weight() { return Root->weight(); }

template <typename E>
void HuffTree<E> ::generateCode(HuffNode<E>* node, string code)
{
	if (node == NULL) return;
	if (node->isLeaf())
		cout << ((LeafNode<E>*)node)->val() << ": " << code << "\n";
	else {
		generateCode(((IntlNode<E>*)node)->left(), code + "0");
		generateCode(((IntlNode<E>*)node)->right(), code + "1");
	}
}
template <typename E>
void HuffTree<E> ::generateCode2(HuffNode<E>* node, string code, string a[])
{
	static int i = 0;
	if (node == NULL) return;
	if (node->isLeaf())
	{
		a[i] = code;
		i++;
	}

	else {
		generateCode2(((IntlNode<E>*)node)->left(), code + "0", a);
		generateCode2(((IntlNode<E>*)node)->right(), code + "1", a);
	}
}

class minTreeComp {
public:
	static bool prior(HuffTree<char>* x, HuffTree<char>* y)
	{
		return x->weight() < y->weight();
	}
};





