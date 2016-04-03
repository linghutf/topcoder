#include "rdwrn.h"

/**
 * return numbers of bytes read,
 * 0 on EOF,
 * or -1 error
 */
ssize_t readn(int fd,void *buffer,size_t count);
/**
 * -1 error
 */
ssize_t writen(int fd,void *buffer,size_t count);
