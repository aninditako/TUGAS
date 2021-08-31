/* contoh11.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
void sigquit (); /*prototype fungsi penanganan signal */
int
main (){
pid_t pid;
pid=fork();
switch (pid) {
case -1: perror("fork"); /* proses fork() gagal */
exit(EXIT_FAILURE); /* exit jika gagal */
case 0: /* ini proses child */
signal (SIGQUIT, sigquit); /* install signal handler baru untuk
child */
for (;;); /* loop terus */
default: /* ini proses parent */
printf ("\nPARENT: Kirim signal SIGQUIT ke CHILD\n\n");
kill (pid, SIGQUIT); /* kirim signal */
sleep (3); /* tunda 3 detik */
exit(EXIT_SUCCESS); /* akhiri proses parent */
}
}
/* ini definisi fungsi penanganan signal */
void
sigquit (){
printf ("CHILD: Terima SIGQUIT dari parent.\n");
exit (0);
}
