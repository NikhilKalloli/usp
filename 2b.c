//2.b) Write a C program to simulate system function. 
#include <unistd.h>
#include <sys/wait.h>

int my_system(const char *cmd) {
    if (fork() == 0)
        execl("/bin/sh", "sh", "-c", cmd, NULL);
    int status;
    wait(&status);
    return status;
}

int main() {
    printf("executing ls-li\n");
    my_system("ls -l");
    return 0;
}

// gcc p1.c
// ./a.out

// The output will show the execution of the command "ls -li" in the child process.