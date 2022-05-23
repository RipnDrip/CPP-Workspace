#ifndef __STUDENT_H__
#define __STUDENT_H__
using namespace std;
#include <string>
#include <iostream>
#include <fstream>
#include "Instructor.h"


class Student { 

public:
    string stName, stUser, stPassword;
    string  projGrade, quizGrade, midGrade, finalGrade;
    int pGrade, qGrade, mGrade, fGrade; 
    double oGrade;

    int stringToInt(string);
    bool login(string username, string password);
    string getStudentName();
    int getProjectGrade();
    int getQuizGrade();
    int getMidtermGrade();
    int getFinalGrade();
    double getOverallGrade();
};
#endif // __STUDENT_H__