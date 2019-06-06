#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int p_id, p_pid;
    char *a;
    long int end = strtol(argv[1], &a, 10);
    p_id=getpid();

    printf("Child PID: %d\n", p_id);
    for (int i = 1; i<=end; ++i)
        printf("Process: %d %d\n", p_id, i);
    
    return 0;
}
