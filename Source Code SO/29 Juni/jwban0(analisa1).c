/**********************/
/*TUGAS Sistem Operasi*/
/* ANALISA 1          */
/**********************/
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
           {printf("ANAK 1 -->%d\n",getpid());
           }
else { 
         printf("INDUK 1 -->%d\n",getpid());  
     }
getchar();
return 0;
}

