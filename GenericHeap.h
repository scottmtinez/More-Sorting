#include <iostream>
#include <vector>
#include <string>
using namespace std;

#ifndef HEAP_H
#define HEAP_H

template<class T, class F>
class GenericHeap {

public:

	vector<T> heapArray;
	F comparator;

public:

	T top() {
		return heapArray.at(0);
	}

	void extract() { // complete this method
    //Swap the contents of index 0 and the last index of the heap
      swap(0,heapArray.size()-1); 

    //Remove the last number in the heap
      heapArray.pop_back();

    //Let currentIndex= 0,leftIndex= 1, and rightIndex= 2
      int currentIndex = 0;
      int leftIndex = 1;
      int rightIndex = 2;

    //While (leftIndex < size of heap), i.e., as long as current node has a left child, do:
      while(leftIndex < heapArray.size())
        {
          //let currentKey be the value at currentIndex
            T currentKey = heapArray.at(currentIndex);

          //let leftKey be the value at leftIndex
            T leftKey = heapArray.at(leftIndex);
            
          //if (rightIndex < size of heap), i.e., if current node has a right child, do:
            if(rightIndex < heapArray.size())
              {
                //let rightKey be the value at rightIndex
                  T rightKey = heapArray.at(rightIndex);

                //if (leftKey < currentKey and leftKey < rightKey), then left child is the smallest; so:
                  if(comparator(leftKey,currentKey) < 0 && comparator(leftKey, rightKey) < 0)
                    {
                      //swap the values of leftIndex and currentIndex
                        swap(leftIndex,currentIndex);
                      
                      //set currentIndex = leftIndex
                        currentIndex = leftIndex;
                    }
                  else if(comparator(rightKey,currentKey) < 0)
                    {
                      //swap the values of rightIndex and currentIndex
                        swap(rightIndex, currentIndex);

                      //set currentIndex = rightIndex
                        currentIndex = rightIndex;
                    }
                  else
                    {
                      break;
                    }
              }
            else if(comparator(leftKey,currentKey) < 0)
              {
                //swap the values of leftIndex and currentIndex
                  swap(leftIndex,currentIndex);
                  break;
              }
            else
              {
                break;
              }

            //set leftIndex = 2 * currentIndex + 1
              leftIndex = 2*currentIndex + 1;
            
            //set rightIndex = leftIndex + 1
              rightIndex = leftIndex + 1;
	}       
  }
	void insert(T &value) { // complete this method
    //Let currentIndex= size of the heap
      int currentIndex = heapArray.size();

    //Let parentIndex = parent of currentIndex
      int parentIndex = (currentIndex-1)/2;

    //Add the new value at the end of the heap array
      heapArray.push_back(value);

    //While (currentIndex > 0 and (value at parentIndex > value at currentIndex)), do:
      while(currentIndex > 0 && comparator(heapArray.at(parentIndex),heapArray.at(currentIndex)) > 0)
        {
          //swap the contents of heapArray at the indexes parentIndex and currentIndex
              swap(parentIndex,currentIndex);

          //set currentIndex = parentIndex
              currentIndex = parentIndex;

          //update parentIndex = parent of currentIndex
              parentIndex = (currentIndex-1)/2;
        }
  }

	

	int size() {
		return heapArray.size();
	}

private:

	void swap(int index1, int index2) {
		T temp = heapArray.at(index1);
		heapArray.at(index1) = heapArray.at(index2);
		heapArray.at(index2) = temp;
	}
};

#endif
