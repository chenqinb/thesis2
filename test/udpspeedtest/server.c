#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
int main(int argc, char **argv)
{
    int listenfd;
    
    struct sockaddr_in servaddr;
	char recvline[1514] = {0};
	ssize_t recvsize = 0;
    listenfd = socket(AF_INET, SOCK_DGRAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(50001);

    bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

 	while(1)
	{
		memset(recvline, 0, 1514);
		if( (recvsize =recvfrom(listenfd, recvline,1514,0,NULL,NULL) )<0){
			perror("recv");
			continue;
		}
		printf("%s\n",recvline);
	}
    close(listenfd);

    return 1;
}
