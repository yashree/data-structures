#include <string>

template<typename E, typename Comp> class heap
{
private:
	E* Heap;
	int maxsize;
	int n;
	void shiftdown(int pos);
public:
	heap(E* h, int num, int max);
	int size() const;
	bool isLeaf(int pos) const;
	int leftchild(int pos) const;
	int rightchild(int pos) const;
	int parent(int pos) const;
	void buildHeap();
	void insert(const E& it);
	E removefirst();
	E remove(int pos);
};

// factory function
template<typename E, typename Comp>
heap<E, Comp> *createHeap(E* h, int num, int max);
