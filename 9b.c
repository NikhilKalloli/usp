//9.b) Write a C program
//i.	To read the first 20 characters from a file
//ii.	Seek to 10th byte from the beginning and display 20 characters from there 
//iii.	Seek 10 bytes ahead from the current file offset and display 20 characters
//iv.	Display the file size             

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(){
	
    int file=open("test.txt",O_RDONLY);
    char buf[20];
    struct stat st;
	
    read(file, buf, 20); 
    buf[20] = '\0';
    printf("First 20 chars     : %s\n", buf);

    lseek(file, 10, SEEK_SET);     
    read(file, buf, 20);
    buf[20] = '\0';
    printf("From 10th byte     : %s\n", buf);

    lseek(file, 10, SEEK_CUR);     
    read(file, buf, 20);
    buf[20] = '\0';
    printf("10 bytes ahead     : %s\n", buf);
	
    stat(file,&st);
    printf("\n%ld",st.st_size);
}

// run: gcc p1.c
// create test.txt with 100 char text.
// run: ./a.out