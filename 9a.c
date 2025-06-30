//9.a) Write a C program to demonstrate the usage of umask and chmod functions.

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    umask(077); // Set umask to 077 (no permissions for group and others
    open("file.txt", O_CREAT | O_WRONLY, 0666); // Create a file with default permissions 0666 (rw-rw-rw-)
    chmod("file.txt", 0644); // Change file permissions to 644 (rw-r--r--)
    return 0;
}

// run: gcc p1.c
// run: ./a.out
// file should be non existent.
// run: ls -l file