// Write a C program using sigaction system call which calls a signal handler on 
// SIGINT signal and then reset the default action of the SIGINT signal.

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum) {
    printf("SIGINT received, custom handler executed.\n");
    signal(SIGINT, SIG_DFL);  // Reset to default action
}

int main() {
    struct sigaction sa = {0};
    sa.sa_handler = handler;
    sigaction(SIGINT, &sa, NULL);

    while (1) {
        printf("Running... Press Ctrl+C\n");
        sleep(1);
    }

    return 0;
}

// gedit p1.c
// gcc p1.c
// ./a.out

// Press Ctrl+C to trigger the signal handler.