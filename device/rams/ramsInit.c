/* ramInit.c - ramInit */

#include <xinu.h>

struct	ramsblk ramstab[Nrams];

/*------------------------------------------------------------------------
 *  ramInit  -  initialize the ramdisk device type
 *------------------------------------------------------------------------
 */
devcall	ramsInit(
	 struct dentry *devptr	/* entry in device switch table	*/
	)
{
	struct ramsblk *ramsptr;	/* pointer to ramtab entry	*/

	ramsptr = &ramstab[ devptr->dvminor ];

	/* Initialize values in the ramdisk block */
	ramsptr->ifopen = 0;
	ramsptr->maxsize = 0;
	ramsptr->fstblk = NULL;
	ramsptr->blksize = (int)(devptr->dvminor + 1) * RMD_BLKSIZ;

	return OK;
}
