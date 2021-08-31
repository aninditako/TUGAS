/* contoh12.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
/*prototype fungsi penanganan signal */
void sighup();
void sigint();
void sigquit();
void sigterm();
int
main(){
pid_t pid;
pid=fork();
if (pid==-1) {
perror("fork");
exit(EXIT_FAILURE);
}
if (pid == 0) {
/* install signal habdler*/
signal(SIGHUP,sighup);
signal(SIGINT,sigint);
signal(SIGQUIT, sigquit);
signal(SIGTERM, sigterm);
for(;;); /* loop terus menerus */
} else {
/* kirim signal ke child */
printf("\nPARENT : kirim signal SIGHUP\n\n");
kill(pid,SIGHUP);
sleep(3); /* tunda 3 detik */
printf("\nPARENT : kirim signal SIGINT\n\n");
kill(pid,SIGINT);
sleep(3);
printf("\nPARENT : kirim signal SIGQUIT\n\n");
kill(pid,SIGQUIT);
sleep(3);
printf("\nPARENT : kirim signal SIGTERM\n\n");
kill(pid,SIGTERM);
sleep(3);
}
}
void
sighup() {
signal(SIGHUP,sighup); /* reset signal */
printf("CHILD : Terima signal SIGHUP\n");
}
void
sigint() {
signal(SIGINT,sigint); /* reset signal */
printf("CHILD : Terima signal SIGINT\n");
}
void
sigquit(){
printf("CHILD : Terima signal SIGQUIT\n");
}
void
sigterm(){
printf("CHILD : Terima signal SIGTERM\n");
exit(EXIT_FAILURE); /* hentika proses child */
}
