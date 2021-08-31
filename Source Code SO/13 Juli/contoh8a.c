/* contoh6.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

/* prototype fungsi */
int doparent();
int dochild1();
int dochild2();

int main(){
  int rv,sv,i;
  pid_t pid1,pid2;                        /* hilangkan child */

  pid1=fork(); /* buat proses child1 */
  
  if(pid1==-1) {
    perror("Fork gagal");
    exit(EXIT_FAILURE);
  }

  if(pid1==0) {
     printf("proses child 1 menunggu\n "); 
     wait(&rv); 
     printf("proses child 1 mulai\n ");   
     getchar();
     dochild1();
     printf("proses child 1 selesai\n ");
      
     pid2=fork(); /* buat proses child2 */
      

     if(pid2==-1){
        perror("Fork gagal");
        exit(1);
     }

     if(pid2==0) {
        printf("proses child 2 menunggu\n "); 
        wait(&sv); 
        printf("-----------------------\n");
        printf("proses child 2 mulai\n");  
        getchar();
        dochild2();
        printf("proses child 2 selesai\n ");    
     }
     else {
       getchar(); 
       printf("Proses parent menampilkan listing program mulai\n");    
       getchar();
       doparent();
          
       printf("Proses parent menampilkan listing program selesai\n");
     }
  }
}                                         /* tambah kurung kurawal } */

int doparent(){
     FILE *pf;                            /* pointer file */         
     char fname[15], buff;
     //fname = "exam1.c";
     printf("Input nama file yang dibaca exam1.c ");
     /* ambil nama file yang isinya ingin dibaca*/
     pf=fopen("exam1.c","r"); /* buka file untuk dibaca */
     if(pf==NULL){
        perror("PARENT: Error : \n");
        exit(EXIT_FAILURE); /* exit jika buka file gagal */
     }
     buff=getc(pf); /* baca karakter pertama */
     printf("PARENT: ISI FILE yang dibaca\n");
     while(buff!=EOF){
        putc(buff,stdout); /* cetak karakter */
        buff=getc(pf); /* baca karakter berikutnya sampai ketemu EOF */
     }
     fclose(pf); /* tutup file */
}

int dochild1(){
  int i;
  FILE *pf=fopen("data1.txt","w");                               /* ganti data2 jadi data1.txt */
  if(pf==NULL){
     printf("CHILD1: Error\n");
     exit(EXIT_FAILURE);
  }
  for(i=1; i<=5; ++i)
         fprintf(pf,"%d.Ini dari child1\n",i);
  fclose(pf);
}

int dochild2(){
  int i;
  FILE *pf=fopen("data2.txt","w");                               /* ganti data3 jadi data2.txt */
  if(pf==NULL){
    printf("CHILD2: Error \n");
    exit(1);
  }
  for(i=5; i>=1; --i)
    fprintf(pf,"%d.Ini dari child2\n",i);
  fclose(pf);
}