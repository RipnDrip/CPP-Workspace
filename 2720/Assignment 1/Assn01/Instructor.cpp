#include <unistd.h>
#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include <string>
#include "Instructor.h"

// username and password of Instructor is passed in from the user's input, the method then reads from the instructor file to check the login info
// if login fails it returns false, if login is successful method saves the name of the professor and returns true
bool Instructor::login(string username, string password) 
{
        ifstream file("instructors.txt");
        if (!file.is_open()) 
        {
                cout << "instructors.txt File not found!" << endl;
                exit(EXIT_FAILURE);
        }
        string line;
        while (getline(file, line)) 
        {
                stringstream curLine(line);
                string aUsername, aPassword;
                getline(curLine, aUsername, '\t');
                getline(curLine, aPassword, '\t');
                if (aUsername.compare(username.c_str()) == 0 && aPassword.compare(password.c_str()) == 0) 
                {
                        getline(curLine, fullName, '\n');
                        file.close();
                        return true;
                }
        }
        file.close();
        return false;
}

// reads form the student file until it finds the username of the student inputed by the user. method then saves all the gardes, login info, and name of that student 
// before returning the student object
Student Instructor::getStudent(string username) 
{
        ifstream file("students.txt");
        if (!file.is_open()) 
        {
                cout << "student.txt File not found!" << endl;
                exit(EXIT_FAILURE);
        }
        string line;
        while (getline(file, line)) 
        {
                stringstream curLine(line);
                string aUsername, aPassword;
                getline(curLine, aUsername, '\t');
                getline(curLine, aPassword, '\t');
                if (aUsername.compare(username.c_str()) == 0)
                {
                        Student student;
                        string fullName;
                        getline(curLine, fullName, '\t');
                        student.setStudentName(fullName);
                        string grade;
                        getline(curLine, grade, '\t');
                        student.setProjectGrade(atoi(grade.c_str()));
                        getline(curLine, grade, '\t');
                        student.setQuizGrade(atoi(grade.c_str()));
                        getline(curLine, grade, '\t');
                        student.setMidtermGrade(atoi(grade.c_str()));
                        getline(curLine, grade, '\n');
                        student.setFinalGrade(atoi(grade.c_str()));
                        file.close();
                        return student;
                }
        }
        file.close();
        return Student();
}

// reads from student file and compares the students grades against each other until the min is discover for all students
// method saves the min grade and name of that student as it goes along and then returns both once all students have been gone through
Student Instructor::getMinStudent(int gradeType) 
{
        Student minGradeStudent;
        ifstream file("students.txt");
        if (!file.is_open()) 
        {
                cout << "student.txt File not found!" << endl;
                exit(EXIT_FAILURE);
        }
        string line;
        bool first = true;
        while (getline(file, line)) 
        {
                stringstream curLine(line);
                string aUsername, aPassword;
                getline(curLine, aUsername, '\t');
                getline(curLine, aPassword, '\t');
                Student student;
                string fullName;
                getline(curLine, fullName, '\t');
                student.setStudentName(fullName);
                string grade;
                getline(curLine, grade, '\t');
                student.setProjectGrade(atoi(grade.c_str()));
                getline(curLine, grade, '\t');
                student.setQuizGrade(atoi(grade.c_str()));
                getline(curLine, grade, '\t');
                student.setMidtermGrade(atoi(grade.c_str()));
                getline(curLine, grade, '\n');
                student.setFinalGrade(atoi(grade.c_str()));
                if (first) 
                {
                        minGradeStudent = student;
                        first = false;
                        continue;
                }
                if (gradeType == 1) 
                {
                        if (student.getProjectGrade() < minGradeStudent.getProjectGrade())
                                minGradeStudent = student;
                }
                else if (gradeType == 2) 
                {
                        if (student.getQuizGrade() < minGradeStudent.getQuizGrade())
                                minGradeStudent = student;
                }
                else if (gradeType == 3) 
                {
                        if (student.getMidtermGrade() < minGradeStudent.getMidtermGrade())
                                minGradeStudent = student;
                }
                else if (gradeType == 4) 
                {
                        if (student.getFinalGrade() < minGradeStudent.getFinalGrade())
                                minGradeStudent = student;
                }
                else 
                {
                        if (student.getOverallGrade() < minGradeStudent.getOverallGrade())
                                minGradeStudent = student;
                }
        }
        file.close();
        return minGradeStudent;
}

