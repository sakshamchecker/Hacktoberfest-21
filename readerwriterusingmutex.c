#include<stdio.h>
#include<pthread.h>
#include<string.h>
void* reader (void*);
void* writer (void*);
int getItemforBuff();
void readItemformBuff(int buffer);
int buff;
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
int flag =0;
int main()
{
pthread_t rd_tid;
pthread_t wr_tid;
pthread_create(&wr_tid,NULL,writer,NULL);
pthread_create(&rd_tid,NULL,reader,NULL);
pthread_join(wr_tid,NULL);
pthread_join(rd_tid,NULL);
return 0;
}
void* reader(void *argp)
{
while(1)
{
pthread_mutex_lock(&mut);
if(flag == 1)
{
readItemformBuff (buff);
flag = 0;
}
pthread_mutex_unlock(&mut);
}
}
void* writer(void *argp)
{
while(1)
{
pthread_mutex_lock(&mut);
if(flag == 0)
{
buff = getItemforBuff();
flag = 1;
}
pthread_mutex_unlock(&mut);
}
}
int getItemforBuff()
{
int item;
printf("\n writer : \n Enter an item into buffer: ");
scanf("%d",&item);
return item;
}
void readItemformBuff(int buffer)
{
 printf("\n reader : read item from buffer = %d\n",buffer);
}
