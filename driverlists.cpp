#include"List.h"
#include"lists.cpp"
#include<iostream>

template<class E>
class List;

template<class E>
class Link;

template<class E>
class DLList;

int main()
{
    using namespace std;
 DLList<int> mylist;

    cout << "Prepending: 1" << endl;
    mylist.prepend(1);
    mylist.printList();

    cout << "Prepending: 2" << endl;
    mylist.prepend(2);
    mylist.printList();

    cout << "Prepending: 3" << endl;
    mylist.prepend(3);
    mylist.printList();
       
    cout << "Append: 9" << endl;
    mylist.append(9);
    mylist.printList();
    cout << "Append: 8" << endl;
    mylist.append(8);
    mylist.printList();
    cout << "Append: 7" << endl;
    mylist.append(7);
    mylist.printList();
    cout << "Current data: " << *mylist.getValue() << endl;

    cout << "Moving to end" << endl;
    mylist.moveToEnd();
    cout << "Current data: " << *mylist.getValue() << endl;

    cout << "Moving to start" << endl;
    mylist.moveToStart();
    cout << "Current data: " << *mylist.getValue() << endl;

    cout << "Iterating through list with next function" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << "Current data: " << *mylist.getValue() << endl;
        cout << "Next: " << mylist.next() << endl;
    }

    cout << "Iterating through list with prev function" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << "Current data: " << *mylist.getValue() << endl;
        cout << "Prev: " << mylist.prev() << endl;
    }

    cout << "active links " << mylist.numActive() << endl;
    cout << "free links  " << mylist.numFree() << endl;

    cout << "Clearing list" << endl;
    mylist.clear();
    mylist.printList();

	cout << "active links " << mylist.numActive() << endl;
	cout << "free links  " << mylist.numFree() << endl;
    return 0;
}
