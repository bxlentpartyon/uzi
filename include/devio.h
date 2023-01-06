#ifndef __DEVIO_H__
#define __DEVIO_H__

#include "unix.h"

int remq(struct s_queue *q, char *cp);
int uninsq(register struct s_queue *q, char *cp);
int insq(register struct s_queue *q, char c);
void brelse(bufptr bp);
int cdread(int dev);
void bawrite(bufptr bp);
int cdwrite(int dev);
int bfree(register bufptr bp, int dirty);
void bufsync(void);
int d_ioctl(int dev, int request, char *data);
int validdev(int dev);
void bufdump(void);
void bufinit(void);
void swapread(int dev, blkno_t blkno, unsigned nbytes, char *buf);
void swapwrite(int dev, blkno_t blkno, unsigned nbytes, char *buf);

#endif
