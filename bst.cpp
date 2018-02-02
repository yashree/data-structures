#include "bst.h"

Node::Node(const int &elem) {
  rightNode = leftNode = NULL;
  element = elem;
  Lcount = 0; //keeps the count of the lesser value nodes 
  Rcount = 0; //keeps the count of the greater value nodes 
}
Node* Node::getLeftNode() {
  return leftNode;
}
void Node::setLeftNode(Node* node) {
  leftNode = node;
}
Node* Node::getRightNode() {
  return rightNode;
}
void Node::setRightNode(Node* node) {
  rightNode = node;
}
int Node::getElement() const {
  return element;
}
void Node::setElement(const int& elem) {
  element = elem;
}
int Node::getLeftNodeCount(void) const {
  return Lcount;
}
void Node::addToLCount(void) {
  Lcount++;
}
int Node::getRightNodeCount(void) const {
  return Rcount;
}
void Node::addToRCount(void)
{
  Rcount++;
}

BST::BST()
{
  root = NULL;
  count = 0;
}
BST::BST(const int &elem)
{
  root = new Node(elem);
  count++;
}
void BST::insert(const int &elem) 
{ //for handling the empty tree special case
  Node* t = new Node(elem); 
  count++;
  if (root == NULL)
  {
    root = t;
  }
  else
    recursiveInsert(t, root);
}
void BST::recursiveInsert(Node* t, Node* curr) 
{ //if the node is not empty 
  if (curr->getElement() > t->getElement()) 
  {
    curr->addToLCount();
    if (curr->getLeftNode() == NULL)
      curr->setLeftNode(temp);
    else
      recursiveInsert(temp, curr->getLeftNode());
  }
  else 
  {
    curr->addToRCount();
    if (curr->getRightNode() == NULL)
      curr->setRightNode(temp);
    else
      recursiveInsert(temp, curr->getRightNode());
  }
}
int BST::Range(const int &start, const int &end) 
{
  return inOrder(root, start, end);
}
int BST::inOrder(Node* curr, const int &start, const int &end) 
{ //printing the values in the tree in decending order
  int count = 1;
  if (curr->getRightNode() != NULL && curr->getElement() < end) //working with the rightnode first because we want to find the largest 
    count = count + inOrder(curr->getRightNode(), start, end); //value first
  if (curr->getElement() >= start && curr->getElement() <= end)
    cout << "Key: "<< curr->getElement() << endl;
  if (curr->getLeftNode() != NULL && curr->getElement() > start)
    count = count + inOrder(curr->getLeftNode(), start, end);
  return count;
}
int BST::nthLargest(const int& pos)
{	//if the vlaue of pos exceedes the vlaues existing in the binary tree
  if (pos <= count && pos > 0)
    return findPos(pos, root);
  else 
  {
    cout << "There are not that many elements in the tree" << endl;
    return 0;
  }
}
int BST::findPos(const int& pos, Node* curr) 
{
if(curr->getRightNodeCount() == pos - 1) //in this subtree there are pos-1 elements greater than the root
    return curr->getElement(); //hence the value we are looking for is in the root
if (curr->getRightNodeCount() >= pos) //the position of the max element is in the right subtree
    findPos(pos, curr->getRightNode());
else
    findPos(pos - curr->getRightNodeCount() - 1, curr->getLeftNode()); // the max element is in the left subtree
}
int BST::getCount() const
{return count;}	//returns the number of elements visited

