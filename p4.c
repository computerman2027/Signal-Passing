#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<signal.h>

void handle_sigusr1(int sig)
{
    printf("\nReceived SIGUSR1 signal! Continuing...\n");
}

void handle_sigint(int sig)
{
    printf("\nReceived SIGINT signal! Continuing...\n");
}

void handle_sigkill(int sig)
{
    printf("\nKilling the process by SIGKILL");
    exit(0);
} 

int main()
{
    // Install the SIGUSR1 handler
    signal(SIGUSR1, handle_sigusr1);

    // Install the SIGINT handler
    signal(SIGINT, handle_sigint);

    // Install the SIGKILL handler
    signal(SIGKILL, handle_sigkill);

    printf("Process Id : %d\n", getpid());

    const char *message = "Thank You";

    while (1)
    {
        printf("\r                      ");
        printf("\r%s", message);
        fflush(stdout);
        sleep(1);
        for (int i = 0; i < 3; i++)
        {
            printf(".");
            fflush(stdout);
            sleep(1);
        }
    }
    return 0;
}