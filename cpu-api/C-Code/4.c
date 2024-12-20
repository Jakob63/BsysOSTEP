#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <features.h>

int main() {
    char *argv[] = {"ls", (char *)NULL};
    char *envp[] = {"PATH=/usr/bin", NULL};

    int rc = fork();
    if(rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if(rc == 0) {
        if (execl("/bin/ls", "ls", (char *)NULL) == -1) { // -l -a -h
            fprintf(stderr, "execl failed\n");
            exit(1);
        }
    }
    waitpid(rc, NULL, 0);

    rc = fork();
    if(rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if(rc == 0) {
        if (execle("/bin/ls", "ls", (char *)NULL, envp) == -1) {
            fprintf(stderr, "execle failed\n");
            exit(1);
        }
    }
    waitpid(rc, NULL, 0);

    rc = fork();
    if(rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if(rc == 0) {
        if (execlp("ls", "ls", (char *)NULL) == -1) {
            fprintf(stderr, "execlp failed\n");
            exit(1);
        }
    }
    waitpid(rc, NULL, 0);

    rc = fork();
    if(rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if(rc == 0) {
        if (execv("/bin/ls", argv) == -1) {
            fprintf(stderr, "execv failed\n");
            exit(1);
        }
    }
    waitpid(rc, NULL, 0);

    rc = fork();
    if(rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if(rc == 0) {
        if (execvp("ls", argv) == -1) {
            fprintf(stderr, "execvp failed\n");
            exit(1);
        }
    }
    waitpid(rc, NULL, 0);

    rc = fork();
    if(rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if(rc == 0) {
        if (execvpe("ls", argv, envp) == -1) {
            fprintf(stderr, "execvpe failed\n");
            exit(1);
        }
    }
    waitpid(rc, NULL, 0);
    return 0;
}