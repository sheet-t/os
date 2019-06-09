#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <sys/types.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    pid_t child_pid;
    pid_t parent_pid;
    char *loop_count;
    
    if (argc < 2)
    {
        assert(printf("Error: no count suppied") >= 0);
        exit(EXIT_FAILURE);
    }
    
    long int end = strtol(argv[1], &loop_count, 10);
    if (errno == ERANGE)
    {
        assert(printf("over/under error occured"));
    }
    
    child_pid=getpid();
    parent_pid=getppid();

    assert(printf("Child PID: %d\n", child_pid) >= 0);
    assert(printf("Parent PID: %d\n", parent_pid) >= 0);
    for (int i = 1; i<=end; i++)
        assert(printf("Process: %d: %d\n", child_pid, i) >= 0);
    
    exit((int)end);
}
