#include <unistd.h>
#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include <string>
#include "Instructor.h"

using namespace std;

// runs the program
// asks the user to login as either a student or instructor
// then displays the grades if the student enters y or exits if n
// if logged in as instructor can look at one student's grades or look at stats for a certain grade type
// then exits
int main() 
{
        char Type;
        char option;
        string username, password;
        while (true) 
        {
                cout << "\n\nUser types," << endl;
                cout << "\t1 - Instructor" << endl;
                cout << "\t2 - Student" << endl;
                cout << "Select a login user type or enter 3 to exit: ";
                cin >> Type;
                if (Type == '1' || Type == '2') 
                {
                        cout << "\nEnter credentials to login," << endl;
                        cout << "\tEnter username: ";
                        cin >> username;
                        cout << "\tEnter password: ";
                        cin >> password;
                }
                if (Type == '1') 
                {
                        Instructor* teacher = new Instructor();
                        if (teacher->login(username, password)) 
                        {
                                cout << "\nYou are now logged in as instructor " << teacher->getInstructorName() << endl;
                                while (true) 
                                {
                                        cout << "\nQuery options," << endl;
                                        cout << "\t1 - view grades of a student" << endl;
                                        cout << "\t2 - view stats" << endl;
                                        cout << "Enter option number: ";
                                        cin >> option;
                                        if (option == '1') 
                                        {
                                                while (true) 
                                                {
                                                        string username;
                                                        cout << "\nEnter student username to view grades: ";
                                                        cin >> username;
                                                        Student kid = teacher->getStudent(username);
                                                        if (kid.getStudentName().compare("") != 0) 
                                                        {
                                                                cout << "\nStudent name: " << kid.getStudentName() << endl;
                                                                cout << "\tProject\t" << kid.getProjectGrade() << "%" << endl;
                                                                cout << "\tQuiz\t" << kid.getQuizGrade() << "%" << endl;
                                                                cout << "\tMidterm\t" << kid.getMidtermGrade() << "%" << endl;
                                                                cout << "\tFinal\t" << kid.getFinalGrade() << "%" << endl;
                                                                cout << "\tOverall\t" << kid.getOverallGrade() << "%" << endl;
                                                                break;
                                                        }
                                                        else
                                                                cout << "\nStudent username is not valid" << endl;
                                                }
                                                break;
                                        }
                                        else if (option == '2') 
                                        {
                                                while (true) 
                                                {
                                                        char gradeType;
                                                        cout << "\nGrade types," << endl;
                                                        cout << "\t1 - Project grade" << endl;
                                                        cout << "\t2 - Quiz grade" << endl;
                                                        cout << "\t3 - Midterm grade" << endl;
                                                        cout << "\t4 - Final grade" << endl;
                                                        cout << "\t5 - Overall grade" << endl;
                                                        cout << "Select a grade type to view stats: ";
                                                        cin >> gradeType;
                                                        if (gradeType == '1' || gradeType == '2' || gradeType == '3' || gradeType == '4' || gradeType == '5') 
                                                        {
                                                                Student minGrade = teacher->getMinStudent(gradeType - 48);
                                                                Student maxGrade = teacher->getMaxStudent(gradeType - 48);
                                                                cout << "\nOverall grade stats," << endl;
                                                                cout << "\tmin " << minGrade.getFinalGrade() << "% (" << minGrade.getStudentName() << ")" << endl;
                                                                cout << "\tmax " << maxGrade.getFinalGrade() << "% (" << maxGrade.getStudentName() << ")" << endl;
                                                                cout << "\tavg " << teacher->getAvg(gradeType - 48) << "%" << endl;
                                                                break;
                                                        }
                                                        else
                                                                cout << "\nInvalid option. Please enter a valid option." << endl;
                                                }
                                                break;
                                        }
                                        else
                                                cout << "\nInvalid option. Please enter a valid option." << endl;
                                }
                        }
                        else
                                cout << "\nLogin as instructor failed." << endl;
                }
                else if (Type == '2') 
                {
                        Student* kid = new Student();
                        if (kid->login(username, password))
                                {
                                cout << "\nYou are now logged in as student " << kid->getStudentName() << endl;
                                cout << "\nDo you want to view grades (y/n)? ";
                                cin >> option;
                                if (option == 'y') 
                                {
                                        cout << "\nStudent name: " << kid->getStudentName() << endl;
                                        cout << "\tProject\t" << kid->getProjectGrade() << "%" << endl;
                                        cout << "\tQuiz\t" << kid->getQuizGrade() << "%" << endl;
                                        cout << "\tMidterm\t" << kid->getMidtermGrade() << "%" << endl;
                                        cout << "\tFinal\t" << kid->getFinalGrade() << "%" << endl;
                                        cout << "\tOverall\t" << kid->getOverallGrade() << "%" << endl;
                                }
                                delete kid;
                        }
                        else
                                cout << "\nLogin as student failed." << endl;
                }
                else if (Type == '3')
                        break;
                else
                        cout << "\nInvalid option. Please enter a valid option." << endl;
        }
        return EXIT_SUCCESS;
}