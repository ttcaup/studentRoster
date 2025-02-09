//student.h

// 3333, linear, francisco, senior
//ID, lastName, firstName, grade

//function to include :
// update: ID, lastName, firstName, grade
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string ID;
    string lastName;
    string firstName;
    string grade;

public:
    Student(string ID, string lastName, string firstName, string grade){
        this-> ID = ID;
        this-> lastName = lastName;
        this-> firstName = firstName;
        this-> grade = grade;
    }
    

//function update 
string getID() const {
    return ID;
};
string getlastName() const {
    return lastName;
};
string getfirstName() const {
    return firstName;
};
string getgrade() const {
    return grade;
};

};

#endif



