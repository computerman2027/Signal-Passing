#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    pid_t pid = atoi(argv[1]);


    kill(pid, SIGUSR1);

    printf("Sent signal to process %d\n", pid);

    return 0;
}