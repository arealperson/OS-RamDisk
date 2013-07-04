/* ramdisk.h */

#define	RMD_BLKSIZ		512	/* size of blocks		*/
#define Nram			1	/* number of master ram disks	*/
#define Nrams			5	/* number of slave ram disks	*/

struct ramblk {
	uint32	ifopen;		/* count number of opened ramdisk	*/
	uint32	maxsize;	/* number of total blocks in ramdisk	*/
	char	*fstblk;	/* pointer to first block in ramdisk	*/
	uint32	blksize;
};

struct ramsblk {
	uint32	ifopen;		/* count number of opened ramdisk	*/
	uint32	maxsize;	/* number of total blocks in ramdisk	*/
	char	*fstblk;	/* pointer to first block in ramdisk	*/
	uint32	blksize;
};

extern	struct	ramblk ramtab[];
extern	struct	ramsblk ramstab[];
