//6.b) Consider the last 100 bytes as a region. Write a C program to check whether the region is locked or not. 
//If the region is locked, print pid of the process which has locked. 
//If the region is not locked, lock the region with an exclusive lock, read the last 50 bytes and unlock the region.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_RDONLY);
    struct flock lock;
    char buffer[51];

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_END;
    lock.l_start = -100;
    lock.l_len = 100;

    fcntl(fd, F_GETLK, &lock);

    if (lock.l_type != F_UNLCK) {
        printf("Region locked by PID: %d\n", lock.l_pid);
    } else {
        lock.l_type = F_WRLCK;
        fcntl(fd, F_SETLK, &lock);

        lseek(fd, -50, SEEK_END);
        read(fd, buffer, 50);
        buffer[50] = '\0';
        printf("Last 50 bytes: %s\n", buffer);

        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &lock);
    }

    close(fd);
    return 0;
}


// ./a.out sample.txt