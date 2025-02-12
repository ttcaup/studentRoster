//roster.h
#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Roster
{

private:
    string fileName;
    vector<Student> roster;
    int findStudent(string id)
    {
        for (size_t i = 0; i < roster.size(); i++)
        {
            if (roster[i].getID() == id)
            {
                return i;
            }
        
        }
        return -1;
    }

    // read txt file into vector of student objects
    // how to make each line into object??
    // while loop that loops until no lines left
    // whitespace seperate each parameter of student object

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
            stringstream ss(line);     // treats the string 'line' as a stream
            string id, ln, fn, g;      // extracts attributes from line
            ss >> id >> ln >> fn >> g; // splits line into 4 'variables' (space-separated)
            roster.push_back(Student(id, ln, fn, g));
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
        
        for (const auto& student : roster)
        {
            file << student.getID() << " "
            << student.getlastName() << " "
            << student.getfirstName() << " "
            << student.getgrade() << endl;
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
        roster.push_back(Student(id, ln, fn, g));
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