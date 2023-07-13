#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h>
int main(){
    pid_t pid;
    int status;
    printf("1");
    printf("\n");
    printf("\n");
    
    if(fork() == 0){
        if(fork() == 0){
            printf("2");
            printf("\n");
            printf("\n");
           
        }
    }
    else{
        printf("3");
        printf("\n");
        printf("\n");
        
        if(fork() == 0){
            printf("4");
            printf("\n");
            printf("\n");
            
            exit(0);
        }
        else{
            wait(&status);
            printf("5");
            printf("\n");
            printf("\n");
           
        }
    }
    printf("6");
    printf("\n");
    printf("\n");
    
    return 0;

}