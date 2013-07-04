/* ramRead.c - ramRead */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  ramRead  -  reads one RMD_BLKSIZ-byte block from disk
 *------------------------------------------------------------------------
 */
devcall	ramRead(
	struct dentry *devptr,	/* entry in device switch table	*/
	void *buff,
	uint32 blknum
	)
{
	struct ramblk *ramptr;	/* pointer to ramtab entry	*/
	char *memaddr;		/* address of data in memory	*/
	int i;

	ramptr = &ramtab[ devptr->dvminor ];
	memaddr = (char *)buff;

	if(ramptr->ifopen != 1) { /* check if ramdisk is open	*/
		return SYSERR;
	}
	
	for (i = blknum * ramptr->blksize; i < (blknum+1) * ramptr->blksize; i ++) {
		memaddr[i-blknum * ramptr->blksize] = ramptr->fstblk[i];
	}
	
	return OK;
}
