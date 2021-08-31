/* contoh7.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> /* wait() */

void dochild1();

int main(){
pid_t pid;
int rv;
pid=fork();
switch(pid) {
case -1:
   perror("fork"); /* pesan kesalahan */
   exit(EXIT_FAILURE); /* exit jika gagal */
case 0:
   
   dochild1();
   printf("Sebagai CHILD dari Parent awal\n");
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

void dochild1(){
  pid_t pid1;
  int rd;
  pid1=fork();
  
  if(pid1==-1) {
     perror("Fork gagal");
     exit(EXIT_FAILURE);
  }
  if(pid1==0) {
    printf("Ini CHILD 2 dari CHILD 1\n");
    printf("Sedang proses....!\n");
    sleep(5);
    printf("Selesai....CHILD 2\n");
  }
  else {
    printf("Ini PARENT DARI CHILD 2\n");
    printf("Sekarang Menunggu CHILD 2 SELESAI\n");
    wait(&rd);
    printf("Parent dari CHILD 2 SELESAI\n");
    printf("----------------------------\n");
  } 
}
