#include"List.h"
#include<cstdlib>
#include<iostream>

template<class E>
class Link  //Link template class
{
private:
    static Link<E>*	freeList;	//three static private member variables to keep track of the free list, the number of active
    static int	activenodes;    //nodes, and the number of free nodes.
    static int	freenodes;	
public:
    E data;
    Link<E>* prev;
    Link<E>* next;

Link()							//constructor 1
	{
		activenodes++;			//incrementing the number of active links on creation of a new link

		if (freenodes != 0)
		{
			freenodes--;		//decrementing the freeList because the new link is allocated from here
		}
	}

Link(E newData, Link<E>* newPrev = 0, Link<E>* newNext = 0) : data(newData), prev(newPrev), next(newNext)  //constructor 2
    {
        activenodes++;			//incrementing the number of active links on creation of a new link

        if (freenodes != 0)		//decrementing the freeList because the new link is allocated from here
        {		
            freenodes--;
        }
    }

    //template<class E>
 void* operator new(std::size_t) 					// Overloaded new operator
 {  
    if (freeList == NULL) return ::new Link; 	// Create space
    Link<E>* temp = freeList; 					// Can take from freeList
    freeList = freeList->next;
	freenodes--;
    return temp;                 				// Return the link
}

//template<class E>
void operator delete(void* p)
{
    activenodes--;
    freenodes++;

    Link<E>* linkToDelete = static_cast<Link<E>*> (p); //static_cast is used to convert from pointer to base class to pointer to derived class
    linkToDelete->next = 0;
    linkToDelete->prev = 0;
    if (freeList == 0)
    {
        freeList = linkToDelete;
        return;
    }
    //inserting this new free link to the head of the freeList
    freeList->prev = linkToDelete;
    linkToDelete->next = freeList;
    freeList = linkToDelete;
}
    
    Link<E>* getfreeList();				//getter functions for the private data members
    int getactivenodes();
    int getfreenodes();
};

//defining the static class members
template<class E>
Link<E>* Link<E>::freeList = 0;

template<class E>
int Link<E>::activenodes = 0;

template<class E>
int Link<E>::freenodes = 0;

template<class E>
Link<E>* Link<E>::getfreeList()
{
    return freeList;
}

template<class E>
int Link<E>::getactivenodes()
{
    return activenodes;
}

template<class E>
int Link<E>::getfreenodes()
{
    return freenodes;
}

template<class E>
class DLList : public List<E>
{
private:
    Link<E>*	curr;
    Link<E>*	head;
    Link<E>*	tail;
    void deleteHead();
public:
    DLList(Link<E>* newcurr = 0, Link<E>* newHead = 0, Link<E>* newTail = 0) : curr(newcurr), head(newHead), tail(newTail)
    {}
    ~DLList();
    void clear();
    void prepend(const E& item);
    void append(const E& item);
    bool moveToStart();
    bool moveToEnd();
    bool next();
    bool prev();
	int numActive();
    int numFree();
    const E* getValue() const;
    void printList();

};

template<class E>
DLList<E>::~DLList()		//Destructor
{}

template<class E>
void DLList<E>::deleteHead()
{
    if (head == 0 || head == tail)
    {
        delete head;
        head = 0;
        tail = 0;
        curr = 0;
        return;
    }

    Link<E>* oldHead = head;
    head = head->next;
    //this is calling the overloaded version of the delete operator
    delete oldHead;
}

template<class E>
void DLList<E>::clear()
{
    while (head != 0)
    {
        deleteHead();
    }
}

template<class E>
void DLList<E>::prepend(const E& item) 
{
	Link<E>* newLink = new Link<E>(item); //created a new link

    if (head == 0)							//for an empty list, simply add the link
    {
		head = newLink;
		tail = newLink;
		curr = newLink;
        return;
    }

    head->prev = newLink;
    newLink->next = head;
	head = newLink;
}

template<class E>
void DLList<E>::append(const E& item)
{
    Link<E>* newLink = new Link<E>(item);

    if (head == 0)
    {
        head = newLink;
        tail = newLink;
        curr = newLink;
        return;
    }

    newLink->prev = tail;
    tail->next = newLink;
    tail = newLink;
}


template<class E>
bool DLList<E>::moveToStart()
{
    if (head == 0)
    {
        return false;
    }

    curr = head;
    return true;
}

template<class E>
bool DLList<E>::moveToEnd()
{
    if (head == 0)
    {
        return false;
    }

    curr = tail;
    return true;
}

template<class E>
bool DLList<E>::next()
{
    if (head == 0 || curr->next == 0)
    {
        return false;
    }

    curr = curr->next;
    return true;
}


template<class E>
bool DLList<E>::prev()
{
    if (head == 0 || curr->prev == 0)
    {
        return false;
    }

    curr = curr->prev;
    return true;
}



template<class E>
const E* DLList<E>::getValue() const
{
	const E* value = &(curr->data);
    return value;
}


template<class E>
int DLList<E>::numActive()
{
    return head->getactivenodes();
}

template<class E>
int DLList<E>::numFree()
{
    return head->getfreenodes();
}

template<class E>
void DLList<E>::printList()
{
    using namespace std;

 Link<E>* curr = head;
    while (curr != 0)
    {
        cout << curr->data << ' ';
        curr = curr->next;
    }
    cout << endl;
}

// Explicit instantiation
template<typename E>
List<E> *createList()
{ return new DLList<int>; }
