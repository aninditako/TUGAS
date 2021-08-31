/* contoh7.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> /* wait() */
int main(){
pid_t pid;
int rv;
pid=fork();
switch(pid) {
case -1:
perror("fork"); /* pesan kesalahan */
exit(EXIT_FAILURE); /* exit jika gagal */
case 0:
printf(" CHILD: Ini proses child!\n");
sleep(5); /* tunggu 5 second */
printf(" CHILD: Selesai...!\n");
exit(EXIT_SUCCESS);
default:
printf("PARENT: Ini proses parent!\n");
printf("PARENT: Sekarang menunggu child selesai...\n");
wait(&rv); /* tunggu sampai child selesai */
printf("PARENT: Selesai...!\n");
}
}
