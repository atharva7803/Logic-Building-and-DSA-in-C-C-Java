#include<stdio.h>
#include<unistd.h>      
#include<fcntl.h>     
#include<stdlib.h>
#include<string.h>


int main(){

    int fd = 0;     // fd: file descriptor
    char FileName[30];
    char Buffer[100] = {'\0'};
    int iRet = 0;
    int iCnt = 0;

    printf("Enter the file name that you want to open: \n");
    scanf("%s", FileName);

    fd = open(FileName, O_RDWR);     // O_APPEND : to avoid the overwriting the data    

    if(fd == -1){
        printf("Unable to open file\n");
        return 0;
    }

    while((iRet = read(fd, Buffer, sizeof(Buffer))) != 0){      // read data from file fd, jevda buffer madhe basel tevda, sizeof(Buffer) = 100 so it will first read 100, then second time 100 and go's on
        for(int i = 0; i < iRet; i++){
            if(Buffer[i] >= 'A' && Buffer[i] <= 'Z'){
                iCnt++;
            }
        }
    }

    printf("Number of capital characters are: %d\n", iCnt);

    close(fd);

    return 0;
}


