#include <iostream>
#include "bst.h"

using namespace std;

const int Size = 10;

int main() {
  int myArray[Size] = {50, 68, 85, 75, 20, 15, 90, 45, 30, 9};
  BST* bst = new BST();

  for (int i = 0; i < Size; i++) {
    bst->insert(myArray[i]);
  }

  cout << "The tree should have 10 elements in the tree:\n" << boolalpha << (bst->getCount() == 10) << endl << endl; 
  cout << "The 2nd largest should be 85:\n" << bst->nthLargest(2) << boolalpha << (bst->nthLargest(2) == 85) << endl << endl; 
  cout << "The 17th largest should return an error message:" << endl;
  cout << bst->nthLargest(17) << endl << endl;	//out of bounds check
  cout << "The -3rd largest should return an error message:" << endl;
  cout << bst->nthLargest(-3) << endl << endl;	//negative number check
  cout << "The range between 25 and 85 should print 7 keys and have 7 checks:" << endl;
  cout << boolalpha << (bst->Range(20, 85)  == 7) << endl << endl;
  cout << "The range between 25 and 86 should print 7 keys and have 8 checks:" << endl;
  cout << boolalpha << (bst->Range(20, 86)  == 8) << endl << endl;
  cout << "Inserting 30 into BST should increment count by 1:" << endl;
  bst->insert(80);	//insert test
  cout << boolalpha << (bst->getCount() == 11) << endl << endl;
  cout << "The range between 25 and 85 should print 8 keys and have 8 checks:" << endl;
  cout << boolalpha << (bst->Range(20, 85)  == 8) << endl << endl;
  cout << "The 3rd largest should be 75:\n" << bst->nthLargest(3) << boolalpha << (bst->nthLargest(3) == 75) << endl;

  return 0;
}
