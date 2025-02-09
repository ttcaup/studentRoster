#include "student.h"
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Roster {

    private:
        string fileName;
        vector<Student> roster;
        int findStudent(string id){
            for (size_t i=0; i < roster.size(); i++){
                if(roster[i].getID() == id){
                    return i;
                }
                return -1;
            }
        }

        //read txt file into vector of student objects 
        //how to make each line into object??
        //for loop that loops until no lines left
        //,whitespace seperate each parameter of student object

        void readRosterFromFile(string fileName){
            ifstream file(fileName);

            if(!f.is_open()){
                cerr << "Error opening file! :()";
                return 1;
            }

            string line;

            while (getLine(file, line)){
                cout << line << endl;
            }
        }

    public:
        
        Roster(string fileName){
            this-> fileName = fileName;
        }
        

        //add an student object
        void addStudent(string id, string ln, string fn, string g){
            roster.push_back(Student(id, ln, fn, g));
            //and update txt file
        }

        //drop an object
        void dropStudent(string idnum){
           int index = findStudent(idnum);
           if (index != -1){
            roster.erase(roster.begin() + index);
            //update txt file
            cout << "Student with ID " << idnum << " removed.\n";
           }
           else {
            cout<< "Student not found"<<endl;
           } 
        }
    
        //display object (find the object, then print it)
        void printStudent(string idnum){
            int index = findStudent(idnum);
            if (index != -1){
                cout << roster[index].getID()<<
                roster[index].getfirstName()<<
                roster[index].getlastName()<<
                roster[index].getgrade()<<endl;
               }
            else {
                cout<< "Student not found"<<endl;
               } 
        }

    
};