/* contoh1.c */
#include <stdio.h> 	/* standard I/O */
#include <unistd.h> 	/* getpid(), getppid() */
#include <sys/types.h> 	/* pid_t

main() {
pid_t mypid, myparentpid; /* deklarasi variabel penampung*/
mypid=getpid(); 		  /* ambil ID proses ini */
myparentpid=getppid();    /*ambil ID parent proses ini*/

/* tampilkan ID proses ini */
printf("PID Saya = %d\n",mypid); 

/* tampilkan ID parent */
printf("PID PARENT Saya = %d\n",myparentpid);
}