#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H

#include <list>
#include <vector>
#include "List.h"
#include "SListNode.h"
#include "SListIterator.h"
using  std::vector;
using std::list;

// Forward references.
template <typename T, typename InputIterator>class List;
template <typename T>class SListNode;
template <typename T>class SListIterator;

// First the class interface
template <typename T, typename InputIterator>
class SLinkedList : public List<T,InputIterator> {
public:        

	SLinkedList();           

	virtual int size() const;
	virtual bool isEmpty() const;
	virtual void swap(InputIterator & first, InputIterator & second);
	virtual void replace(InputIterator & position, T element);        
	virtual void insertFirst(T element);
	virtual void insertLast(T element);
	virtual void insertAfter(InputIterator & position, T element);  
	virtual InputIterator remove(InputIterator & position);
	virtual int remove(T element);
	virtual void insertBefore(InputIterator & position, T element); 
	virtual void splice(InputIterator position, list<T> & x);

	// Member functions specific to SLinkedList
	SListNode<T>* head() const;
	SListNode<T>* tail() const;

	void reverse();

	SListIterator<T> begin() const;        
	SListIterator<T> end() const;        
	SListIterator<T> last() const;

private:
	SListNode<T>* m_pHead;
	SListNode<T>* m_pTail;
	int m_count;
};

// Now the class implementation.

template <typename T, typename InputIterator>
SLinkedList<T, InputIterator>::SLinkedList() :
	m_pHead(0),
	m_pTail(0),
	m_count(0)
{}

template <typename T, typename InputIterator>
int SLinkedList<T, InputIterator>::size() const {
	return m_count;
}

template <typename T, typename InputIterator>
bool SLinkedList<T, InputIterator>::isEmpty() const {
	return m_count == 0;
}


template <typename T, typename InputIterator>
void SLinkedList<T, InputIterator>::swap(InputIterator & first, InputIterator & second) {    
	T temp = *first;
	*first = *second;        
	*second = temp;		
}

template <typename T, typename InputIterator>
void SLinkedList<T, InputIterator>::replace(InputIterator & position, T element) {    
	*position = element; 
}

template <typename T, typename InputIterator>
void SLinkedList<T, InputIterator>::insertFirst(T element) {
	// create the new node.

	SListNode<T>* pNewnode =  new SListNode<T>(element, this);
	pNewnode->setNext(m_pHead);
	// set the head node, and the tail node if needed.
	m_pHead = pNewnode;

	if( m_pTail == 0 ) {
		m_pTail = m_pHead;
	}    

	m_count++;  
}

template <typename T, typename InputIterator>
void SLinkedList<T, InputIterator>::insertLast(T element) {
	// create the new node.

	SListNode<T>* pNewnode =  new SListNode<T>(element, this);
	if (m_pHead == 0) {
		m_pHead = pNewnode;
	}
	else {
		m_pTail->setNext(pNewnode);			
	}
	m_pTail = pNewnode;      
	m_count++;

}

template <typename T, typename InputIterator>
void SLinkedList<T, InputIterator>::insertAfter(InputIterator & position, T element) {

	SListNode<T>* pTemp = position.ptr();       

	if (pTemp != 0) {
		SListNode<T>* pNewnode = new SListNode<T>(element, this); 
		pNewnode->setNext(pTemp->next());
		pTemp->setNext(pNewnode);
		// if the new node is the new end of list node
		if (pNewnode->next() == 0) {
			m_pTail = pNewnode;                    
		}  
		m_count++;
	}
}

template <typename T, typename InputIterator>
void SLinkedList<T, InputIterator>::insertBefore(InputIterator & position, T element) {

	SListNode<T> *pTemp = position.ptr();      
	SListNode<T> *pNewnode =  new SListNode<T>(element, this);

	if(pTemp == m_pHead) {
		pNewnode->setNext(m_pHead);
		m_pHead = pNewnode;
	}
	else {
		pTemp = m_pHead;
		while(pTemp->next() != position.ptr()) {
			pTemp = pTemp->next();
		}
		pNewnode->setNext(pTemp->next());
		pTemp->setNext(pNewnode);
	}
}

template <typename T, typename InputIterator>
void SLinkedList<T, InputIterator>::splice(InputIterator position, list<T> & x){
	for each (T object in x)
	{
		insertBefore(position, object);
	}
}

template <typename T, typename InputIterator>
InputIterator SLinkedList<T, InputIterator>::remove(InputIterator & position) {
	SListNode<T>* pTemp = position.ptr();	     

	// Advance the iterator position to the next node
	++position;

	// If the node to be removed is at the head of the list
	if (pTemp == m_pHead) {
		m_pHead = m_pHead->next();           
	}
	else { // Node to be deleted has a predecessor.
		SListNode<T>* pPrevious = m_pHead;

		// Set up pPrevious to point to the node one before pTemp.
		for ( ; pPrevious->next() != pTemp; pPrevious = pPrevious->next() );   

		// If the node to be deleted is the tail.
		if (pTemp == m_pTail) {
			m_pTail = pPrevious;
		}
		// Link to the node after the one to be deleted.
		pPrevious->setNext(pTemp->next()); 
	}

	// Finally, remove the node.          
	delete pTemp; 
	m_count--;

	// Return the new iterator position
	return position;
}

// Implement this function
template <typename T, typename InputIterator>
int SLinkedList<T, InputIterator>::remove(T element) {
	// Remove all occurrences of element
	SListNode<T> *pCurrent = m_pHead;
	SListNode<T> *pTemp;

	int matches = 0;
	while (pCurrent != 0) {
		// if we have found a match
		if (pCurrent->element() == element) {
			cout << "Found a match" << endl;
			// Remove the match we have found
			pTemp = pCurrent;
			pCurrent = pCurrent->next();
			remove( SListIterator<T>(pTemp) );

			matches++;
		}
		else {
			pCurrent = pCurrent->next();
		}
	}
	m_count--;
	return matches;
}

template <typename T, typename InputIterator>
SListIterator<T> SLinkedList<T, InputIterator>::last() const {
	if (m_pTail != 0) {
		return SListIterator<T>(m_pTail);
	}
	return this->end();	
}

template <typename T, typename InputIterator>
SListIterator<T> SLinkedList<T, InputIterator>::begin() const {
	SListIterator<T> startIterator(m_pHead);
	return startIterator;    
}

template <typename T, typename InputIterator>
SListIterator<T> SLinkedList<T, InputIterator>::end() const {
	// Return a "one past the end" iterator  
	SListNode<T> *pTemp = 0;

	if (isEmpty() == false) {
		pTemp = m_pTail->next();
	}

	SListIterator<T> endIterator(pTemp);
	return endIterator;    
}

template <typename T, typename InputIterator>
void SLinkedList<T, InputIterator>::reverse() {
	if (size() > 1) {
		vector<SListNode<T> *> v;
		SListIterator<T> iter = begin(); //objects not pointers
		SListIterator<T> iterEnd = end();
		for( ; iter != iterEnd; iter++) {
			SListNode<T> *pNode = iter.ptr();
			v.push_back(pNode);
			//v.push_back(iter.ptr());
		}
		//iterate through the vector in reverse
		for(int i=v.size()-1; i>0; i--) {
			v.at(i)->setNext(v.at(i-1));
		}
		v.at(0)->setNext(0); //set last element pointer field to null
		//update head and tail pointers
		m_pTail = v.at(0);
		m_pHead = v.at(v.size() - 1);
	}
}

#endif

