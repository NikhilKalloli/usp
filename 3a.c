//3.a) Write a C program to remove empty files from the given directory.

#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

int main()
{
    DIR *dp;
    struct dirent *dir;
    int fd, n;

    dp = opendir(".");
    while ((dir = readdir(dp)) != NULL)
    {
        fd = open(dir->d_name, O_RDWR, 0777);
        n = lseek(fd, 0, SEEK_END);
        if (!n)
        {
            unlink(dir->d_name);
        }
    }
    return 0;
}

// create an empty file (ex:empty.txt)
// run: ls
// run: gcc p1.c
// run: ./a.out
// run: ls

// The program will delete all empty files in the current directory.