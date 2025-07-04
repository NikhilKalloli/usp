// b) Demonstrate the working of wait and waitpid system calls with a program

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid1 = fork();
    int pid2 = fork();

    if (pid1 == 0) {
        printf("first pid: %d\n", getpid());
        sleep(2);
        exit(0);
    }

    if (pid2 == 0) {
        printf("second pid: %d\n", getpid());
        sleep(4);
        exit(0);
    }

    wait(NULL);
    printf("first wait\n");

    waitpid(pid2, NULL, 0);
    printf("second wait\n");

    return 0;
}

// run: gcc p1.c
// run: ./a.out