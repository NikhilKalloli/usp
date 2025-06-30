// a) Write a C program such that it initializes itself as a Daemon Process.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void createDaemon() {
    pid_t pid = fork();

    if (pid > 0) exit(0);
    setsid();

    while (1) {
        sleep(10);
        // Daemon's work here
    }
}

int main() {
    createDaemon();
    return 0;
}

// ps aux | grep compiled filename

// to stop deamon:
// sudo kill -9 <pid>