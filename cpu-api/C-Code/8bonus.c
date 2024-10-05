#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int pipearray[2]; // pipearray[0] input, pipearray[1] output
    pipe(pipearray);

    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child1 (new process)
        close(pipearray[0]); // Close reading end in child1
        dup2(pipearray[1], STDOUT_FILENO); // Redirect stdout to pipe
        close(pipearray[1]); // Close writing end after duplication

        // Send a message through the pipe
        printf("hello from child1 hallo gallo mallo\n");
        exit(0); // Terminate child1
    } else {
        // parent creates another child process
        int re = fork();
        if (re < 0) {
            // fork failed; exit
            fprintf(stderr, "fork failed\n");
            exit(1);
        } else if (re == 0) {
            // child2 (new process)
            close(pipearray[1]); // Close writing end in child2

            char buffer[128]; // Buffer to store input from the pipe
            char result[600]; // Buffer to store concatenated result
            int bytesRead;
            result[0] = '\0'; // Initialize the result string

            // Read from the pipe until EOF (when pipe is closed)
            while ((bytesRead = read(pipearray[0], buffer, sizeof(buffer) - 1)) > 0) {
                buffer[bytesRead] = '\0'; // Null-terminate the read data
                strcat(result, buffer);   // Concatenate the read data to result
            }
            close(pipearray[0]); // Close reading end in child2 after reading

            printf("hello from child2\n");
            printf("I'll tell you what child1 has to say: %s\n", result);
            exit(0); // Terminate child2
        } else {
            // parent goes down this path (original process)
            close(pipearray[0]);
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