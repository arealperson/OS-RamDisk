/* ramInit.c - ramInit */

#include <xinu.h>

struct	ramblk ramtab[Nram];

/*------------------------------------------------------------------------
 *  ramInit  -  initialize the ramdisk device type
 *------------------------------------------------------------------------
 */
devcall	ramInit(
	 struct dentry *devptr	/* entry in device switch table	*/
	)
{
	struct ramblk *ramptr;	/* pointer to ramtab entry	*/

	ramptr = &ramtab[ devptr->dvminor ];

	/* Initialize values in the ramdisk block */
	ramptr->ifopen = 0;
	ramptr->maxsize = 0;
	ramptr->fstblk = NULL;
	ramptr->blksize = RMD_BLKSIZ;

	return OK;
}
