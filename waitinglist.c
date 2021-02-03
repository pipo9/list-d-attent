 #include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int  peopleinside=0;
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  canadd=PTHREAD_COND_INITIALIZER;
pthread_cond_t  canremove=PTHREAD_COND_INITIALIZER;


void* addperson(){
 pthread_mutex_lock(&lock);
 pthread_cond_wait(&canadd,NULL);
 peopleinside++;
 printf("this is the thread number %d. nmbr of people inside is %d \n",pthread_>
 pthread_mutex_unlock(&lock);
}

void* removeperson(){

 pthread_mutex_lock(&lock);
 pthread_cond_wait(&canremove,NULL);
 peopleinside--;
 printf("this is the thread number %d. nmbr of people inside is %d \n",pthread_>
 pthread_mutex_unlock(&lock);

}

int main(){
char order;
int maxnbr;
pthread_t addth,removeth;
  printf("            ********** Program start now **********\n");
  printf("max nbr of people inside\n");
  scanf("%d",&maxnbr);
  pthread_create(&addth,NULL,&addperson,NULL);

  pthread_create(&removeth,NULL,&removeperson,NULL);
  while(1){
  printf("type order:'+' to add person, '-' to remove  person , 'q' to quit \n">
  scanf("%c",&order);
  if(order=='+')
    if(peopleinside<maxnbr) pthread_cond_signal(&canadd);
  if(order=='-')
   if(peopleinside>0) pthread_cond_signal(&canremove);
  if(order=='q' || order=='Q') break;
}
 pthread_mutex_destroy(&lock);
 return 0;
}
