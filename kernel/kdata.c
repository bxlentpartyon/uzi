#include <extern.h>

/* Process/userspace stuff */

struct u_data udata;
struct p_tab ptab[PTABSIZE];

/* Interrupt/timer stuff */

time_t tod;      /* Time of day */
int16 inint;   /* flag is set whenever interrupts are being serviced */

/* Filesystem stuff */

inoptr root;   /* Address of root dir in inode table */
struct cinode i_tab[ITABSIZE];    /* In-core inode table */

/* Driver stuff */

