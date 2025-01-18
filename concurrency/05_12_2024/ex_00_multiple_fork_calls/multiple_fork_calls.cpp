#include <unistd.h>


int main(){
    fork();
    fork();
    fork();
    fork();
    sleep(20);
    return 0;
}