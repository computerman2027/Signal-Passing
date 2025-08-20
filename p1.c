#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("Process Id : %d\n",getpid());

    const char* message = "Thank You";

    while(1)
    {
        printf("\r                      ");
        printf("\r%s",message);
        fflush(stdout);
        sleep(1);
        for(int i =0;i<3;i++)
        {
            printf(".");
            fflush(stdout);
            sleep(1);
        }
    }
    return 0;
}