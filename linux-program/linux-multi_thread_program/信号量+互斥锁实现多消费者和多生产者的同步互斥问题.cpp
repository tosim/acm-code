#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>

#define _SIZE_ 5

int ringbuf[_SIZE_];

pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;

sem_t blanks;
sem_t datas;

int i1 = 0;
int i2 = 0;
void* thread_pro(void* arg)
{
    while(1)
    {
        sleep(1);
        sem_wait(&blanks);//判断是否可以生产
        pthread_mutex_lock(&lock1);//因为有多个生产者，抢占生产锁
        //int data = rand()%10000;
        int data = i1;
        ringbuf[i1] = data;
        i1++;
        i1 %=_SIZE_;
        printf("pro sell a number: %d\n",data);

        pthread_mutex_unlock(&lock1);//生产完成，是否生产锁
        sem_post(&datas);//提示消费者消费
    }
}



void* thread_con(void* arg)
{
    while(1)
    {
        sleep(1);
        sem_wait(&datas);//判断是否可以消费
        pthread_mutex_lock(&lock2);//因为有多个消费者，抢占消费锁
        int data = ringbuf[i2];
        i2++;
        i2%=_SIZE_;
        printf("con get a number: %d\n",data);

        pthread_mutex_unlock(&lock2);
        sem_post(&blanks);//消费完成，提醒生产者生产

    }
}

int main()
{
    //index = 0;
    //num = 0;
    sem_init(&blanks,0,_SIZE_);
    sem_init(&datas,0,0);

    pthread_t pro1,pro2;
    pthread_t con1,con2;
    pthread_create(&pro1,NULL,thread_pro,NULL);
    pthread_create(&pro2,NULL,thread_pro,NULL);
    pthread_create(&con1,NULL,thread_con,NULL);
    pthread_create(&con2,NULL,thread_con,NULL);
    pthread_join(pro1,NULL);
    pthread_join(pro2,NULL);
    pthread_join(con1,NULL);
    pthread_join(con2,NULL);

    sem_destroy(&blanks);
    sem_destroy(&datas);

    pthread_mutex_destroy(&lock1);
    pthread_mutex_destroy(&lock2);
    //printf("hello\n");
    return 0;
}
