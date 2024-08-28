#include<stdio.h>
#include<unistd.h>      
#include<fcntl.h>     
#include<stdlib.h>
#include<string.h>


int main(){

    int fdRead = 0, fdWrite = 0;    
    char FileName[30];
    char Buffer[1024] = {'\0'};     // 1024: 1Kb
    int iRet = 0;


    // TO read file
    printf("Enter the existing file name that you want to open: \n");
    scanf("%s", FileName);

    fdRead = open(FileName, O_RDWR);     

    if(fdRead == -1){
        printf("Unable to open file\n");
        return 0;
    }



    // To create new file to write into it
    printf("Enter the name of file that you want to create: \n");
    scanf("%s", FileName);

    fdWrite = creat(FileName, 0777);
    
    if(fdWrite == -1){
        printf("Unable to create new file\n");
        return 0;
    }



    // To copy the contents of read file into newly created file which is fdWrite
    while((iRet = read(fdRead, Buffer, sizeof(Buffer))) != 0){     
        write(fdWrite, Buffer, iRet);       // This will copy the contents of fdRead file into fdWrite file

        memset(Buffer, 0, sizeof(Buffer));      // To clean the data (flush before using data)
    }

    close(fdRead);
    close(fdWrite);

    return 0;
}


