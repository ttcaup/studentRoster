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
    void dropStudent(string idnum)
    {
        int index = findStudent(idnum);
        if (index != -1)
        {
            roster.erase(roster.begin() + index);
            // update txt file
            updateFile(); 

            cout << "Student with ID " << idnum << " is removed.\n";
        }
        else
        {
            cout << "Student not found." << endl;
        }
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
};

#endif 