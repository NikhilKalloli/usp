//2.a) Write a C program to display various details of a file using stat structure (At least 5 fields).

#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat fs;
    lstat("sample.txt", &fs);

    printf("Mode:             %o\n", fs.st_mode & 07777);
    printf("Size:             %lu bytes\n", fs.st_size);
    printf("Number of Links:  %lu\n", fs.st_nlink);
    printf("Inode:            %lu\n", fs.st_ino); 
    printf("Block Size:       %lu\n", fs.st_blksize);

    return 0;
}