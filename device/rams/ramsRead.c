/* ramsRead.c - ramsRead */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  ramsRead  -  reads one RMD_BLKSIZ-byte block from disk
 *------------------------------------------------------------------------
 */
devcall	ramsRead(
	struct dentry *devptr,	/* entry in device switch table	*/
	void *buff,
	uint32 blknum
	)
{
	struct ramsblk *ramsptr;	/* pointer to ramstab entry	*/
	char *memaddr;		/* address of data in memory	*/
	int i;

	ramsptr = &ramstab[ devptr->dvminor ];
	memaddr = (char *)buff;

	if(ramsptr->ifopen != 1) { /* check if ramsdisk is open	*/
		return SYSERR;
	}
	
	for (i = blknum * ramsptr->blksize; i < (blknum+1) * ramsptr->blksize; i ++) {
		memaddr[i-blknum * ramsptr->blksize] = ramsptr->fstblk[i];
	}
	
	return OK;
}
