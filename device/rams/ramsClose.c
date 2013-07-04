/* ramClose.c - ramClose */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  ramClose  -  terminates use of the RAMDISK and deallocates the memory
 *------------------------------------------------------------------------
 */
devcall	ramsClose(
	 struct dentry *devptr	/* entry in device switch table	*/
	)
{
	struct ramblk *ramptr;	/* pointer to ramtab entry	*/

	ramptr = &ramtab[ devptr->dvminor ];
	

	ramptr->maxsize = 0;
	ramptr->fstblk = NULL;
	freemem(ramptr->fstblk, ramptr->maxsize);
	return OK;
}
