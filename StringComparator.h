#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

#ifndef STRINGCOMPARATOR_H_
#define STRINGCOMPARATOR_H_

class StringComparator {
public:
	int operator()(const string &arg1, const string &arg2) const {
		return arg1.compare(arg2);
	}
};

#endif /* STRINGCOMPARATOR_H_ */
