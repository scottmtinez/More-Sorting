#include <iostream>
#include <string>

#include "GenericHeap.h"
#include "Student.h"
#include "StudentComparator.h"
#include "StringComparator.h"

using namespace std;

#ifndef HEAPAPPLICATIONS_H_
#define HEAPAPPLICATIONS_H_

class HeapApplications {

public:

	static void heapSort(string *array, int arrayLen) { // complete this method
    //Create a string heap via a constructor call to the GenericHeap class; use the StringComparator in this case. Refer to the GenericSelectionSort class method stringSort for usage.
      GenericHeap<string, StringComparator> heap;

    //Insert all the strings of the array into the heap using a for loop.
      for(int i = 0; i < arrayLen; i++)
        {
            heap.insert(array[i]); 
        }

    //for (i = 0 to i < arrayLen), do the following:
      for(int i = 0; i < arrayLen; i++)
        {
          //set array[i] to the smallest/topmost string in the heap
            array[i] = heap.top();

          //extract the smallest/topmost from the heap
            heap.extract();

        }
	}

	static vector<Student> topK(vector<Student> &students, int k) { // complete this method
    //If k is more than the size of students, then set k to the size of students
      if(k > students.size())
        {
          k = students.size();
        }

    //Create a Student heap via a constructor call to the GenericHeap class; use the StudentComparator in this case. Refer to the GenericSelectionSort class method studentSort for usage.
      GenericHeap<Student, StudentComparator> heap;

    //Create a StudentComparator object.
      StudentComparator comp;
      
    //Insert the first k students into the heap.
      for(int i = 0; i < k; i++)
        {
          heap.insert(students.at(i));
        }

    //for (i = k to i < size of students), do the following:
      for(int i = k; i < students.size(); i++)
        {
          //let min be the topmost student in the heap
            Student min = heap.top();
          
          //let current be the student at index i of students
            Student current = students.at(i);
          
          //Use the student comparator object to compare min and current. If (min is smaller than current), then:
            if(comp(min,current) < 0)
              {
                //extract the topmost student from the heap
                  heap.extract();

                //insert current into the heap
                  heap.insert(current);
              }
        }
    
    //Create a Student dynamic array (vector in C++ and ArrayList in Java).
      vector<Student>dynamicArray;

    //At this point, notice that the heap contains the top-k students. Use top and extract to extract the students in the heap and add them into the dynamic array.
      for(int i = 0; i < k; i++)
        {
          dynamicArray.push_back(heap.top());
          heap.extract();
        }

    //Return the dynamic array.
      return dynamicArray;

    
	}
};

#endif /* HEAPAPPLICATIONS_H_ */
