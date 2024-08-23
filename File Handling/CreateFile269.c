#include<stdio.h>
#include<unistd.h>      // universal standard
#include<fcntl.h>      // file control
#include<stdlib.h>


int main(){

    int fd = 0;     // fd: file descriptor

    fd = creat("Marvellous.txt", 0777);     // 0777 - its a octal number, 0 stands for octal

    if(fd == -1){
        printf("Unable to create file\n");
    }
    else{
        printf("File gets successfully created with fd %d\n", fd);
    }

    return 0;
}