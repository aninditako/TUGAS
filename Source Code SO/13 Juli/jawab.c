#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
 pid_t ap1;
 pid_t ap2;
 ap1=fork();
 if (ap1==-1)
    { printf("Fork gagal");
      exit (EXIT_FAILURE);
    }
   else if (ap1==0)
              {
               printf("chiled 1 \n");
              }
    else {
        printf("parent Aplikasi 1\n");
         ap1=fork();
         if (ap2==-1)
            { printf("Fork gagal");
                exit(EXIT_FAILURE);
             }
         else
         if (ap1==0)
            {
             printf("chiled 1 \n");
             ap2=fork();
             if (ap2==-1)
                { printf("Fork gagal");
                  exit (EXIT_FAILURE);
                }
                else
               if (ap2==0)
                
                 {printf("Parent\n");}
            }
           }


getchar();
return 0;
}
  

