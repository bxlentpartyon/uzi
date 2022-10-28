#ifndef __MACHDEP_H__
#define __MACHDEP_H__

void di(void);
void ei(void);
void idump(void);
void warning(char *s);

/* Not actually implemented yet */
unsigned int in(unsigned int *addr);
void out(char c, unsigned int *addr);

#endif /* __MACHDEP_H__ */
