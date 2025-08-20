#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void handle_sigterm(int sig)
{
    printf("\nProcess %d has been killed by SIGTERM\n", getpid());
    exit(0);
}

int main()
{
    // Install the SIGTERM handler
    signal(SIGTERM, handle_sigterm);

    int n;
    printf("Enter a number : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", i);
    }
    printf("\n");

    // Send SIGTERM to itself (catchable, will invoke handler)
    kill(getpid(), SIGTERM);

    return 0;
}
