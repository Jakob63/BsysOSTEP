#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    FILE * f = fopen("file1.txt", "w");
    if (f == NULL){
        // open file failed
        fprintf(stderr, "open file failed\n");
        exit(1);
    }

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
        fprintf(f, "hello I'm Child my x is: %d\n", x);
    } else {
        // parent goes down this path (original process)
        x = x+2; //x ist 100 trotz änderung in Child
                 // wegen eigenem address space
        fprintf(f, "hello I'm Parent my x is: %d\n", x);
    }
    return 0;
}



