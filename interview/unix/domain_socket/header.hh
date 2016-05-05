#ifndef __HEADER__HH__
#define __HEADER__HH__

#include <sys/un.h>
#include <sys/socket.h>
#include <stddef.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SOCK_PATH "test.sock"

#define offsetof(TYPE,MEMBER) ((int)&((TYPE*)0)->MEMBER)

#endif
