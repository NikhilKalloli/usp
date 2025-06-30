// b) Write a C program to perform the following operations
// i) To create a child and parent process with the use of an echoall
// file.
// ii) The Child should execute a process that prints the user defined
// values of environment variables
// iii) The Parent should execute a process that prints default values
// for the environment variables.

// p1.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    char *env[] = {"USER=unknown", "PATH=/tmp", NULL};
    if (fork() == 0)
        execle("./echoall", "echoall", "myarg1", "MY ARG2", NULL, env);
    wait(NULL);
    execlp("./echoall", "echoall", "only 1 arg", NULL);
    return 0;
}
//-------------------------------------------------------------
// echoall.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
    for (int i = 0; i < argc; i++)
        printf("argv[%d]: %s\n", i, argv[i]);
    for (int i = 0; envp[i]; i++)
        printf("%s\n", envp[i]);
    return 0;
}


// gedit p1.c
// gedit echoall.c
// gcc -o echoall echoall.c
// gcc p1.c
// ./a.out