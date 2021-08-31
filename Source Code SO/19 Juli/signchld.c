#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
sig_atomic_t child_exit_status;
void clean_up_child_process(int signal_number)
{
  /* clean up the child proses */
 int status;
 wait(&status);
 /*store its exit status in a global variable*/
 child_exit_status =status;
}
int main()
 {
  /*Handle SIGCHLD by calling clean_up_Child_proses*/
  struct sigaction sigchld_action;
  memset(&sigchld_action,0,sizeof(sigchld_action));
  sigchld_action.sa_handler=&clean_up_child_process;
  sigaction(SIGCHLD, &sigchld_action, NULL);
  /* Now do thing, including forking a child proses */
return 0;
}

