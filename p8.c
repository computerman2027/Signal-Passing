#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

void handle_sigterm(int sig)
{
    printf("\nProcess %d has been killed by SIGTERM\n", getpid());
    exit(0);
}

int main()
{
    signal(SIGTERM, handle_sigterm);
    printf("Starter id = %d\n", getpid());

    for (int i = 0; i < 9; i++)
    {
        fork();
    }

    printf("PID = %d PPID = %d EXIT\n", getpid(), getppid());
    kill(getpid(), SIGTERM);

    // parent waits for children (prevents prompt messing)
    while (wait(NULL) > 0)
        ;
    return 0;
}
