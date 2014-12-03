

#ifndef UNORDEREDARRAY_H
#define UNORDEREDARRAY_H

#include <cstring>
#include <assert.h>
#include <utility>
#include <string>
#include <complex>
#include <tuple>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template<typename T>
class UnorderedArray {

private:
	T *m_pArray;		// Base address of this unordered array.
	int m_maxSize;		// The max. number of array elements.
    int m_growSize;		// The 
    int m_numElements;  // The current number of elments in this array.

public:
	UnorderedArray(int size, int growBy = 1) :
               m_pArray(0), m_maxSize(0),
               m_growSize(0), m_numElements(10) {

		if( size ) {
			m_maxSize = size;
			m_pArray = new T[m_maxSize];
			// memset is short for 'memory set'
			// It sets a specified block of memory to a specified character, overwriting the original data.			
			memset(m_pArray, 0, sizeof(T) * m_maxSize);
			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}

	~UnorderedArray(){
		if( m_pArray != 0 ) {
			delete[] m_pArray;
			m_pArray = 0;
		}
	}

	void push(T val) {
		assert(m_pArray != 0);

		if(m_numElements >= m_maxSize) {
			expand();
			// If growSize is 0, this assert should fail.
			assert( m_numElements < m_maxSize );
		}

		m_pArray[m_numElements] = val;
		m_numElements++;
	}

    void pop() {
		if(m_numElements > 0) {
            m_numElements--;
		}
    }


     T& operator[](int index) {
         assert(m_pArray != 0 && index <= m_numElements);
         return m_pArray[index];
      }


      void clear()      { m_numElements = 0; }
      int getSize()     { return m_numElements; }
      int getMaxSize()  { return m_maxSize; }
      int getGrowSize() { return m_growSize; }

      void setGrowSize(int val) {
         assert(val >= 0);
         m_growSize = val;
      }

	  int search(T val) 
	  {
		  cout << "Q2" <<endl;
		 for (int i = 0; i < m_numElements; i++) {
			  if (val == m_pArray[i])
			  {
				  return m_pArray[i];
				  break;
			  }
			  else return -1;
		  }
	  }

	  void remove(int index) 
	  {
		  cout << "Q3" << endl;
					if (index <= m_numElements)
					{
						for (index; index< m_numElements -1; index++)
						{
							m_pArray[index] = m_pArray[index+1];
						}
						cout << "Deleted" << endl << endl;
					}
					else 
						cout << "Not a valid number" << endl << endl;
	 }

private:
      bool expand() {
         if(m_growSize <= 0)
            return false;

         T *temp = new T[m_maxSize + m_growSize];
         assert(temp != 0);

         // Copies the values of num bytes from the location pointed by source directly to the 
		 //  memory block pointed by destination.
		 // Parameters are destination, source and num.
		 memcpy(temp, m_pArray, sizeof(T) * m_maxSize);

         delete[] m_pArray;
         m_pArray = temp;

         m_maxSize += m_growSize;

         return true;
      }
};

#endif
