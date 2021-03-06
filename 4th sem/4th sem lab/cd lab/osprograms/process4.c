#include<stdio.h>
#include<sys/types.h>                            
#include<unistd.h>

int main(){
    pid_t pid, currentPid, parentPid;
    pid = getpid();
    printf("Before fork: Proccess id: %d\n",pid);
    
    pid=fork();
    
    if(pid<0){
        printf("Forking failed...\n");
        return 1;
    }
    if(pid==0){
        printf("Child process.\n");
        currentPid=getpid();
        parentPid=getppid();
        printf("Current pid: %d & Parent pid: %d\n",currentPid,parentPid);
    }else{
        sleep(2);
        printf("Parent process.\n");
        currentPid=getpid();
        parentPid=getppid();
        printf("Current pid: %d & Parent pid: %d\n",currentPid,parentPid);
        printf("Newly created process pid: %d\n",pid);
    }

    return 0;
}