/* ramClose.c - ramClose */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  ramClose  -  terminates use of the RAMDISK and deallocates the memory
 *------------------------------------------------------------------------
 */
devcall	ramClose(
	 struct dentry *devptr	/* entry in device switch table	*/
	)
{
	struct ramblk *ramptr;	/* pointer to ramtab entry	*/

	ramptr = &ramtab[ devptr->dvminor ];
	
	if(ramptr->ifopen != 1) { /* check if ramdisk is open	*/
		return SYSERR;
	}
	else {
		ramptr->ifopen = 0;
	}

	freemem(ramptr->fstblk, ramptr->maxsize);
	ramptr->maxsize = 0;
	ramptr->fstblk = NULL;
	return OK;
}
