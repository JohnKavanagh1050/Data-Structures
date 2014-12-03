#include "UnorderedArray.h"

using namespace std;


template <typename T>
T scalarProduct(T const* pVec1Array, T const* pVec2Array, int const ELEMENTS)
{
	cout << "Q1" << endl;
	T scalarProduct = 0;

	for (int i = 0; i < ELEMENTS; i++)
	{
		scalarProduct += (pVec1Array[i] * pVec2Array[i]);
		
	}

	return scalarProduct;
}

template <typename T>
pair<T,T>findMinMax(T * pArray)
{
	pair<T,T> pair = make_pair(pArray[0], 4);
	
	for (int i = 1; i < 3; i++)
	{
		if (pair.second < pArray[i])
		{
			pair.second = pArray[i];
		}

		if (pair.first > pArray[i])
		{
			pair.first = pArray[i];
		}
	}

return pair;
}

void questionFive()
{
	cout <<"Q5" << endl;
	int num;
	cout << "Enter a number to remove between 1 and 10" << endl;

	cin >> num;
	
	std::vector<int> myVec;
	//std::vector< int >::iterator newLastElement;
	//for (int i = 0; i < 100; i++)
	//{
	//	myVec.push_back(rand() % 9 + 1);
	//}

	std::vector< int >::iterator it = myVec.begin();   //(vector1.it(), vector1.end(), input);
	while (it != myVec.end())
	{
		it = find(it,myVec.end(), num);
		if (it != myVec.end())
			it = myVec.erase(it);
	}
	cout << num << "Was Deleted" << endl;

	//part 2
	if (num > 0 && num < 10)
	{
		myVec.erase(std::remove(myVec.begin(), myVec.end(), num), myVec.end());
		cout << num << " Has been removed from vector" << endl << endl;
	}
}

// Create a small class 
class SomeClass { 
private:
	int m_t;
public: 
	SomeClass(int t = 0) : m_t(t) 
	{
	
	} 
	// Destructor function. 
	~SomeClass ()
	{ 
		cout << "Destructor called " << endl; 
	} 
	// Define a copy constructor. 
	SomeClass( SomeClass const & copy ) 
	{ 
		cout << "Copy constructor called " << endl; 
	} 
};

void QuesionSix()
{
	vector<SomeClass> v;
	{
		for (int i = 0; i < 3; i++)
		{
			v.push_back( SomeClass(i) );
		}

		cout << endl << "Q6 " << endl << "Size = " << v.size() << endl;
		cout << "Capacity is " << v.capacity() << endl;
		v.clear();
		cout << "v.clear() was called" << endl;
		cout << "New size = " << v.size() << "\nCapacity stays the same = " << v.capacity() << endl;
	}
}

void QuestionSixPointer()
{
	vector<SomeClass *> v;
	{
		for (int i = 0; i < 3; i++)
		{
			v.push_back(new SomeClass(i));
		}
		char n;
		cout << endl << "Press n to continue" << endl;
		cin >> n;
		if (n == 'n')
		{
			cout << "Q6 Part 2 What happens when clear() is called? " << endl;
			v.clear();
			cout << "New size = " << v.size() << "\nCapacity stays the same = " << v.capacity() << endl;
		}
	}
}

int main()
{
	int const ELEMENTS = 3;
	int vector1[] = {1,2,3};
	int vector2[] = {4,5,6};

	char qsfour[] = {'e', 'b', 'a'};

	UnorderedArray<int> unArray(10,1);
	cout << "The answer is " << scalarProduct(vector1, vector2, ELEMENTS) << endl << endl;
	cout << "value is " << unArray.search(8) <<endl << endl;
	unArray.remove(10);

	cout << "Q4 "  << endl; 
	findMinMax(qsfour);
	cout << " Smallest " << findMinMax(qsfour).first << "\n Biggest " << findMinMax(qsfour).second << endl << endl;;
	questionFive();
	QuesionSix();
	QuestionSixPointer();

	system("PAUSE");
}