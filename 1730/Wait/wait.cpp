#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main() {
  int pid;
  int status;
  if((pid = fork()) == 0) {
    // child
    cout << "child pid = " << getpid() << endl;
    while(1) {
      cout << "child waiting" << endl;
      sleep(1);
    }
  } else {
    // parent
    wait(&status);		// blocking wait
    cout << "in parent" << endl;
    if(WIFEXITED(status)) {
      cout << "child exited with status " << WEXITSTATUS(status) << endl;
    } else if (WIFSIGNALED(status)) {
      cout << "child was signaled, sig = " << WTERMSIG(status) << endl;
    }
  }
  return 0;
}
