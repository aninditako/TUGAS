/* contoh8.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  pid_t pid,pid1,pid2;
  int rv;
  pid=fork();
  if (pid == -1) {
        perror("fork"); /* pesan kesalahan */
        exit(1);
   }
   else if (pid == 0) {
              	printf(" CHILD: Ini proses child!\n");
		printf(" CHILD: PID saya adalah %d\n", getpid());
		printf(" CHILD: PID parent saya %d\n", getppid());
   }
   else {
		printf("PARENT: Ini proses parent!\n");
		printf("PARENT: PID saya adalah %d\n", getpid());
		printf("PARENT: PID child saya %d\n", pid);
                pid1 = fork();
                if (pid1 == -1) 
                  printf("Error");
                else if (pid1 == 0) {
                   printf("INI CHILD KEDUA : %d\n", getpid());
                   pid2 = fork();
                   if (pid2 == -1) 
                      printf("error");
                   else if (pid2 == 0) {
                           printf("ini anak yang ke dua");
                 }   
              }
          }
  getchar();
}
