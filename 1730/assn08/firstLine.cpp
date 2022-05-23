#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <fcntl.h>
#include <iostream>

using namespace std;
#define BUFFSIZE 1

void failure(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        failure("Error. There is incorrect usage.");
    }

    int fd = open(argv[1], O_RDONLY); // fd = file destination value
    if (fd < 0)
    {
        perror("Error. The file could not be opened.");
        exit(2);
    }

    char buf[BUFFSIZE];
    int bytes,length;
    int buffCount = 0;
    char value;
    //buf is where read bytes are stored.
    //BUFFERSIZE is the number of bytes to read

    while ((bytes = read(fd, buf, BUFFSIZE)) > 0)
    {
        if (write(STDOUT_FILENO, buf, bytes) != bytes)
        {
            perror("There was an error writing. Written bytes does not match Read bytes.");
            exit(3);
        }
        
        for (int i = 0; i < BUFFSIZE; i++)
        {
            value = buf[i];
            if (value == '\n')
            {
                return EXIT_SUCCESS;
            }
        }
    }

    if (bytes < 0)
    {
        perror("Error. Cannot read file. Bytes less than 0.");
        exit(4);
    }

    return EXIT_SUCCESS;
}