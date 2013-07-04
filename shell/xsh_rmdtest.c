/* xsh_rmdtest.c - xsh_rmdtest */

#include <xinu.h>
#include <stdio.h>
#include <string.h>

/*------------------------------------------------------------------------
 * xsh_rmdtest - test shell for ram disk device
 *------------------------------------------------------------------------
 */
shellcmd xsh_rmdtest(int nargs, char *args[])
{
	char *testbuf1, *testbuf2;
	int i,j;
	int retval;
	did32 devid1, devid2;
	
	/* open device 1 */
	devid1 = open(RAMDISK, "100", NULL);
	if( devid1 !=  SYSERR ) {
		kprintf("Device %s opened!\r\n", devtab[devid1].dvname);
	}
	/* open device 2 */
	devid2 = open(RAMDISK, "100", NULL);
	if( devid2 !=  SYSERR ) {
		kprintf("Device %s opened!\r\n", devtab[devid2].dvname);
	}

	/* write device 1*/
	if( devid1 == RAMDISK ) {
		testbuf1 = getmem(ramtab[0].blksize);
		for( i=0;i<ramtab[0].blksize;i++ )
			testbuf1[i]=(char)(i%256);
	}
	else {
		testbuf1 = getmem(ramstab[devtab[devid1].dvminor].blksize);
		for( i=0;i<ramstab[devtab[devid1].dvminor].blksize;i++ )
			testbuf1[i]=(char)(i%256);
	}
	
	if( devid1 == RAMDISK ) {
		for ( i=0;i<ramtab[0].maxsize;i++)
			retval = write(devid1, testbuf1,i);
			for (j=0; j< ramtab[0].blksize;j++) {
				if (testbuf1[j] != (char)(j%256)) {
					kprintf(" Device %s writes wrong!\r\n", devtab[devid1].dvname);
					return SYSERR;
				}
			}
				
	}
	else {
		for ( i=0;i<ramstab[devtab[devid1].dvminor].maxsize;i++) {
			retval = write(devid1, testbuf1,i);
			for (j=0; j< ramtab[0].blksize;j++) {
				if (testbuf1[j] != (char)(j%256)) {
					kprintf(" Device %s writes wrong!\r\n", devtab[devid1].dvname);
					return SYSERR;
				}
			}
		}
	}
	if (retval == OK) {
		kprintf(" Device %s write OK!\r\n", devtab[devid1].dvname);
	}

	/* read device 1 */
	if( devid1 == RAMDISK ) {
		for ( i=0;i<ramtab[0].maxsize;i++) {
			retval = read(devid1, testbuf1,i);
			for( j=0;j<ramtab[0].blksize;j++ ) {
				if (testbuf1[j] != (char)(j%256)) {
					kprintf(" Device %s reads wrong!\r\n", devtab[devid1].dvname);
					return SYSERR;
				}
			}
		}			
	}
	else {
		for ( i=0;i<ramstab[devtab[devid1].dvminor].maxsize;i++) {
			retval = read(devid1, testbuf1,i);
			for( j=0;j<ramtab[0].blksize;j++ ) {
				if (testbuf1[j] != (char)(j%256)) {
					kprintf(" Device %s reads wrong!\r\n", devtab[devid1].dvname);
					return SYSERR;
				}
			}
		}
	}
	if (retval == OK) {
		kprintf(" Device %s reads OK!\r\n", devtab[devid1].dvname);
	}
	
	/* write device 2*/
	if( devid2 == RAMDISK ) {
		testbuf2 = getmem(ramtab[0].blksize);
		for( i=0;i<ramtab[0].blksize;i++ )
			testbuf2[i]=(char)(i%256);
	}
	else {
		testbuf2 = getmem(ramstab[devtab[devid2].dvminor].blksize);
		for( i=0;i<ramstab[devtab[devid2].dvminor].blksize;i++ )
			testbuf2[i]=(char)(i%256);
	}
	
	if( devid2 == RAMDISK ) {
		for ( i=0;i<ramtab[0].maxsize;i++)
			retval = write(devid2, testbuf2,i);
	}
	else {
		for ( i=0;i<ramstab[devtab[devid2].dvminor].maxsize;i++) {
			retval = write(devid2, testbuf2,i);
		}
	}
	if (retval == OK) {
		kprintf(" Device %s write OK!\r\n", devtab[devid2].dvname);
	}
	
	/* read device 2 */
	if( devid1 == RAMDISK ) {
		for ( i=0;i<ramtab[0].maxsize;i++) {
			retval = read(devid2, testbuf2,i);
			for( j=0;j<ramtab[0].blksize;j++ ) {
				if (testbuf2[i] != (char)(i%256)) {
					kprintf(" Device %s reads wrong!\r\n", devtab[devid2].dvname);
					return SYSERR;
				}
			}
		}			
	}
	else {
		for ( i=0;i<ramstab[devtab[devid1].dvminor].maxsize;i++) {
			retval = read(devid2, testbuf2,i);
			for( j=0;j<ramstab[devtab[devid2].dvminor].blksize;j++ ) {
				if (testbuf2[i] != (char)(i%256)) {
					kprintf(" Device %s reads wrong!\r\n", devtab[devid2].dvname);
					return SYSERR;
				}
			}
		}
	}	

	if (retval == OK) {
		kprintf(" Device %s reads OK!\r\n", devtab[devid2].dvname);
	}

	/* close device 1 */
	retval = close(devid1);
	if( retval == OK ) {
		kprintf(" Device %s close OK!\r\n", devtab[devid1].dvname);
	}
	/* close device 2 */
	retval = close(devid2);
	if( retval == OK ) {
		kprintf(" Device %s close OK!\r\n", devtab[devid2].dvname);
	}
	return OK;
}
