#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#

int
main(int argc, char *argv[])
{
    int pipearray[2]; // pipearray[0] input [1] ist output
    pipe(pipearray);

    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child1 (new process)
        close(pipearray[0]);
        dup2(pipearray[1], STDOUT_FILENO); 
        // verbindet pipe[1] mit I/O Stream
        // nun wird alles aus printf in die pipe geleitet
        close(pipearray[1]);
        printf("hello from child1 \n");
    } else {
        // parent goes down this path (original process)
        int re = fork();
        if (re < 0) {
            // fork failed; exit
            fprintf(stderr, "fork failed\n");
            exit(1);
        } else if (re == 0) {
            // child2 (new process)
            close(pipearray[1]);
            dup2(pipearray[0], STDIN_FILENO);
            close(pipearray[0]);
            char * pointer = malloc(sizeof(char)*600); // 600 weil bestimmt groß genug
            char * pointer2 = malloc(sizeof(char)*600);
            char * pointer3 = malloc(sizeof(char)*600);
            scanf("%s%s%s", pointer, pointer2, pointer3);
            printf("hello from child2 \n");
            printf("I'll tell you what child1 has to say: %s %s %s\n", pointer, pointer2, pointer3);
            free(pointer);
            free(pointer2);
            free(pointer3);
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