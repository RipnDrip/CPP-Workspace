#include <string>
#include <iostream>
#include <istream>
#include <sstream>
#include <fstream>
#include "Instructor.h"

Student* currentS;
Student** kids;
Instructor**  I;
Instructor* currentI;
Instructor tempI;
int fileRow;

int stringToInt (string in) {
stringstream convert(in);
int x =0;
convert >> x;
return x;
}

bool Instructor::login(string username, string password) 
{
    int fileRow;
    bool instructorIsIn, legit = false;
    string line;
    ifstream File("instructors.txt", ios::in);
    if (!File) {
        perror("Error: cannot parse instructors information from");
        exit(1);
    }

    while (getline(File, line)) {
        string trim;
        
        Instructor* currInstructor = new Instructor();
        string iu = currInstructor->profUser =  line.substr(0, line.find("\t")); 
        trim = line.substr(line.find("\t"), line.find("\n"));
        line = trim;

        string ip = currInstructor->profPassword = line.substr(1,6);
        trim = line.substr(8, line.find("\n"));
        line = trim;

        string in = currInstructor->profName = line.substr(0, trim.find("\n"));
        I[fileRow] = currInstructor;
        fileRow++;
    }
    for (int i = 0; i < fileRow; i++ ) { 
        if ((I[i]->profUser.compare(username) == 0)) {
            
            for (int j; j < 3; j++) {  
                if (I[j]->profPassword.compare(password) == 0) {
                legit = true;
                instructorIsIn = true;
                cout << "You are now logged in as Instructor " << currentI->profName << endl;
                }
            }      
        }
    }
}


string Instructor::getInstructorName() 
{
    return profName;
}

Student Instructor::getStudent(string username) 
{
ifstream File("students.txt", ios::in);
    if (!File) {
        perror("Error: cannot parse instructors information from");
        exit(1);
    }

    string line;
    int row, col = 0;
    int fileRow = 0;

    kids = new Student*[fileRow];
    for (int i = 0; i < fileRow; i++) {
        kids[i] = new Student[7];
    }
    
    while (getline(File, line)) {
    
        string trim;
        
        
        Student* currStudent = new Student();
        currStudent->stUser =  line.substr(0, line.find("\t")); 
        trim = line.substr(line.find("\t"), line.find("\n"));
        line = trim;

        currStudent->stPassword = line.substr(1,6);
        trim = line.substr(8, line.find("\n"));
        line = trim;

        currStudent->stName = line.substr(0, trim.find("\t"));
        trim = line.substr(line.find("\t"), line.find("\n"));
        line = trim;

        currStudent->projGrade = line.substr(1, 3);
        currStudent->pGrade = stringToInt(currStudent->projGrade);
        currStudent->quizGrade = line.substr(4, 3);
        currStudent->qGrade = stringToInt(currStudent->quizGrade);
        currStudent->midGrade = line.substr(7, 3);
        currStudent->mGrade = stringToInt(currStudent->midGrade);
        currStudent->finalGrade = line.substr(10, 3);
        currStudent->fGrade = stringToInt(currStudent->finalGrade);
        currStudent->oGrade = currStudent->getOverallGrade();
        

        kids[fileRow] = currStudent;
        fileRow++;
        if(username.compare(currStudent->stName) == 0) {
            cout << "Student name:  " << currentS->stName << "\nProject    " << currentS->pGrade <<"%" <<
       "\nQuiz       " << currentS->qGrade << "%" <<"\nMidterm    " << currentS->mGrade << "%" << 
       "\nFinal      " << currentS->fGrade << "%" <<"\nOverall    " << currentS->oGrade << "%" << endl;
        }
    }//while
    
}

