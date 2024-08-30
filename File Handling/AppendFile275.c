#include<stdio.h>
#include<unistd.h>      
#include<fcntl.h>     
#include<stdlib.h>
#include<string.h>


int main(){

    int fd = 0;     // fd: file descriptor
    char FileName[30];
    char Arr[100];
    int iRet = 0;   

    printf("Enter the file name that you want to open: \n");
    scanf("%s", FileName);

    fd = open(FileName, O_RDWR | O_APPEND);     // O_APPEND : to avoid the overwriting the data    

    if(fd == -1){
        printf("Unable to open file\n");
        return 0;
    }
    
    printf("Enter the data that you want to write: \n");
    scanf(" %[^'\n']s", Arr);       // give space before % to refresh the buffer


    iRet = write(fd, Arr, strlen(Arr));     // fd: File descriptor ,  Arr: Contains data that you want to write,  strlen(Arr): total no of bytes that you want to write

    printf("Number of bytes written into the file are: %d\n", iRet);    // $

    close(fd);

    return 0;
}


