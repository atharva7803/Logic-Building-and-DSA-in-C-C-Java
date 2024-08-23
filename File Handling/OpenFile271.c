#include<stdio.h>
#include<unistd.h>      // universal standard
#include<fcntl.h>      // file control
#include<stdlib.h>


int main(){

    int fd = 0;     // fd: file descriptor
    char FileName[30];

    printf("Enter the file name that you want to open: \n");
    scanf("%s", FileName);

    fd = open(FileName, O_RDWR);     // O_RDWR: open for read & write

    if(fd == -1){
        printf("Unable to open file\n");
    }
    else{
        printf("File is successfully opened with fd %d\n", fd);
    }

    return 0;
}


/*

O_RDONLY    -   READ MODE
O_WRONLY    -   WRITE MODE
O_RDWR      -   READ + WRITE MODE
O_CREATE    -   CREATE MODE
O_APPEND    -   APPEND MODE

*/


