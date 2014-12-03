#include <iostream>
#include "SLinkedList.h"
#include <list>

using namespace std;
    
int main() {
  /* 
	list.reverse();*/
	/*SListIterator<int> start = list.begin();
	list.insertAfter( start, -1 );
	start = list.begin();	
	list.remove( start );

	cout << list.size() << endl;*/

	//SListNode<int> *pFirst = new SListNode<int>(10);
	//SListNode<int> *pSecond = new SListNode<int>(10);
	//pFirst->setNext(pSecond);

	////create a list iterator
	//SListIterator<int> first(pFirst);
	//SListIterator<int> it = first++;
	list<int> list1;
	list<int> dest;

	//SLinkedList<int, SListIterator<int>> list;
	//SListIterator<int> iterator1 = list.begin();
	//list.insertLast(20);
 //   list.insertLast(10);
	//list.insertLast(5);
	
	// fill the list so that it has 20,10,50,40
	//list.push_back(50);
	//list.push_back(40);
	//listObject.push_back(10);

	//Q1
	//SListIterator<int> iterator = list.begin();
	//iterator++;
	//list.insertBefore(iterator, 8);

	////Q2
	//for (int i = 0; i < 10; i++)
	//{
	//	list1.push_back(i);
	//}
	//iterator = ++list.begin();
	//list.splice(iterator, list1);

	//
	
	//Q3
	for (int i = 0; i < 20; i++)
    {
        int random = rand() % 10 + 1;
		list1.push_back(random);
    }

	list<int>::reverse_iterator backIt = find( list1.rbegin(), list1.rend(), 2 );
	list<int>::iterator forwardIt = find( backIt.base(), list1.end(), 7 );

	dest.splice(dest.end(), list1, backIt.base(), forwardIt);

	// sort the list using the list::sort() function
	//list<int>::iterator it = listObject.begin();
	//list<int> secondList;
	//it++;
	//it++;
	//secondList.splice(secondList.begin(), listObject, it, listObject.end());

	//void splice ( iterator position, list<T,Allocator>& x, iterator (10), iterator last );

	//reverse 
	/*list<int>::reverse_iterator i = listObject.rbegin();

	list<int>::iterator it  = i.base();
	for(; i != listObject.rend(); i++)
	{
		cout << *i << endl;
	}*/
	//output list in reverse order.

    system("PAUSE");
}