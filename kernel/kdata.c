#include <extern.h>
#include <unix.h>

/* Process/userspace stuff */

struct u_data udata;
ptptr initproc; /* The process table address of the first process. */
struct p_tab ptab[PTABSIZE];

/* Interrupt/timer stuff */

time_t tod;      /* Time of day */
int16 inint;   /* flag is set whenever interrupts are being serviced */
int16 runticks;  /* Number of ticks current process has been
                    swapped in */
int16 sec;   /* Tick counter for counting off one second */

/* Filesystem stuff */

inoptr root;   /* Address of root dir in inode table */
int16 ROOTDEV;
struct cinode i_tab[ITABSIZE];    /* In-core inode table */
struct oft of_tab[OFTSIZE];
struct filesys fs_tab[NDEVS];

/* Driver stuff */

struct blkbuf bufpool[NBUFS];
