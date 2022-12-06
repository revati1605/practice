#include "header.h"
void main(int argc , char **argv)
{   
    if(argc != 3)
    {
        printf("./a.out port_addr ip_addr\n");
        return;
    }
    int sfd,len;
    struct sockaddr_in saddr,caddr;
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
    if(bind(sfd,(struct sockaddr*)&saddr, len) < 0)
    {
        perror("bind");
        return;
    }
    while(1)
    {
    char str[20];
    recvfrom(sfd,str,sizeof(str),0,(struct sockaddr*)&caddr,&len);
    printf("client message:%s\n",str);   
    int ele,i,j;
    ele = strlen(str);
    char t;
     for(i=0;i<ele;i++)
    {
        for(j=0;j<ele-i;j++)
        {
            if(str[j]>str[i])
            {
                t=str[i];
                str[i]=str[j];
                str[j]=t;
              }
        }
    }
    sendto(sfd,str,strlen(str)+1,0,(struct sockaddr*)&caddr,len);
    }
    close(sfd);
}
