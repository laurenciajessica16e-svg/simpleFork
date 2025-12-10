#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
    int pid, i, endvalue;

    endvalue = 1000;
    printf("calling fork()\n");

    pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
        exit(0);
    }
    else if (pid == 0)
    {
        // child process
        for (i = 0; i < endvalue; i++)
        {
            printf("Child\n");
            fflush(stdout);
        }
    }
    else
    {
        // parent process
        for (i = 0; i < endvalue; i++)
        {
            printf("Parent\n");
            fflush(stdout);
        }
        wait(NULL);
    }

    return 0;
}
