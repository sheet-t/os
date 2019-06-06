#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int p_id, p_pid;
    int a = atoi(argv[1]);
    p_id=getpid();
    p_pid=getppid();

    printf("Child PID: %d\n", p_id);
    printf("Parent PID: %d\n", p_pid);
    for (int i = 0; i<=a; ++i)
        printf("Process: %d %d\n", p_id, ++i);
    
    return 0;
}
