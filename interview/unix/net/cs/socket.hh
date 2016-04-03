#ifndef _SOCKET_HH_
#define _SOCKET_HH_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h> //bzero

#include <time.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> //fork close

#include <sys/prctl.h> // ptrctl
#include <signal.h>

char *nowtime(char *str,int len);

#endif
