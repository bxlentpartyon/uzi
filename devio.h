#ifndef __DEVIO_H__
#define __DEVIO_H__

#include "unix.h"

int remq(struct s_queue *q, char *cp);
int uninsq(register struct s_queue *q, char *cp);
int insq(register struct s_queue *q, char c);

#endif
