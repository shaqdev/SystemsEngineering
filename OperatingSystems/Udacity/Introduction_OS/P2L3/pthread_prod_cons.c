#include <pthread.h>
#include <stdio.h>
#include <stdlib.h> //exit()

#define BUFSIZE 3

int buffer[BUFSIZE];
int add = 0;
int rem = 0;
int num = 0;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t c_cons = PTHREAD_COND_INITIALIZER;
pthread_cond_t c_prod = PTHREAD_COND_INITIALIZER;

void *producer(void *);
void *consumer(void *);

int main()
{
   pthread_t prod_t, cons_t;

   if (pthread_create(&prod_t, NULL, producer, NULL) != 0){
       fprintf(stderr, "Unable to crate producer thread\n");
       exit(1);
   } 

   if (pthread_create(&cons_t, NULL, consumer, NULL) != 0){
       fprintf(stderr, "Unable to create consumer thread\n");
       exit(1);
   }

   pthread_join(prod_t, NULL);
   pthread_join(cons_t, NULL);
   printf("Parent Quitting\n");

 return 0;   
}

void *producer(void *params){
    for (int i = 1; i < 20; ++i){
        pthread_mutex_lock(&m);
            if (num > BUFSIZE)
                exit(1);
            
            while (num == BUFSIZE)
            {
                pthread_cond_wait(&c_prod, &m);
            }

            buffer[add] = i;
            add = (add + 1) % BUFSIZE;
            num++;
        pthread_mutex_unlock(&m);

        pthread_cond_signal(&c_cons);
        printf("Producer inserted %d\n", i); 
        fflush(stdout);        
    }
    return 0;
}

void *consumer(void *params) {
    int i;
    while(1) {
        pthread_mutex_lock(&m);
            if (num < 0)
                exit(1);
            
            while (num == 0) {
                pthread_cond_wait(&c_cons, &m);
            }

            i = buffer[rem];
            rem = (rem + 1) % BUFSIZE;
            num--;
        pthread_mutex_unlock(&m);

        pthread_cond_signal(&c_prod);
        printf("Consumer removed %d\n", i);
        fflush(stdout);
    }
    return 0;
}