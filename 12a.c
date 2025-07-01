// a) Write a program to demonstrate the zombie state of a process and
// provide the solution for the same.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child process (PID: %d) exiting\n", getpid());
        exit(0);
    } 
    else {
        wait(NULL);  // <-- Solution: Clean up the child process
        sleep(30);
        printf("Parent process (PID: %d) sleeping\n", getpid());
        printf("Parent exiting\n");
    }

    return 0;
}

// ./a.out
// ps aux | grep Z

// gedit p1.c
// gcc p1.c
// ./a.out
