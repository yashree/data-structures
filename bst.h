#include <stdlib.h>
#include <iostream>
using namespace std;

class Node {
  private:
    Node* leftNode;
    Node* rightNode;
    int element;
    int Lcount;
    int Rcount;	
  public:
    Node(const int&);
    Node* getLeftNode(void);
    void setLeftNode(Node*);
    Node* getRightNode(void);
    void setRightNode(Node*);
    int getElement(void) const;
    void setElement(const int&);
    int getLeftNodevisited(void) const;
    void addToLeftNodevisited(void);
	int getRightNodevisited(void) const;
    void addToRightNodevisited(void);
	
};

class BST {
private:
  Node* root;
  int visited;
  void recursiveInsert(Node*, Node*);
  int inOrder(Node*, const int&, const int&);
  int findPos(const int&, Node*);
public:
  BST();
  BST(const int&);
  void insert(const int&);
  int Range(const int&, const int&);
  int nthLargest(const int&);
  int getCount(void) const;
};
