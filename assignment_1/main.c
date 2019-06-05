#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int p_id;
    int a = atoi(argv[1]);
    int p_pid = atoi(argv[2]);
    p_id=getpid();

    printf("Child PID: %d\n", p_id);
    printf("Parent PID: %d\n", p_pid);
    for (int i = 0; i<=a; i++)
        printf ("Process: %d %d\n", p_id, ++i);
    
    return 0;
}
