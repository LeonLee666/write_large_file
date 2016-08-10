#undef  _FILE_OFFSET_BITS   
#define _FILE_OFFSET_BITS 64   
#define __USE_FILE_OFFSET64
#define __USE_LARGEFILE64
#define _LARGEFILE64_SOURCE
#include <unistd.h>   
#include <dirent.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "util.h"
#include <fcntl.h>


int main()
{
	int sz=0;
	scanf("%d",&sz);
	size_t length = (size_t)1024*1024*1024*sz;
	char* mem = (char*) malloc(sizeof(char)*(size_t)length);
	int fd = open("./test.dat",O_RDWR | O_TRUNC | O_SYNC | O_CREAT , 666);
	long begin = get_utime();
	for(size_t i=0; i<length; i++)
	{
		*(mem+i) ='0';
	}
	writeLarge(fd, mem, length);
	close(fd);
	long end = get_utime();
	printf("%ld\n",end-begin);
}
