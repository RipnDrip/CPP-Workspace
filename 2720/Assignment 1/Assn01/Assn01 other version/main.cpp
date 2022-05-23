#include <unistd.h>
#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include <string>
#include "Instructor.h"
#include "Student.h"


using namespace std;

Instructor** mainI; 
Instructor* currentI;

Student** mainS;
Student* currentS;

bool studentIsIn, instructorIsIn;
int type, fileRow, fileCol = 0;


int stringToInt (string in) {
stringstream convert(in);
int x = 0;
convert >> x;
return x;
}

void readInFile(char *) {
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
        
        currentI = new Instructor();
        string iu = currentI->profUser =  line.substr(0, line.find("\t")); 
        trim = line.substr(line.find("\t"), line.find("\n"));
        line = trim;

        string ip = currentI->profPassword = line.substr(1,6);
        trim = line.substr(8, line.find("\n"));
        line = trim;

        string in = currentI->profName = line.substr(0, trim.find("\n"));
        ia[fileRow] = currentI;
        fileRow++;
    }//while
    mainI = ia;
} //readInFile

void readStFile(char*) {
    
    ifstream File("students.txt", ios::in);
    if (!File) {
        perror("Error: cannot parse instructors information from");
        exit(1);
    }

    string line;
    int row, col = 0;
    fileRow = 0;

    Student** kids = new Student*[fileRow];
    for (int i = 0; i < fileRow; i++) {
        kids[i] = new Student[7];
    }
    
    while (getline(File, line)) {
    
        string trim;
        
        
        currentS = new Student();
        currentS->stUser =  line.substr(0, line.find("\t")); 
        trim = line.substr(line.find("\t"), line.find("\n"));
        line = trim;

        currentS->stPassword = line.substr(1,6);
        trim = line.substr(8, line.find("\n"));
        line = trim;

        currentS->stName = line.substr(0, trim.find("\t"));
        trim = line.substr(line.find("\t"), line.find("\n"));
        line = trim;

        currentS->projGrade = line.substr(1, 3);
        currentS->pGrade = stringToInt(currentS->projGrade);
        currentS->quizGrade = line.substr(4, 3);
        currentS->qGrade = stringToInt(currentS->quizGrade);
        currentS->midGrade = line.substr(7, 3);
        currentS->mGrade = stringToInt(currentS->midGrade);
        currentS->finalGrade = line.substr(10, 3);
        currentS->fGrade = stringToInt(currentS->finalGrade);
        currentS->oGrade = (currentS->pGrade*0.3)+(currentS->qGrade*0.1)+(currentS->mGrade*0.2)+(currentS->fGrade*0.4);
        

        kids[fileRow] = currentS;
        fileRow++;
    }//while
    mainS = kids;
} //read stFile

int main(int argc, char *argv[]) {   
        
    readInFile(argv[1]);
    readStFile(argv[2]);
    
    int userType = 0;
    
    bool typeCheck, legit = false;
    string username,password;
    
        
    while(userType != 3 && legit == false) {
        
        cout << "User types, \n 1 - Instructor \n 2 - Student\n Select a login user type or enter 3 to exit: " << endl;
        cin >> userType;
        if (userType == 1 || 2 || 3) {
            if (userType == 3) {
                exit(1);
            }
        typeCheck = true;
        type = userType;
        } 
        else {
            cout << "Invalid option. Please enter a valid option.";
            exit(1);
        }

         
        if (userType == 1) {
            cout << "Enter credentials to login, Enter Username: " << endl;
            cin >> username;
            cout << "Enter Password: " << endl;
            cin >> password;
            //bool tempI = currentI->login(username,password);
            legit = true;
        }
        if (type == 1 && legit == false) {
            cout << "Login as Instructor failed." << endl;
            cout << "Enter credentials to login, Enter Username: " << endl;
            cin >> username;
            cout << "Enter Password: " << endl;
            cin >> password;
            //currentI->login(username,password);
        }
        
        if (type == 2) {
            cout << "Enter credentials to login, Enter Username: " << endl;
            cin >> username;
            cout << "Enter Password: " << endl;
            cin >> password;
            //currentS->login(username,password);
            legit = true;
        }
        if (type == 2 && legit == false) {
            cout << "Login as Student failed." << endl;
            cout << "Enter credentials to login, Enter Username: " << endl;
            cin >> username;
            cout << "Enter Password: " << endl;
            cin >> password;
            //currentS->login(username,password);
        }
        
    }

    if(instructorIsIn) {
        int response;
        cout << "Query options, \n1 - view grades of a student\n2 - view stats\nEnter option number:" << endl;
        cin >> response;
        if(response == 1) {
            string input;
            cout << "Enter Student username to view grades: " << endl;
            cin >> input;
           //currentI->getStudent(input);

        }
        else if(response == 2) {
            int gt;
            cout << "Grade types,\n1 - Project grade\n2 - Quiz grade\n3 - Midterm grade\n4 - Final grade\n5 - Overall grade\nSelect a grade type to view stats:" << endl;
            cin >> gt;
            //currentI->getMinStudent(gt);
            //currentI->getMaxStudent(gt);
            //currentI->getAvg(gt);
        }
    }
    return EXIT_SUCCESS;
}