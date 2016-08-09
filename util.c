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

