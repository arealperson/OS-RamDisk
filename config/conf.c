/* conf.c (GENERATED FILE; DO NOT EDIT) */

#include <xinu.h>


extern	devcall	ioerr(void);
extern	devcall	ionull(void);

/* Device independent I/O switch */

struct	dentry	devtab[NDEVS] =
{
/**
 * Format of entries is:
 * dev-number, minor-number, dev-name,
 * init, open, close,
 * read, write, seek,
 * getc, putc, control,
 * dev-csr-address, intr-handler, irq
 */

/* CONSOLE is tty */
	{ 0, 0, "CONSOLE",
	  (void *)ttyInit, (void *)ionull, (void *)ionull,
	  (void *)ttyRead, (void *)ttyWrite, (void *)ioerr,
	  (void *)ttyGetc, (void *)ttyPutc, (void *)ttyControl,
	  (void *)0xb8020000, (void *)ttyInterrupt, 11 },

/* RAMDISK is ram */
	{ 1, 0, "RAMDISK",
	  (void *)ramInit, (void *)ramOpen, (void *)ramClose,
	  (void *)ramRead, (void *)ramWrite, (void *)ionull,
	  (void *)ionull, (void *)ionull, (void *)ionull,
	  (void *)0x0, (void *)ioerr, 0 },

/* RAMDISK0 is rams */
	{ 2, 0, "RAMDISK0",
	  (void *)ramsInit, (void *)ioerr, (void *)ramsClose,
	  (void *)ramsRead, (void *)ramsWrite, (void *)ionull,
	  (void *)ionull, (void *)ionull, (void *)ionull,
	  (void *)0x0, (void *)ioerr, 0 },

/* RAMDISK1 is rams */
	{ 3, 1, "RAMDISK1",
	  (void *)ramsInit, (void *)ioerr, (void *)ramsClose,
	  (void *)ramsRead, (void *)ramsWrite, (void *)ionull,
	  (void *)ionull, (void *)ionull, (void *)ionull,
	  (void *)0x0, (void *)ioerr, 0 },

/* RAMDISK2 is rams */
	{ 4, 2, "RAMDISK2",
	  (void *)ramsInit, (void *)ioerr, (void *)ramsClose,
	  (void *)ramsRead, (void *)ramsWrite, (void *)ionull,
	  (void *)ionull, (void *)ionull, (void *)ionull,
	  (void *)0x0, (void *)ioerr, 0 },

/* RAMDISK3 is rams */
	{ 5, 3, "RAMDISK3",
	  (void *)ramsInit, (void *)ioerr, (void *)ramsClose,
	  (void *)ramsRead, (void *)ramsWrite, (void *)ionull,
	  (void *)ionull, (void *)ionull, (void *)ionull,
	  (void *)0x0, (void *)ioerr, 0 },

/* RAMDISK4 is rams */
	{ 6, 4, "RAMDISK4",
	  (void *)ramsInit, (void *)ioerr, (void *)ramsClose,
	  (void *)ramsRead, (void *)ramsWrite, (void *)ionull,
	  (void *)ionull, (void *)ionull, (void *)ionull,
	  (void *)0x0, (void *)ioerr, 0 },

/* NOTADEV is null */
	{ 7, 0, "NOTADEV",
	  (void *)ionull, (void *)ionull, (void *)ionull,
	  (void *)ionull, (void *)ionull, (void *)ioerr,
	  (void *)ionull, (void *)ionull, (void *)ioerr,
	  (void *)0x0, (void *)ioerr, 0 }
};
