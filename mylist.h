#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T>
class MyList
{
	public:
		MyList();
		~MyList();
		void push_back(T s);
		T& at(int loc) const;
		int size() const;
		bool remove (T val);
		T pop(int loc);
		T& operator[](int loc);
		void clear();

	private:
		int size_;
		int capacity_;
		T* array;
};

template <typename T>
MyList<T>::MyList()
{
	size_ = 0; capacity_ = 5; array = new T[5];
}

template <typename T>
MyList<T>::~MyList(){delete [] MyList<T>::array;}

template <typename T>
void MyList<T>::push_back(T s)
{
	if (size_ >= capacity_)
		{
			T* tempArray = new T[2*capacity_];
			for (int i=0; i<capacity_; i++)
			{
				tempArray[i] = array[i];
			}
			delete [] array;
			array = tempArray;
			capacity_ *= 2;
		}

		array[size_++] = s;

}

template <typename T>
T& MyList<T>::at(int loc) const 
{
	return array[loc];
}

template <typename T>
int MyList<T>::size () const
{
	return size_;
}

template <typename T>
bool MyList<T>::remove (T val)
{
	for (int i=0; i<size_; i++)
	{
		if (array[i] == val)
		{
			for (int j=i; j<size_; j++)
			{
				T tempVal;
				tempVal = array[j+1];
				array[j] = tempVal;	
			}
			size_--;
			return true;
		}
	}

	return false;

}

template <typename T>
T MyList<T>::pop (int loc)
{
	if (loc > size_ || loc <0)
	{
		throw invalid_argument("Location out of bounds");
	}
	T popVal = array[loc];
	int i;
	i=loc;
	for (int i; i<size_; i++)
			{
				T tempVal;
				tempVal = array[i+1];
				array[i] = tempVal;	
			}
	return array[loc];

}

template <typename T>
T& MyList<T>::operator[](int loc)
{
	if (loc > size_ || loc < 0)
	{
		throw std::out_of_range("message");
	}
	return array[loc];
}

template <typename T>
void MyList<T>::clear()
{
	delete [] array;
	array= new T[5];
	size_ = 0;
	capacity_ = 5;
	
}


#endif
