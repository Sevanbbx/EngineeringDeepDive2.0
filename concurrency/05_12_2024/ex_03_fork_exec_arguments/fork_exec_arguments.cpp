#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    pid_t pid = fork();

    if (pid > 0) {  // I am the parent
        wait(NULL);
        printf("Parent process done \n");
    } else if (!pid) {  // I am the child
        execl("/usr/bin/echo", "echo", "Hello from the child process", NULL);  
    } else if (pid == -1) { // In case of error
        printf("Error \n");
    }
    return 0;
}