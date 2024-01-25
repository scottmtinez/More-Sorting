#include "Student.h"

#ifndef STUDENTCOMPARATOR_H_
#define STUDENTCOMPARATOR_H_

class StudentComparator { // complete this class
  //If arg1’s grade does not equal arg2’s grade, return arg1’s grade – arg2’s grade
  public:
    int operator()(const Student &arg1, const Student &arg2) const {
      //
        if(arg1.grade != arg2.grade)
          {
            return arg1.grade - arg2.grade;
          }
        else
          {
            return arg1.name.compare(arg2.name);
          }
	}

     
  
};

#endif /* STUDENTCOMPARATOR_H_ */
