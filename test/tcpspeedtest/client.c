#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <sys/time.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>

#define BUFSIZE 1514
int main(int argc, char **argv)
{
    int sockfd;
    struct sockaddr_in servaddr;
	int fd = -1;
	int ret = 0;
	char Buf[BUFSIZE] = {0} ;
	ssize_t ReadSize = 0;
	if( argc !=3){
		printf("argc !=3\n");
		exit(-1);
	}
    sockfd = socket(PF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(50001);
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);

    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	fd = open(argv[2], O_RDONLY);
	if( fd < 0)
	{
		printf("error:open file %s %d", argv[2], errno);
		exit(-1);
	}


    char sendline[100];
    sprintf(sendline, "Hello, world!");
{
	struct timeval start,end;
	long int i = 0;
	gettimeofday(&start, NULL);
	while( (ReadSize = read (fd, Buf, BUFSIZE)) >0) 
	{
		ret = write(sockfd, Buf, ReadSize);
		if( ret <0)
		{
			printf("write erro %d %s\n", ret,strerror(errno));
		}
		//i++;
	}
	gettimeofday( &end, NULL);
	printf("%ld\n",1000000 * ( end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec);
	//printf("%ld\n",i);
}
    close(sockfd);

    return 1;
}
