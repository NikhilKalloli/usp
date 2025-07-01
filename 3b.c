//3.b) Write a C program to implement ls  –li command which lists the files in a specified directory.
//Your program should Print 5 attributes of files.

#include <dirent.h>
#include <unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include <stdio.h>
int main()
{
	struct dirent *dir;
	DIR *dp=opendir(".");
	struct stat st;
	while(dir = readdir(dp))
	{
		printf("\n%ld %ld %ld %o %ld %s\n",
            st.st_size, st.st_nlink, st.st_ino , st.st_mode, st.st_atime , dir->d_name);
	}
}

// gcc p1.c
// ./a.out
// ls -l