Student Instructor::getMinStudent(int gradeType) 
{
    ifstream File("students.txt", ios::in);
    if (!File) {
        perror("Error: cannot parse instructors information from");
        exit(1);
    }

    string line;
    int row, col = 0;
    int fileRow = 0;
    int sum;

    kids = new Student*[fileRow];
    for (int i = 0; i < fileRow; i++) {
        kids[i] = new Student[7];
    }
    
    while (getline(File, line)) {
    
        string trim;
        
        
        Student* currStudent = new Student();
        currStudent->stUser =  line.substr(0, line.find("\t")); 
        trim = line.substr(line.find("\t"), line.find("\n"));
        line = trim;

        currStudent->stPassword = line.substr(1,6);
        trim = line.substr(8, line.find("\n"));
        line = trim;

        currStudent->stName = line.substr(0, trim.find("\t"));
        trim = line.substr(line.find("\t"), line.find("\n"));
        line = trim;

        currStudent->projGrade = line.substr(1, 3);
        currStudent->pGrade = stringToInt(currStudent->projGrade);
        currStudent->quizGrade = line.substr(4, 3);
        currStudent->qGrade = stringToInt(currStudent->quizGrade);
        currStudent->midGrade = line.substr(7, 3);
        currStudent->mGrade = stringToInt(currStudent->midGrade);
        currStudent->finalGrade = line.substr(10, 3);
        currStudent->fGrade = stringToInt(currStudent->finalGrade);
        currStudent->oGrade = currStudent->getOverallGrade();
        

        kids[fileRow] = currStudent;
        fileRow++;
        int min;
        Student* minStudent;
        Student* maxStudent;
        if(gradeType == 1 && fileRow > 1) {
            if(currStudent->pGrade < kids[fileRow-1]->pGrade) {
                minStudent = currStudent;
                cout << "Project grade stats,\n        min     "<< minStudent->pGrade << "%" << (minStudent->stName) <<"\n        max     " 
                << maxStudent->oGrade << "%" << (maxStudent->stName)<< "\n        avg     " << currentI->getAvg(gradeType) << "%" << endl;
            }
        }
        else if(gradeType == 2 && fileRow > 1) {
            if(currStudent->qGrade < kids[fileRow-1]->qGrade) {
                minStudent = currStudent;
                cout << "Quiz grade stats,\n        min     "<< minStudent->qGrade << "%" << (minStudent->stName) <<"\n        max     " 
                << maxStudent->oGrade << "%" << (maxStudent->stName)<< "\n        avg     " << currentI->getAvg(gradeType) << "%" << endl;
            }
        }
        else if(gradeType == 3 && fileRow > 1) {
            if(currStudent->mGrade < kids[fileRow-1]->mGrade) {
                minStudent = currStudent;
                cout << "Midterm grade stats,\n        min     "<< minStudent->mGrade << "%" << (minStudent->stName) <<"\n        max     " 
                << maxStudent->oGrade << "%" << (maxStudent->stName)<< "\n        avg     " << currentI->getAvg(gradeType) << "%" << endl;
            }
        }
        else if(gradeType == 4 && fileRow > 1) {
            if(currStudent->fGrade < kids[fileRow-1]->fGrade) {
                minStudent = currStudent;
                cout << "Final grade stats,\n        min     "<< minStudent->fGrade << "%" << (minStudent->stName) <<"\n        max     " 
                << maxStudent->oGrade << "%" << (maxStudent->stName)<< "\n        avg     " << currentI->getAvg(gradeType) << "%" << endl;
            }
        }
        else if(gradeType == 5 && fileRow > 1) {
            if(currStudent->oGrade < kids[fileRow-1]->oGrade) {
                minStudent = currStudent;
                cout << "Overall grade stats,\n        min     "<< minStudent->oGrade << "%" << (minStudent->stName) <<"\n        max     " 
                << maxStudent->oGrade << "%" << (maxStudent->stName)<< "\n        avg     " << currentI->getAvg(gradeType) << "%" << endl;
            }
        }
    }//while
}

Student Instructor::getMaxStudent(int gradeType) 
{
ifstream File("students.txt", ios::in);
    if (!File) {
        perror("Error: cannot parse instructors information from");
        exit(1);
    }

    string line;
    int row, col = 0;
    int fileRow = 0;
    int sum;

    kids = new Student*[fileRow];
    for (int i = 0; i < fileRow; i++) {
        kids[i] = new Student[7];
    }
    
    while (getline(File, line)) {
    
        string trim;
        
        
        Student* currStudent = new Student();
        currStudent->stUser =  line.substr(0, line.find("\t")); 
        trim = line.substr(line.find("\t"), line.find("\n"));
        line = trim;

        currStudent->stPassword = line.substr(1,6);
        trim = line.substr(8, line.find("\n"));
        line = trim;

        currStudent->stName = line.substr(0, trim.find("\t"));
        trim = line.substr(line.find("\t"), line.find("\n"));
        line = trim;

        currStudent->projGrade = line.substr(1, 3);
        currStudent->pGrade = stringToInt(currStudent->projGrade);
        currStudent->quizGrade = line.substr(4, 3);
        currStudent->qGrade = stringToInt(currStudent->quizGrade);
        currStudent->midGrade = line.substr(7, 3);
        currStudent->mGrade = stringToInt(currStudent->midGrade);
        currStudent->finalGrade = line.substr(10, 3);
        currStudent->fGrade = stringToInt(currStudent->finalGrade);
        currStudent->oGrade = currStudent->getOverallGrade();
        

        kids[fileRow] = currStudent;
        fileRow++;
        Student* minStudent;
        Student* maxStudent;
        if(gradeType == 1 && fileRow > 1) {
            if(currStudent->pGrade > kids[fileRow-1]->pGrade) {
                maxStudent = currStudent;
                cout << "Project grade stats,\n        min     "<< minStudent->pGrade << "%" << (maxStudent->stName) <<"\n        max     " 
                << maxStudent->oGrade << "%" << (maxStudent->stName)<< "\n        avg     " << currentI->getAvg(gradeType) << "%" << endl;
            }
        }
        else if(gradeType == 2 && fileRow > 1) {
            if(currStudent->qGrade > kids[fileRow-1]->qGrade) {
                maxStudent = currStudent;
                cout << "Quiz grade stats,\n        min     "<< minStudent->qGrade << "%" << (maxStudent->stName) <<"\n        max     " 
                << maxStudent->oGrade << "%" << (maxStudent->stName)<< "\n        avg     " << currentI->getAvg(gradeType) << "%" << endl;
            }
        }
        else if(gradeType == 3 && fileRow > 1) {
            if(currStudent->mGrade > kids[fileRow-1]->mGrade) {
                maxStudent = currStudent;
                cout << "Midterm grade stats,\n        min     "<< minStudent->mGrade << "%" << (minStudent->stName) <<"\n        max     " 
                << maxStudent->oGrade << "%" << (maxStudent->stName)<< "\n        avg     " << currentI->getAvg(gradeType) << "%" << endl;
            }
        }
        else if(gradeType == 4 && fileRow > 1) {
            if(currStudent->fGrade > kids[fileRow-1]->fGrade) {
                maxStudent = currStudent;
                cout << "Final grade stats,\n        min     "<< minStudent->fGrade << "%" << (minStudent->stName) <<"\n        max     " 
                << maxStudent->oGrade << "%" << (maxStudent->stName)<< "\n        avg     " << currentI->getAvg(gradeType) << "%" << endl;
            }
        }
        else if(gradeType == 5 && fileRow > 1) {
            if(currStudent->oGrade > kids[fileRow-1]->oGrade) {
                maxStudent = currStudent;
                cout << "Overall grade stats,\n        min     "<< minStudent->oGrade << "%" << (minStudent->stName) <<"\n        max     " 
                << maxStudent->oGrade << "%" << (maxStudent->stName)<< "\n        avg     " << currentI->getAvg(gradeType) << "%" << endl;
            }
        }
    }//while
}

