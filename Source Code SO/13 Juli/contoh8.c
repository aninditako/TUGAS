/* contoh8.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int
main(){
pid_t pid;
int rv;
switch(pid=fork()) {
case -1:
perror("fork"); /* pesan kesalahan */
case 0:
printf(" CHILD: Ini proses child!\n");
printf(" CHILD: PID saya adalah %d\n", getpid());
printf(" CHILD: PID parent saya %d\n", getppid());
printf(" CHILD: Masukkan status exit saya: ");
scanf(" %d", &rv);
printf(" CHILD: Selesai...!\n");
exit(rv);
default:
printf("PARENT: Ini proses parent!\n");
printf("PARENT: PID saya adalah %d\n", getpid());
printf("PARENT: PID child saya %d\n", pid);
printf("PARENT: Sekarang menunggu child untuk selesai...\n");
wait(&rv); /* tunggu proses child selesai */
printf("PARENT:status exit child saya :
%d\n",WEXITSTATUS(rv)); /*status exit*/
printf("PARENT: Selesai...!\n");
}
}