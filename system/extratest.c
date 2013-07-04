/* extratest.c - extratest.c */

#include <xinu.h>
#include <stdio.h>
#include <stdlib.h>

/*------------------------------------------------------------------------
 * extratest_write - write arbitrary data to blocks in arbitrary order
 * extratest_varify - read blocks back with random order and verify
 *------------------------------------------------------------------------
 */

char testbuf[RMD_BLKSIZ];
int i,j;
int *dirty;		/* record if block is wriiten or verified	*/
struct ramblk *ramptr;
uint32 maxblknum, blknum;

void extratest_write(void) {
	ramptr = &ramtab[0];
	maxblknum = ramptr -> maxsize;
	dirty = (int *)getmem(maxblknum);

	for(i = 0; i < maxblknum; i ++ ) {
		dirty[i] = FALSE;
	}

	i = 0;
	srand(1234);		/* initial seed			*/
	while ( i < maxblknum )
	{
		blknum = rand() % maxblknum;
		if(dirty[blknum] == TRUE) {
			continue;
		}
		else
			i ++;
		dirty[blknum] = TRUE;
		srand(blknum);	/* use block Number as seed	 */
		for(j = 0; j < RMD_BLKSIZ; j ++)
			testbuf[j] = (char) rand()%256;
		write(RAMDISK, testbuf, blknum);
	}
}

syscall extratest_verify(void) {
	for(i = 0; i < 100; i ++ ) {
		dirty[i] = FALSE;
	}
	i = 0;
	srand(4321);
	while ( i < maxblknum ) {
		blknum = rand() % maxblknum;
		if(dirty[blknum] == TRUE) {
			continue;
		}
		else
			i ++;
		dirty[blknum] = TRUE;
		read(RAMDISK, testbuf, blknum);
		srand(blknum);	/* use block Number as seed	 */
		for(j = 0; j < RMD_BLKSIZ; j ++) {
			if ( testbuf[j] != (char) rand()%256 ) {
				printf("Block %d is not consistent\r\n", blknum);
				return SYSERR;
			}
		}
	}
	return OK;
}
