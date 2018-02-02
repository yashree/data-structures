#include "Graphm.h"
#include "ParPtrTree.h"
#include "heap.cpp"
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
  int array[10] = {5, 2, 3, 9, 10, 7, 4, 6, 8, 1};

  heap<int, minComp> *h = new heap<int, minComp>(array, 10, 10);

  cout << "Left Child: " << h->leftchild(0) << endl;
  cout << "Left Child: " << h->rightchild(0) << endl;
  cout << "Parent of position 5: " << h->parent(5) << endl << endl;

  ParPtrTree *ptrTree = new ParPtrTree(10);

  ptrTree->UNION(1, 2);
  ptrTree->UNION(3, 2);
  ptrTree->UNION(4, 5);
  ptrTree->UNION(4, 2);

  for (int i = 0; i < 10; i++) {
    cout << "Element: " << i << endl;
    cout << "Parent: " << ptrTree->getParent(i) << endl;
    cout << "Weight: " << ptrTree->getWeight(i) << endl << endl;
  }

  Graph *G = read_graph("bkexamp.gph");
  write_graph(G, "FinalGraph.gph");

  return 0;
}
