#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <assert.h>

int main(void)
{
    int status;
    pid_t childID;
    int wait_status;
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
        assert(waitpid(childID, &status, 0) >= 0);
        if (WIFEXITED(status))
        {
            assert(printf("Process %d exited with status: %d\n", childID, 
                WEXITSTATUS(status)) >= 0);
        }
        exit(EXIT_SUCCESS);
    }
    
}
