#ifndef __SYSCALL_H__
#define __SYSCALL_H__

void readi(register inoptr ino);
void writei(register inoptr ino);
int doclose(int16 uindex);

/* stuff below is static to scall1.c and should be pulled out of the header */
void updoff(void);
int min(int a, int b);


#endif /* __SYSCALL_H__ */
