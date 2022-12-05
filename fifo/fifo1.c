//job of this process is to scan data from user and put it into fifo
#include"header.h"
void main()
{
    mkfifo("f1",0664);//we are creating fifo using this function.If file already present this function will fail.
//we can create fifo using command also then function call is not required.
    perror("mkfifo");
    int fd = open("f1",O_WRONLY);//file is open for writing purpose
    //it will block if any of process is not opened for reading
    if(fd < 0)
    {
        perror("open");
        return;
    }
    char s[20];
    printf("enter data\n");
    scanf("%s",s);
    write(fd,s,strlen(s)+1);
}
