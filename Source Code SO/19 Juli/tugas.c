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
         { ap1=fork();
            printf("ANAK 1 -->%d\n",getpid());        
            if (ap1==-1)
                  { printf("Fork gagal");exit(EXIT_FAILURE);}
            else if (ap1==0)
                  { printf("ANAK 2 -->%d\n",getpid());}
            else { ap1=fork();
                     printf("INDUK 2 -->%d\n",getpid());
                   if (ap1==-1)
                      { printf("Fork Gagal");exit(EXIT_FAILURE);}
                   else if (ap1==0)
                           { printf("ANAK 4 -->%d\n",getpid());
                           }
                   else { ap1=fork();
                          printf("INDUK 4 -->%d\n",getpid());
                          if(ap1==-1)
                             { printf("Fork gagal");exit(EXIT_FAILURE);}
                           else if (ap1==0)
                                   {printf("ANAK 5 -->%d\n",getpid());}
                           else {printf("INDUK 5 --> %d\n",getpid());} 
                        }
                  }
          }
 else { ap1=fork();
        printf("INDUK 1-->%d\n",getppid());
        if (ap1==-1)
            {printf("Fork gagal"); exit(EXIT_FAILURE);}
        else if (ap1 ==0)
                {printf("ANAK 3 -->%d\n",getpid());
                }                       
        else  {printf("INDUK 3 -->%d\n",getpid());}  
       }
getchar();
return 0;
}






