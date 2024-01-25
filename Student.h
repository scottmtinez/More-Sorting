#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#ifndef STUDENT_H_
#define STUDENT_H_

class Student {

public:
	string name;
	int grade;

	Student(string name, int grade) {
		this->name = name;
		this->grade = grade;
	}

	Student() {
		this->name = "";
		this->grade = 0;
	}

	string toString() const {
		string output = "(";
		output.append(name);
		output.append(", ");
		output.append(to_string(grade));
		output.append(")");
		return output;
	}

	static vector<Student> readStudents(const string &filePath) { // complete this method
    ifstream read(filePath, ios::in);
    
    vector<Student> Students;
    while(!read.eof())
      {
        //Declaring variables
          string name;
          int grade;

        //Reading the declarations 
          read >> name;
          read >> grade;
        
        //
          Student newStudent(name, grade);
          Students.push_back(newStudent); 
      }

    read.close();
    return Students;  
	}
};

#endif /* STUDENT_H_ */
