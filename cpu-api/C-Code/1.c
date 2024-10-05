#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    int x = 100;
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        x = x+1; // Child hat eigenen address space 
                 //also quasi ein eigenes x
        printf("hello I'm Child my x is: %d\n", x);
    } else {
        // parent goes down this path (original process)
        x = x+2; //x ist 100 trotz änderung in Child
                 // wegen eigenem address space
        printf("hello I'm Parent my x is: %d\n", x);
    }
    return 0;
}