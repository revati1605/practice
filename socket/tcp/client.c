#include "header.h"
void main(int argc,char **argv)
{
    if(argc != 3)
    {
        printf("./a.out server port_addr server ip_addr\n");
        return;
    }
    int i,sadd,len,nsadd;
    struct sockaddr_in saddr,caddr;
    sadd = socket(AF_INET, SOCK_STREAM ,0);
    if(sadd < 0)
    {
        perror("socket");
        return;
    }
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(atoi(argv[1]));
    saddr.sin_addr.s_addr = inet_addr(argv[2]);
    len = sizeof(saddr);
 
    if(connect(sadd,(struct sockaddr*)&saddr,len) < 0)
    {
        perror("socket");
        return;
    }
    printf("request send to server\n");

    char s[20];
    while(1)
    {
    printf("enter string from user\n");
    gets(s);
    write(sadd,s,strlen(s)+1);
    if(strcmp("bye",s ) == 0)
        break;
    read(sadd,s,20);
    printf("data :%s\n",s);
    }
  
    close(sadd);

}