double Instructor::getAvg(int gradeType) 
{
    ifstream File("students.txt", ios::in);
    if (!File) {
        perror("Error: cannot parse instructors information from");
        exit(1);
    }

    string line;
    int row, col = 0;
    int fileRow = 0;

    kids = new Student*[fileRow];
    for (int i = 0; i < fileRow; i++) {
        kids[i] = new Student[7];
    }
    
    while (getline(File, line)) {
    
        string trim;
        
        
        Student* currStudent = new Student();
        currStudent->stUser =  line.substr(0, line.find("\t")); 
        trim = line.substr(line.find("\t"), line.find("\n"));
        line = trim;

        currStudent->stPassword = line.substr(1,6);
        trim = line.substr(8, line.find("\n"));
        line = trim;

        currStudent->stName = line.substr(0, trim.find("\t"));
        trim = line.substr(line.find("\t"), line.find("\n"));
        line = trim;

        currStudent->projGrade = line.substr(1, 3);
        currStudent->pGrade = stringToInt(currStudent->projGrade);
        currStudent->quizGrade = line.substr(4, 3);
        currStudent->qGrade = stringToInt(currStudent->quizGrade);
        currStudent->midGrade = line.substr(7, 3);
        currStudent->mGrade = stringToInt(currStudent->midGrade);
        currStudent->finalGrade = line.substr(10, 3);
        currStudent->fGrade = stringToInt(currStudent->finalGrade);
        currStudent->oGrade = currStudent->getOverallGrade();
        

        kids[fileRow] = currStudent;
        fileRow++;
    }//while

    int avg,sum;

    if(gradeType == 1) {
        for (int i = 0; i < fileRow;i++) {
            sum += kids[i]->pGrade;
        }
        avg = sum/fileRow;
    }
    else if(gradeType == 2) {
        for (int i = 0; i < fileRow;i++) {
            sum += kids[i]->qGrade;
        }
        avg = sum/fileRow;      
    }
    else if(gradeType == 3) {
            for (int i = 0; i < fileRow;i++) {
            sum += kids[i]->mGrade;
        }
        avg = sum/fileRow;
    }
    else if(gradeType == 4) {
           for (int i = 0; i < fileRow;i++) {
            sum += kids[i]->fGrade;
        }
        avg = sum/fileRow;
    }
    else if(gradeType == 5) {
            for (int i = 0; i < fileRow;i++) {
            sum += kids[i]->oGrade;
        }
        avg = sum/fileRow;
    }
    else {
        cout << "Invalid Option. Please enter valid option." << endl;
    }
    return avg;
}


void readInFile(char **) {
    ifstream File("instructors.txt", ios::in);
    if (!File) {
        perror("Error: cannot parse instructors information from");
        exit(1);
    }

    string line;
    Instructor** ia = new Instructor*[fileRow];
    for (int i = 0; i < fileRow; i++) {
        ia[i] = new Instructor[3];
    }
    while (getline(File, line)) {
        
        string trim;
        
        Instructor* currInstructor = new Instructor();
        string iu = currInstructor->profUser =  line.substr(0, line.find("\t")); 
        trim = line.substr(line.find("\t"), line.find("\n"));
        line = trim;

        string ip = currInstructor->profPassword = line.substr(1,6);
        trim = line.substr(8, line.find("\n"));
        line = trim;

        string in = currInstructor->profName = line.substr(0, trim.find("\n"));
        ia[fileRow] = currInstructor;
        fileRow++;
    }//while
    I = ia;
} //readInFile