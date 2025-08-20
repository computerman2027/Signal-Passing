#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

void handle_sigterm(int sig)
{
    printf("Process %d has been killed by SIGTERM\n", getpid());
    exit(0);
}

int main()
{
    signal(SIGTERM, handle_sigterm);
    printf("Parent PID = %d\n", getpid());

    int n = 10;
    pid_t children[n]; // store PIDs of child processes

    for (int i = 0; i < n; i++)
    {
        pid_t pid = fork();
        if (pid == 0)
        {
            // child process
            printf("Child %d (PID=%d, PPID=%d) running...\n", i, getpid(), getppid());
            pause(); // wait until killed
        }
        else
        {
            // parent saves child PID
            children[i] = pid;
        }
    }

    sleep(2); // let children start
    printf("\nParent killing children...\n");

    for (int i = 0; i < n; i++)
    {
        kill(children[i], SIGTERM); // parent kills each child
    }

    // wait for all children
    while (wait(NULL) > 0)
        ;

    printf("Parent %d exiting.\n", getpid());
    return 0;
}
