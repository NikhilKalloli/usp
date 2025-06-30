// b) Write a program to perform the following operations
// i) To create a child process
// ii) The child process should execute a separate program (using exec
// function) that calculates the addition of two numbers by passing two
// integer values.
// iii) The parent process should wait for a child to complete

// parent.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (fork() == 0) { 
        execl("./child", "child", argv[1], argv[2], (char *)NULL);
    }
    else { 
        wait(NULL);
        printf("Child exited.....\n");
    }
    return 0;
}

// ---------------------------------------------------------
// child.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("Sum: %d\n", atoi(argv[1]) + atoi(argv[2]));
    return 0;
}

// gedit parent.c
// gedit child.c
// gcc -o parent parent.c
// gcc -o child child.c
// ./parent 5 6