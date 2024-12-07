#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void create_child(const char *path, const char *arg, ...) {  // To avoid ugly indentations 
    pid_t pid;
    pid = fork();
    if (pid > 0) {  // I am the parent
        wait(NULL);
    } else if (!pid) { // I am the child
        execl(path, arg, NULL);
    } else if (pid == -1) {  // In case of error
        printf("Error");
    }
}

int main(){
    create_child("/usr/bin/ls", "ls", NULL);
    create_child("/usr/bin/date", "date", NULL);
    printf("create_child \n");
    return 0;
}