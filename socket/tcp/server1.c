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
    if(bind(sadd,(struct sockaddr*)&saddr,len) < 0)
    {
        perror("bind");
        return;
    }
    if(listen(sadd,5) < 0)
    {
        perror("listen");
        return;
    }
    while(1)
    {
    printf("waiting for client request\n");
    nsadd = accept(sadd,(struct sockaddr*)&caddr,&len);
    if(nsadd < 0)
    {
        perror("accept");
        return ;
    }
    printf("client request accepted\n");
    printf("client port : %d\n",ntohs(caddr.sin_port));
    printf("client ip address : %s\n",inet_ntoa(caddr.sin_addr));
    char s[20];
    while(1)
    {
    read(nsadd,s,20);
    if(strcmp("bye",s) == 0)
        break;
    printf("data is :%s\n",s);
    for(i=0;s[i];i++)
    {
            if(s[i] >='a' && s[i] <= 'z')
        {
            s[i] = s[i] - 32;
        }
    }
    write(nsadd,s,sizeof(s)+1);
    }
    }
    close(sadd);


}
