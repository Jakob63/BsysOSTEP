#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
        close(STDOUT_FILENO);
        printf("hello I'm Child\n");
    } else {
        printf("hello I'm Parent\n");
    }
    return 0;
}