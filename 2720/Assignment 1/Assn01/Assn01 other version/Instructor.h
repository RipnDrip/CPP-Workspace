#ifndef __INSTRUCTOR_H__
#define __INSTRUCTOR_H__
using namespace std;
#include <string>
#include <iostream>
#include <fstream>
#include "Student.h"

class Instructor {
public:
    string profName, profUser, profPassword; //Name, Username, Password
    string  projGrade, quizGrade, midGrade, finalGrade, ovrGrade;
    Instructor** I;
    Instructor* currentI;
    
    int stringToInt(string);
    bool login(string username, string password);
    string getInstructorName();
    Student getStudent(string username);
    Student getMinStudent(int gradeType);
    Student getMaxStudent(int gradeType);
    double getAvg(int gradeType);
    
};
#endif // __INSTRUCTOR_H__