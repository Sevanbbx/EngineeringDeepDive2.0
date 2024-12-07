#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    pid_t pid;
    pid = fork();
    if (pid > 0) {  // if I am the parent
        wait(NULL);
        printf("Parent process done \n");
    } else if (!pid) {  // if I am the child
        execl("/usr/bin/ls", "ls", NULL);
    } else if (pid == -1) {  // in case of error
        printf("Error \n");
    }
    
    return 0;
}
