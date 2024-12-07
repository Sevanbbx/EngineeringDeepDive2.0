#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

int main(){
    std::string input;
    std::vector<std::string> args;
    std::string temp;
    std::string path;
    std::string arg;
    pid_t pid;

    printf("Input in the following format: <path> <command> \n");

    while (true) {
        std::getline(std::cin, input);
        std::istringstream stream(input);
        args.clear();
        
        while (stream >> temp) {
            args.push_back(temp);
        }
        if (args.size() < 2) {
            printf("Input in the following format: <path> <command> \n");
            continue;
        }
        path = args[0];
        arg = args[1];
        pid = fork();

        if (pid > 0) {  // I am the parent
            wait(NULL);
        } else if (!pid) {  // I am the child
            printf("executing...\n");
            if (execl(path.c_str(), arg.c_str(), NULL) == -1) {
                printf("Wrong command \n");
            }
        } else if (pid == -1) {  // in case of error
            printf("Error \n");
        }
    }
    return 0;
}