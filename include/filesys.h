#ifndef __FILESYS_H__
#define __FILESYS_H__

#include <unix.h>

int super(void);

int uf_alloc(void);
int oft_alloc(void);
void oft_deref(register int of);

int getperm(inoptr ino);
int getmode(inoptr ino);
int isdevice(inoptr ino);
int d_open(int dev);
void d_close(int dev);
void i_ref(inoptr ino);
void i_deref(register inoptr ino);
void f_trunc(register inoptr ino);
void wr_inode(register inoptr ino);
int ch_link(register inoptr wd, char *oldname, char *newname, inoptr nindex);
int fmount(register int dev, register inoptr ino);

void setftime(register inoptr ino, register int flag);

#endif /* __FILESYS_H__ */
