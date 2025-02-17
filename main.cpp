//main.cpp
#include "student.h"
#include "roster.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void studentMenu () {
    cout << "1.Add Student\n2.Drop Student\n3.List Student\n4.Sort by Name\n5.Sort by ID\n6.Sort by Grade\n7.Exit\n";
}

int main(){

    Roster roster("list.txt");
    //roster.loadFromFile("list.txt");

    cout << "\nEnter a space between each word, ex: 1234 Doe John Freshman\n\n";
    int choice; //user choice variable 
    do{ //student menu loop
        studentMenu();
        cin >> choice;
        //1 add student
        if (choice ==1) {
            // doesnt work?
            string ID, lastName, firstName, grade;
            cout << "Enter Student ID, Last Name, First Name, Grade Level: "<<endl;
            cin >> ID >> lastName >> firstName >> grade;
            roster.addStudent(ID, lastName, firstName, grade);
        }
        //2 drop student
        else if(choice == 2){
            string ID;
            cout << "Enter Student ID to drop student: "<<endl;
            cin >> ID;
            roster.dropStudent(ID);
        }  
        //3 list one student 
        else if(choice == 3){
            //doesnt work
            string ID;
            cout << "Enter Student ID to list student: "<<endl;
            cin >> ID;
            roster.printStudent(ID);
        } 
        else if(choice == 4){
            //Sort by Name
            roster.insertionSort();
            roster.printRoster();
        } 
        else if(choice == 5){
            //sort by id
            roster.selectionSort();
            roster.printRoster();
        } 
        else if(choice == 6){
            //sort by grade
            roster.quickSortWrap();
            roster.printRoster();
        } 

    }
    //7 exit menu
    while (choice != 7);
        return 0; 
}


 
    


   

    


    



    
