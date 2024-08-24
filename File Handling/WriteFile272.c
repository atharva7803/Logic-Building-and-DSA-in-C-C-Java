#include<stdio.h>
#include<unistd.h>      
#include<fcntl.h>     
#include<stdlib.h>


int main(){

    int fd = 0;     // fd: file descriptor
    char FileName[30];

    printf("Enter the file name that you want to open: \n");
    scanf("%s", FileName);

    fd = open(FileName, O_RDWR);     

    if(fd == -1){
        printf("Unable to open file\n");
        return 0;
    }
    
    write(fd, "Hello World", 11);

    return 0;
}



