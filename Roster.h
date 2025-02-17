//roster.h
#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Roster
{

private:
    string fileName;
    Student* roster;
    size_t size;
    size_t capacity;
    
    void resize()
    {
        capacity *= 2;
        Student* newRoster = new Student[capacity];
        for (size_t i = 0; i < size; i++)
        {
            newRoster[i] = roster[i];
        }
        delete[] roster;
        roster = newRoster;
    }

    int findStudent(string id)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (roster[i].getID() == id)
            {
                return i;
            }
        
        }
        return -1;
    }


    void readRosterFromFile(string fileName)
    {
        ifstream file(fileName);

        if (!file.is_open())
        {
            cerr << "Error opening file! :()";
            return;
        }

        string line;
        while (getline(file, line))
        {
            if (size == capacity){
                resize();
            }
            stringstream ss(line);     // treats the string 'line' as a stream
            string id, ln, fn, g;      // extracts attributes from line
            ss >> id >> ln >> fn >> g; // splits line into 4 'variables' (space-separated)
            roster[size++] = Student(id, ln, fn, g);
        }
        file.close(); // closes after reading all of the lines
    }
    // saving the current student (roster vector) into the file
    void updateFile()
    {
        ofstream file(fileName);
        if (!file.is_open())
        {
            // error case
            cerr << "Error opening file! :()";
            return;
        }
        
        for (size_t i = 0; i < size; i++)
        {
            file << roster[i].getID() << " "
            << roster[i].getlastName() << " "
            << roster[i].getfirstName() << " "
            << roster[i].getgrade() << endl;
        }
        file.close();
    }

public:
    Roster(string fileName)
    {
        this->fileName = fileName;
        // loading already exisiting student data, populated the roster vector
        readRosterFromFile(fileName);
    }

    // add an student object
    void addStudent(string id, string ln, string fn, string g)
    {
        if (size == capacity){
            resize();
        }
        roster[size++] = Student(id, ln, fn, g);
        // and update txt file
        updateFile(); // save changes to file
    }

    // drop an object
    void dropStudent(string idnum){

        int index = findStudent(idnum);
        if (index == -1)
        {
            cout << "Student not found!" << endl;
            return;
        }

        // Shift elements left to overwrite the deleted student
        for (size_t i = index; i < size - 1; i++)
        {
            roster[i] = roster[i + 1];
        }

        size--; // Reduce the number of students

        updateFile(); // Save changes to file
        cout << "Student with ID " << idnum << " is removed.\n";
    }


    // display object (find the object, then print it)
    void printStudent(string idnum)
    {
        int index = findStudent(idnum);
        if (index != -1)
        {
            cout << roster[index].getID() << " "
            << roster[index].getfirstName() << " "
            << roster[index].getlastName() << " "
            << roster[index].getgrade() << endl;
        }
        else
        {
            cout << "Student not found, sorry!" << endl;
        }
    }
    void insertionSort(){
        //name
        for(size_t i = 1; i < size ; i++ ){
            Student key = roster[i]; //object
            size_t j = i - 1; //index
            while(j >= 0 && roster[j].getfirstName() > key.getfirstName()){
                roster[j+1] = roster[j]; //overwrites the right element with the one to its left
                j--;
            }
            //putting item in hole
            roster[j+1] = key; 
        }
    }
    void selectionSort(){
        //id
        for(size_t i = 0; i < size - 1 ; i++){
            int currentMin = i;
            
            for(int j = i + 1; j < size; j++ ){
                if (roster[j].getID() < roster[currentMin].getID()){
                    //update min is smaller elem. is found
                    currentMin = j;
                }
            }
            //once you exit this loop, it means you have found the smallest elem.
            //so insert in to correct pos.
            swap(roster[i], roster[currentMin]); 
        }
    }
    int partition(int low, int high){
        string pivot = roster[high].getgrade(); //choosing last elem. as pivot
        int i = low - 1; //i tracks the last swapped pos
        
        for (int j = low; j < high; j++){
            if (roster[j].getgrade() <= pivot){//compares with pivot
                i++; //moves the boundary of smaller elem.
                swap(roster[i], roster[j]);
            }
        }   
        swap(roster[i + 1], roster[high]); //puts pivot in correct pos
        return i + 1; //returns pivot pos

    }
    void quickSort(int low, int high){
        //grade
        if (low < high){
           int partitionIndex = partition(low, high);

           quickSort(low, partitionIndex - 1);//sort left side
           quickSort(partitionIndex + 1, high);//sort right side
        }
    }
    void quickSortWrap(){//wrapper function to call in main
        quickSort(0, size - 1);
    }
};

#endif 