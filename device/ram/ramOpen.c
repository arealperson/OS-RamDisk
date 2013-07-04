/* ramOpen.c - ramOpen */

#include <xinu.h>
#include <stdlib.h>

/*------------------------------------------------------------------------
 *  ramOpen  -  creates a RAMDISK of the specificed size
 *------------------------------------------------------------------------
 */
did32	ramOpen(
	struct dentry *devptr,	/* entry in device switch table	*/
	char *maxsize,
	char *extra
	)
{
	struct ramblk *ramptr;	/* pointer to ramtab entry	*/
	int i;

	ramptr = &ramtab[ devptr->dvminor ];
	
	if (ramptr->ifopen == 0) {
		ramptr->ifopen = 1;
		ramptr->maxsize = atoi(maxsize);
		ramptr->fstblk = getmem(ramptr->blksize * ramptr->maxsize);
		return 1;
	}
	else {
		for (i=0;i<Nrams;i++) {
			if(ramstab[i].ifopen == 0) {
				ramstab[i].ifopen = 1;
				ramstab[i].maxsize = atoi(maxsize);
				ramstab[i].fstblk = getmem(ramstab[i].blksize * ramstab[i].maxsize);
				return 2+i;
			}
		}
	}	
	return SYSERR;
}
