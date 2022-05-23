#include <iostream>
#include <unistd.h>
#include <stdio.h>


using namespace std;

int gVar = 6;

int main() {
    int lVar = 4;
    pid_t pid;

    cout << "Prior to fork" << endl;

    if ((pid = fork()) < 0) {
        perror("ERROR IN FORK PROCESS.");
    }
    else if (pid == 0){
        ++gVar;
        ++lVar;
    } else
    {
        sleep(3);
    }
    
    cout << "After fork: " 
         << "pid = " << pid << ", "
         << "gVar = " << gVar << ", "
         << "lVar = " << lVar << endl;
         return EXIT_SUCCESS;
}