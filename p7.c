#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include<signal.h>

void handle_sigterm(int sig)
{
    printf("\nProcess %d has been killed by SIGTERM\n", getpid());
    exit(0);
}

int main()
{
    // Install the SIGTERM handler
    signal(SIGTERM, handle_sigterm);
    printf("Starter id = %d\n", getpid());
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    // fork();
    // fork();
    // fork();
    // sleep(10);
    printf("PID = %d PPID = %d EXIT\n", getpid(), getppid());
    kill(getpid(), SIGTERM);
    // sleep(15);
    // printf("Hello\n");
}