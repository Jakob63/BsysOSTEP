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
        printf("hello from Child\n");
    } else {
        // parent goes down this path (original process)
        sleep(1); // pausiert das Programm für 1 sec
                  // und nutzt die CPU in der zeit nicht
        printf("goodbye from Parent\n");
    }
    return 0;
}