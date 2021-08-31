/* contoh2.c */
#include <stdio.h> 		/* standard I/O */
#include <unistd.h> 		/* fork() */
#include <sys/types.h> 	/* pid_t */

int main() {

printf("Hello\n"); 		/* tampilkan Hello */
fork(); 				/* buat proses child */
printf("Bye-Bye\n"); /* dieksekusi oleh parent dan child */
}
