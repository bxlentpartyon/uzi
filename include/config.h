/**************************************************
UZI (Unix Z80 Implementation) Kernel:  config.h
***************************************************/

#ifndef __CONFIG_H__
#define __CONFIG_H__

extern tty_open(), tty_close(), tty_read(),tty_write();
extern mem_read(),mem_write();
extern null_write();

#define NDEVS   3    /* Devices 0..NDEVS-1 are capable of being mounted */
#define TTYDEV  5    /* Device used by kernel for messages, panics */
#define SWAPDEV  3   /* Device for swapping. */
#define NBUFS  4     /* Number of block buffers */

#endif /* __CONFIG_H__ */
