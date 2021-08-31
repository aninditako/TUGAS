/* contoh3.c */
#include <stdio.h> /* standard I/O */
#include <stdlib.h> /* standard library */
#include <unistd.h> /*fork(), getpid(), getppid() */
#include <sys/types.h> /* pid_t */
int main(){
pid_t pid;
pid=fork(); /* buat proses child */
if (pid==-1){
print(“Fork gagal\n”);
exit(EXIT_FAILURE); /* exit jika gagal */
if (pid==0){
/* proses child */
print(“CHILD: Ini proses Child\n”);
print(“CHILD: PID saya = %d\n”,getpid());
print(“CHILD: PID parent saya = %d\n”,getppid());
} else {
/* proses parent */
print(“PARENT: Ini proses Parent\n”);
print(“PARENT: PID saya = %d\n”,getpid());
print(“PARENT: PID parent saya = %d\n”,getppid());
print(“PARENT: PID child saya = %d\n”,pid);
 }
}
