/* contoh5.c */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
printf("Hello\n");
fork();
printf("Hiii\n");
fork();
printf("Hooo\n");
}