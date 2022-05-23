#include <unistd.h>
#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include <string>
#include "Student.h"

// username and password of student is passed in from the user's input, the method then reads from the student file to check the login info
// if login fails it returns false, if login is successful method saves the name of and grade data for the student and then returns true
bool Student::login(string username, string password) 
{
        ifstream inputFile("students.txt");
        if (!inputFile.is_open()) 
        {
                cout << "student.txt File not found!" << endl;
                exit(EXIT_FAILURE);
        }
        string line;
        while (getline(inputFile, line)) 
        {
                stringstream dataLine(line);
                string aUsername, aPassword;
                getline(dataLine, aUsername, '\t');
                getline(dataLine, aPassword, '\t');
                if(aUsername.compare(username.c_str()) == 0 && aPassword.compare(password.c_str()) == 0) 
                {
                        getline(dataLine, fullName, '\t');
                        string grade;
                        getline(dataLine, grade, '\t');
                        setProjectGrade(atoi(grade.c_str()));
                        getline(dataLine, grade, '\t');
                        setQuizGrade(atoi(grade.c_str()));
                        getline(dataLine, grade, '\t');
                        setMidtermGrade(atoi(grade.c_str()));
                        getline(dataLine, grade, '\n');
                        setFinalGrade(atoi(grade.c_str()));
                        inputFile.close();
                        return true;
                }
        }
        inputFile.close();
        return false;
}

// calculates the overall grade of the student based off the weighted percentages of grade types then returns the value
double Student::getOverallGrade() 
{
        return ((projectGrade * 0.3) + (quizGrade * 0.1) + (midtermGrade * 0.2) + (finalGrade * 0.4));
}

//standard getters and setters

string Student::getStudentName() 
{
        return fullName;
}

int Student::getProjectGrade() 
{
        return projectGrade;
}

int Student::getQuizGrade() 
{
        return quizGrade;
}

int Student::getMidtermGrade() 
{
        return midtermGrade;
}

int Student::getFinalGrade() 
{
        return finalGrade;
}

void Student::setStudentName(string fullName) 
{
        this->fullName = fullName;
}

void Student::setProjectGrade(int grade) 
{
        this->projectGrade = grade;
}

void Student::setQuizGrade(int grade) 
{
        this->quizGrade = grade;
}

void Student::setMidtermGrade(int grade) 
{
        this->midtermGrade = grade;
}

void Student::setFinalGrade(int grade) 
{
        this->finalGrade = grade;
}