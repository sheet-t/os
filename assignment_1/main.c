#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

int main(void)
{
    int i, status;
    pid_t childID, endID;
    int pid=getpid();

    if ((childID = fork()) == -1)
    {
        perror("fork error");
        exit(EXIT_FAILURE);
    }
    else if (childID == 0)
    {
        execl("./counter","counter", "5", NULL);    
    }
    else
    {
        printf("Process %d exited with status: %d", pid, childID);
        exit(EXIT_SUCCESS);
    }
    
}
