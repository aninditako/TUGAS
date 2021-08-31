/* contoh6.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

/* prototype fungsi */
void doparent();
void dochild1();
void dochild2();

int main(){
int rv=0,i;
pid_t chilpid1,childpid2;
pid1=fork(); /* buat proses child1 */
if(pid1==-1) {
perror("Fork gagal");
exit(EXIT_FAILURE);
}

if(pid1==0) {
dochild1();
pid2=fork(); /* buat proses child2 */
if(pid2==-1){
perror("Fork gagal");
exit(1);
}
if(pid2==0)
dochild2();
else
doparent();
}

void doparent(){
FILE pf; /* pointer file */
char fname[15], buff;
printf("Input nama file yang dibaca :");
scanf("%s",fname); 
/* ambil nama file yang isinya ingin dibaca*/
pf=fopen(fname,"r"); /* buka file untuk dibaca */
if(pf==NULL){
perror("PARENT: Error : \n");
exit(EXIT_FAILURE); /* exit jika buka file gagal */
}
buff=getc(pf); /* baca karakter perta
ma */
printf("PARENT: ISI FILE yang dibaca\n");
while(buff!=EOF){
putc(buff,stdout); /* cetak karakter */
buff=getc(pf); /* baca karakter berikutnya sampai ketemu EOF */
}
fclose(pf); /* tutup file */
}

void dochild1(){
int i;
FILE *pf=fopen("data2.txt","w");
if(pf==NULL){
printf("CHILD1: Error\n");
exit(EXIT_FAILURE);
}
for(i=1; i<=5; ++i)
fprintf(pf,"%d.Ini dari child1\n",i);
fclose(pf);
}

void dochild2(){
int i;
FILE *pf=fopen("data3.txt","w");
if(pf==NULL){
printf("CHILD2: Error \n");
exit(1);
}
for(i=5; i>=1; --i)
fprintf(pf,"%d.Ini dari child2\n",i);
fclose(pf);
}
