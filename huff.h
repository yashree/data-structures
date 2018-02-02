#include <string>
using namespace std;
template<typename E> class HuffNode
{
public:
	virtual ~HuffNode() {}
	virtual int weight() = 0;
	virtual bool isLeaf() = 0;
};

template<typename E> class LeafNode : public HuffNode<E>
{
private:
	E it;
	int wgt;
public:
	LeafNode(const E& val, int freq);
	int weight();
	E val();
	bool isLeaf();
};
template<typename E> class IntlNode : public HuffNode<E>
{
private:
	HuffNode<E>* lc;
	HuffNode<E>* rc;
	int wgt;
public:
	IntlNode(HuffNode<E>* l, HuffNode<E>* r);
	int weight();
	bool isLeaf();
	HuffNode<E>* left() const;
	void setLeft(HuffNode<E>* b);
	HuffNode<E>* right() const;
	void setRight(HuffNode<E>* b);
};
template<typename E> class HuffTree
{
private:
	HuffNode<E>* Root;
public:
	HuffTree(E& val, int freq);
	HuffTree(HuffTree<E>* l, HuffTree<E>* r);
	~HuffTree() {};
	HuffNode<E>* root();
	int weight();
	void traverse(HuffNode<E>* node);
	void generateCode(HuffNode<E>* node, string code);
	void generateCode2(HuffNode<E>* node, string code, string a[]);
	// Factory functions (as friends, so they can access Root)
	friend HuffTree *createLeaf(char val, int freq);
	friend HuffTree *createIntl(HuffTree* l, HuffTree* r);
};

template <typename E> HuffTree<E>*
buildHuff(HuffTree<E>** TreeArray, int count);
