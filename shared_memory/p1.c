#include "header.h"
void main()
{
    int id = shmget(3,50,IPC_CREAT|0664);
    if(id < 0)
    {
        perror("shmget");
        return;
    }
    char *p;
    p=shmat(id,0,0);
    printf("enter data\n");
    scanf("%s",p);
}
