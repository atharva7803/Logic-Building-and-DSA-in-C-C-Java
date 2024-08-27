#include<stdio.h>
#include<unistd.h>      
#include<fcntl.h>     
#include<stdlib.h>
#include<string.h>


int main(){

    int fd = 0;     // fd: file descriptor
    char FileName[30];
    char Arr[100] = {'\0'};     // '\0': to clean the array which reduces tha garbage values
    int iRet = 0;   

    printf("Enter the file name that you want to open: \n");
    scanf("%s", FileName);

    fd = open(FileName, O_RDWR);     // O_APPEND : to avoid the overwriting the data    

    if(fd == -1){
        printf("Unable to open file\n");
        return 0;
    }
    
    iRet = read(fd, Arr, 10);       // 10: to read first 10 characters form file

    printf("Number of bytes successfully read from the file: %d\n", iRet);
    printf("Data from file: %s\n", Arr);

    close(fd);

    return 0;
}



