#include "header.h"
void main(int argc,char **argv)
{
       if(argc != 3)
    {   
        printf("./a.out port_addr ip_addr\n");
        return;
    }   
    int sfd,len;
    struct sockaddr_in saddr;
    sfd = socket(AF_INET, SOCK_DGRAM ,0);
    if(sfd < 0)
    {   
        perror("socket");
        return;
    }   
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(atoi(argv[1]));
    saddr.sin_addr.s_addr = inet_addr(argv[2]);
    len = sizeof(saddr);
    char str[20];
    while(1)
    {
    printf("enter string:\n");
    gets(str);
    sendto(sfd,str,strlen(str)+1,0,(struct sockaddr*)&saddr,len);
    recvfrom(sfd,str,sizeof(str),0,(struct sockaddr*)&saddr,&len);
    printf("data is:%s\n",str);
    }
    close(sfd);
}
