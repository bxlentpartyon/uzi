#ifndef __PROCESS_H__
#define __PROCESS_H__

void psleep(void *event);
void sendsig(ptptr proc, int16 sig);
void wakeup(void *event);

#endif /* __PROCESS_H__ */