// reads from student file and compares the students grades against each other until the max is discover for all students
// method saves the max grade and name of that student as it goes along and then returns both once all students have been gone through
Student Instructor::getMaxStudent(int gradeType) 
{
        Student maxGradeStudent;
        ifstream file("students.txt");
        if (!file.is_open()) 
        {
                cout << "student.txt File not found!" << endl;
                exit(EXIT_FAILURE);
        }
        string line;
        bool first = true;
        while (getline(file, line)) 
        {
                stringstream curLine(line);
                string aUsername, aPassword;
                getline(curLine, aUsername, '\t');
                getline(curLine, aPassword, '\t');
                Student student;
                string fullName;
                getline(curLine, fullName, '\t');
                student.setStudentName(fullName);
                string grade;
                getline(curLine, grade, '\t');
                student.setProjectGrade(atoi(grade.c_str()));
                getline(curLine, grade, '\t');
                student.setQuizGrade(atoi(grade.c_str()));
                getline(curLine, grade, '\t');
                student.setMidtermGrade(atoi(grade.c_str()));
                getline(curLine, grade, '\n');
                student.setFinalGrade(atoi(grade.c_str()));
                if (first) 
                {
                        maxGradeStudent = student;
                        first = false;
                        continue;
                }
                if (gradeType == 1) 
                {
                        if (student.getProjectGrade() > maxGradeStudent.getProjectGrade())
                                maxGradeStudent = student;
                }
                else if (gradeType == 2) 
                {
                        if (student.getQuizGrade() > maxGradeStudent.getQuizGrade())
                                maxGradeStudent = student;
                }
                else if (gradeType == 3) 
                {
                        if (student.getMidtermGrade() > maxGradeStudent.getMidtermGrade())
                                maxGradeStudent = student;
                }
                else if (gradeType == 4) 
                {
                        if (student.getFinalGrade() > maxGradeStudent.getFinalGrade())
                                maxGradeStudent = student;
                }
                else 
                {
                        if (student.getOverallGrade() > maxGradeStudent.getOverallGrade())
                                maxGradeStudent = student;
                }
        }
        file.close();
        return maxGradeStudent;
}

// reads the student file and counts how many students there are and adds up all of there grades of a certain type 
// and then returns the sum divide by num of students which equals the average grade for that type
double Instructor::getAvg(int gradeType) 
{
        double sum = 0;
        ifstream file("students.txt");
        if (!file.is_open()) 
        {
                cout << "student.txt File not found!" << endl;
                exit(EXIT_FAILURE);
        }
        string line;
        int kids = 0;
        while (getline(file, line)) 
        {
                stringstream curLine(line);
                string aUsername, aPassword;
                getline(curLine, aUsername, '\t');
                getline(curLine, aPassword, '\t');
                Student student;
                string fullName;
                getline(curLine, fullName, '\t');
                student.setStudentName(fullName);
                string grade;
                getline(curLine, grade, '\t');
                student.setProjectGrade(atoi(grade.c_str()));
                getline(curLine, grade, '\t');
                student.setQuizGrade(atoi(grade.c_str()));
                getline(curLine, grade, '\t');
                student.setMidtermGrade(atoi(grade.c_str()));
                getline(curLine, grade, '\n');
                student.setFinalGrade(atoi(grade.c_str()));
                kids++;
                if (gradeType == 1)
                        sum += student.getProjectGrade();
                else if (gradeType == 2)
                        sum += student.getQuizGrade();
                else if (gradeType == 3)
                        sum += student.getMidtermGrade();
                else if (gradeType == 4)
                        sum += student.getFinalGrade();
                else
                        sum += student.getOverallGrade();
        }
        file.close();
        return (sum / kids);
}

//getters and setters

string Instructor::getInstructorName() 
{
        return fullName;
}

void Instructor::setInstructorName(string fullName) 
{
        this->fullName = fullName;
}