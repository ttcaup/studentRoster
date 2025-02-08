#include "student.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Roster {

    private:
        vector<Student> roster;

    public:
        
        int findStudent(string id){
            for (size_t i=0; i < roster.size(); i++){
                if(roster[i].getID() == id){
                    return i;
                }
                return -1;
            }
        }
        //add an student object
        void addStudent(string id, string ln, string fn, string g){
            roster.push_back(Student(id, ln, fn, g));
        }

        //drop an object
        void dropStudent(string idnum){
           int index = findStudent(idnum);
           if (index != -1){
            roster.erase(roster.begin() + index);
            cout << "Student with ID " << idnum << " removed.\n";
           }
           else {
            cout<< "Student not found"<<endl;
           } 
            

        }
    
        //display object (find the object, then print it)
        vector<Student> searchStudent{
            
        }
};