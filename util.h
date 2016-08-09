#pragma once

#include <stdio.h>
#include<sys/mman.h>
#include<fcntl.h>
#include <time.h>
#include <numa.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

#define __USE_GNU
#include <sched.h>
#include <pthread.h>

long long get_ntime(void);
long long get_utime(void);
long long get_mtime(void);

