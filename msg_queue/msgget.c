#include"header.h"
void main()
{
    int id = msgget(2,IPC_CREAT|0664);
    if(id < 0)
    {
        perror("msgget");
        return;
    }
    printf("id = %d\n",id);
    }
