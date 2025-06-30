#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<syslog.h>
#include<fcntl.h>
#include<unistd.h>


int main(){
    int st;
    pid_t pid1 = fork();
    pid_t pid2 = fork();

    if(pid1 == 0){
        printf("First pid: %d", getpid());
        sleep(2);
        exit(0);
    }

     if(pid2 == 0){
        printf("Second pid: %d", getpid());
        sleep(2);
        exit(0);
    }

    wait(&st);
    printf("first wait");

    waitpid(pid2, &st, 0);
    printf("Second wait");
    return 0;
}