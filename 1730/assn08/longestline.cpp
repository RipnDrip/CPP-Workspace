#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <fcntl.h>
#include <iostream>

using namespace std;
#define BUFFSIZE 10

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
    char value;
    int bytes, max = 0;

    //buf is where read bytes are stored.
    //BUFFERSIZE is the number of bytes to read
    int length = 0;
    while ((bytes = read(fd, buf, BUFFSIZE)) > 0)
    {
        
        for (int i = 0; i < bytes; i++)
        {
            if (buf[i] != '\n')
            {
                length++;
                if (length > max)
                {
                    max = length;
                }
            }
            else
            {
                length = 0;
            }
        }
    }
    if (max == -1)
    {
        max = BUFFSIZE;
    }
    cout << max << '\n';
    if (bytes < 0)
    {
        perror("Error. Cannot read file. Bytes less than 0.");
        exit(4);
    }

    return EXIT_SUCCESS;
}