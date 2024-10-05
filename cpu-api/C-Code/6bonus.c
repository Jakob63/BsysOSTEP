#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int
main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("hello from child \n");
        printf("my PID is: %d\n", getpid());
    } else {
        // parent goes down this path (original process)
        int re = fork();
        if (re < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (re == 0) {
        // child (new process)
        printf("hello from child2 \n");
        printf("my PID is: %d\n", getpid());
    } else {
        // parent goes down this path (original process)
        int w = waitpid(re, NULL, 0);
        int ww = waitpid(rc, NULL, 0);
        printf("goodbye from parent\n");
        printf("my PID is: %d\n", getpid());
        printf("parent wait()1 result: %d\n", w);
        printf("parent wait()2 result: %d\n", ww);
    }
    return 0;
    }
}