/*********************/
/*JAWABAN SOAL       */
/*********************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
 pid_t pid;
 pid_t ap1;
 pid_t ap2;
 ap1=fork();
 if (ap1==-1)
    { printf("Fork gagal");exit (EXIT_FAILURE);}
 else if (ap1==0)
         {printf("ANAK 1 -->%d\n",getpid());}
 else { printf("INDUK -->%d\n",getppid());
        ap1=fork();
        if (ap1==-1)
            {printf("Fork gagal"); exit(EXIT_FAILURE);}
        else if (ap1 ==0)
                {printf("ANAK 2 -->%d\n",getpid());
                 ap2=fork();
                 if (ap2==-1)
                    { printf("Fork gagal");exit (EXIT_FAILURE);}
                 else  if (ap2==0)
                      {printf("ANAK 3 -->%d\n",getpid());}
                 else {printf("INDUK 3-->%d\n",getpid());}
                }                       
        else  {printf("INDUK 2 -->%d\n",getpid());}  
       }
getchar();
return 0;
}





