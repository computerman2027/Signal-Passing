#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void handle_sigkill(int sig)
{
    printf("\nKilling the process by SIGKILL");
    exit(0);
}

int main()
{
    // Install the SIGKILL handler
    signal(SIGKILL, handle_sigkill);
    
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",i);
    }
    printf("\n");
    kill(getpid(),SIGKILL);
    return 0;
}
