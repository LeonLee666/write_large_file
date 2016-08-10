#include "util.h"

long long get_ntime(void)
{
	struct timespec timeNow;
	clock_gettime(CLOCK_MONOTONIC, &timeNow);
	return timeNow.tv_sec * 1000000000 + timeNow.tv_nsec;
}

long long get_utime(void)
{
	return get_ntime() / 1000;
}

long long get_mtime(void)
{
	return get_ntime() / 1000000;
}

//if the file size > 2GB, it runs very well
void writeLarge(int fd, const void *mem, size_t count)
{
	size_t block = (size_t)1024*1024*1024;
	int G = (size_t)count / block;
	int mod = count % block;
	for(int i=0; i< G; i++)
	{
        	write(fd, mem+(size_t)i*block,block);
        	//lseek(fd, (size_t)(i+1)*block , SEEK_SET);
		lseek(fd, 0, SEEK_END);
	}
	write(fd,mem+(size_t)G*block,(size_t)mod);
	//fsync(fd);
}
