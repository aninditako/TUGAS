/* contoh9.c */
#include <stdio.h>
#include <signal.h> /* kill() */
#include <sys/types.h> /* pid_t */

int main(){
int noID;
printf("Masukkan no ID yang ingin di terminate\n");
scanf("%d",&noID);
pid_t PID=noID;
kill(PID,SIGTERM);
printf("no ID %d sudah terminate\n",noID);

}

