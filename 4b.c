//4.b) Write a C program to
//i. To create a child process.
//ii. The child should execute an interpreter file by passing a few arguments
//iii. Create an interpreter file that has the path of echoall.c file and pass one argument
//iv. Create echoall.c file which prints the arguments received from both child process and
//interpreter file.

// echoall.c 
#include<stdio.h>

int main(int argc, char *argv[]) {
    for(int i=0; i<argc; i++){
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    return 0;
}


// child.c 
#include<sys/wait.h>
#include<unistd.h>

int main(){
    if (fork()==0){
        execl("./textinterpreter", "dummy", "arg1", "arg2", "g3", (char *)0);
    }
    else{
        wait(NULL);
    }
    return 0;
}

// textinterpreter.sh
    
#!/bin/bash
$(realpath ./echoall) myArg "$@"   
  

// Instructions to Build and Run: Save each block above into its own file
// main.c, child.c , textinterpreter

// Make the script executable:
// chmod +x textinterpreter

// Compile the C files:
// gcc -o main main.c
// gcc -o child child.c

// Run the program:
// ./child 