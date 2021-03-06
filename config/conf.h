/* conf.h (GENERATED FILE; DO NOT EDIT) */

/* Device switch table declarations */

/* Device table entry */
struct	dentry	{
	int32   dvnum;
	int32   dvminor;
	char    *dvname;
	devcall (*dvinit) (struct dentry *);
	devcall (*dvopen) (struct dentry *, char *, char *);
	devcall (*dvclose)(struct dentry *);
	devcall (*dvread) (struct dentry *, void *, uint32);
	devcall (*dvwrite)(struct dentry *, void *, uint32);
	devcall (*dvseek) (struct dentry *, int32);
	devcall (*dvgetc) (struct dentry *);
	devcall (*dvputc) (struct dentry *, char);
	devcall (*dvcntl) (struct dentry *, int32, int32, int32);
	void    *dvcsr;
	void    (*dvintr)(void);
	byte    dvirq;
};

extern	/* one entry per device */

/* Device name definitions */

#define CONSOLE     0       /* type tty      */
#define RAMDISK     1       /* type ram      */
#define RAMDISK0    2       /* type rams     */
#define RAMDISK1    3       /* type rams     */
#define RAMDISK2    4       /* type rams     */
#define RAMDISK3    5       /* type rams     */
#define RAMDISK4    6       /* type rams     */
#define NOTADEV     7       /* type null     */

/* Control block sizes */

#define	Nnull	1
#define	Ntty	1
#define	Nram	1
#define	Nrams	5

#define DEVMAXNAME 24
#define NDEVS 8


/* Configuration and Size Constants */

#define	NPROC	     100	/* number of user processes		*/
#define	NSEM	     100	/* number of semaphores			*/
#define	IRQ_TIMER    IRQ_HW5	/* timer IRQ is wired to hardware 5	*/
#define	IRQ_ATH_MISC IRQ_HW4	/* Misc. IRQ is wired to hardware 4	*/
#define MAXADDR      0x02000000	/* 32 MB of RAM				*/
#define CLKFREQ      200000000	/* 200 MHz clock			*/
#define FLASH_BASE   0xBD000000	/* Flash ROM device			*/
