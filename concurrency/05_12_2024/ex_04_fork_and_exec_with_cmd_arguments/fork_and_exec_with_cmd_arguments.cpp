#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {  // I am the parent
        wait(NULL);
        printf("Hello from parent \n");
    } else if (!pid) {  // I am the child
        execl("/usr/bin/grep", "grep", "Hello", "text.txt", NULL);
    } else if (pid == -1) {  // in case of error
        printf("Error \n");
    }

    return 0;
}