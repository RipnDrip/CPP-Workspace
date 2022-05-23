#include <string>
#include <iostream>
#include <fstream>
#include "Instructor.h"



int stringToInt (string num) {
stringstream convert(num);
int x = 0;
convert >> x;
return x;
}

Student** kids;
Student* current;
bool studentIsIn, legit = false;   
bool Student::login(string username, string password) 
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
    }
    for (int i = 0; i < fileRow; i++ ) { 
        if ((kids[i]->stUser.compare(username) == 0)) {
                    
            for (int j; j < 3; j++) {  
                if (kids[j]->stPassword.compare(password) == 0) {
                legit = true;
                studentIsIn = true;
                cout << "You are now logged in as Student " 
                << kids[i]->stName.substr(0,kids[i]->stName.find("\t")) << endl;
                current = kids[i];
                }
            }      
        }
    }
    if(studentIsIn) {
    string response;
        while (response != "y") {
        cout << "Do you want to view grades (y/n)?" << endl;
        cin >> response;
            if (response ==  "y") {
            cout << "Student name:  " << current->stName << "\nProject    " << current->pGrade <<"%" <<
            "\nQuiz       " << current->qGrade << "%" <<"\nMidterm    " << current->mGrade << "%" << 
            "\nFinal      " << current->fGrade << "%" <<"\nOverall    " << current->oGrade << "%" << endl;
            string newUsername, newPassword;
            cout << "Enter credentials to login, Enter Username: " << endl;
            cin >> newUsername;
            cout << "Enter Password: " << endl;
            cin >> newPassword;
            login(newUsername, newPassword);
            }
        }
    }
    
}
string Student::getStudentName() {
    return stName;
}

int Student::getProjectGrade() 
{
    return pGrade;
}

int Student::getQuizGrade() 
{
    return qGrade;
}

int Student::getMidtermGrade() 
{
    return mGrade;
}

int Student::getFinalGrade() 
{
    return fGrade;
}

double Student::getOverallGrade() 
{
    return oGrade;
}


