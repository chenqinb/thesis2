#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <pcap.h>
#include <fcntl.h>
#include <errno.h>
#include "debug.h"
#include <sys/time.h>
#define BUFSIZE 1514
int Authentication(const char *DeviceName, const char *FileName);

int main(int argc, char *argv[])
{
	/*check if root */
	if (getuid() != 0) {
		fprintf(stderr, "Sorry,it is unroot.\n");
		exit(-1);
	}
	/* check the argc*/
	if (argc !=3 ) {
		fprintf(stderr, "Command is Illegal\n");
		fprintf(stderr,	"    %s Interface_Of_Wlan fileName\n", argv[0]);
		exit(-1);
	}
	Authentication(argv[1], argv[2]);
	return (0);
}

int lookupdev(void)
{
	char errBuf[PCAP_ERRBUF_SIZE], *device;
	device = pcap_lookupdev(errBuf);
	if( device)
		printf("success:device %s\n",device);
	else
		printf("error:%s\n",errBuf);
	return 0;
}


int Authentication(const char *DeviceName, const char *FileName)
{
	char errBuf[PCAP_ERRBUF_SIZE] = {0} ;

	char Buf[BUFSIZE] = {0}; 
	pcap_t *device = NULL ;
	ssize_t ReadSize = 0;
	int fd = -1;
	int ret = 0;
	struct timeval start,end;
	//lookupdev();
	device = pcap_open_live(DeviceName, 65535, 1, 0, errBuf);
	if( !device)
	{
		printf("error:pcap_open_live():%s\n",errBuf);
		exit(1);
	}

	fd = open(FileName, O_RDONLY);
	if( fd < 0)
	{
		printf("error:open file %s %d", FileName, errno);
		exit(1);
	}
	//send file
	{	
		long int i = 0;
			gettimeofday(&start, NULL);
		while( (ReadSize = read (fd, Buf, BUFSIZE)) >0)
		 {
			//printf("%d\n",ReadSize);
			//ret = pcap_sendpacket(device,(const u_char *) Buf, ReadSize);
			//if( ret != 0)
			//{
			//	printf("sendpacket error %d %s\n", ret, pcap_geterr(device));
			//	break;
			//}

			i++;

		 }	
		 		gettimeofday( &end, NULL);
			printf("%ld\n",1000000 * ( end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec);
			printf("%ld\n",i);
	}

	close(fd);
	pcap_close(device);
	return 0;
}
