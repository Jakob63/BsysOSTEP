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
    } else {
        // parent goes down this path (original process)
        int w = waitpid(rc, NULL, 0); // Null keine Statusinfo 0 weil keine Flags 
                                    // mögliche flags: WNOHANG, WUNTRACED machen das warten asynchron
                                    //waitpid ist nützlich für das warten auf ein spezifisches Kind
        printf("goodbye from parent\n");
        printf("parent wait() result: %d\n", w);
    }
    return 0;
}