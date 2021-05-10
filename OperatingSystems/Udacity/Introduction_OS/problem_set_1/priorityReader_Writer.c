#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int x = 0, timer = 0;
int r = 0; 

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t read_cv = PTHREAD_COND_INITIALIZER;
pthread_cond_t write_cv = PTHREAD_COND_INITIALIZER;

void *reader(void *);
void *writer(void *);

int main()
{
    pthread_t read_t, write_t;
    int *i;
    *i = 1;

    if (pthread_create(&read_t, NULL, reader, NULL) != 0){
        fprintf(stderr, "Unable to create Reader thread\n");
        exit(1);
    }

    if (pthread_create(&write_t, NULL, writer, i) != 0){
        fprintf(stderr, "Unable to create Writer thread\n");
        exit(1);
    }

    pthread_join(read_t, NULL);
    pthread_join(write_t, NULL);

    printf("Quitting from Parent thread\n");
    return 0;
}

// Reader thread
void *reader(void *params){
    int i;
    pthread_mutex_lock(&m);
        r++;
    pthread_mutex_unlock(&m);
    for (i = 0; i < 5; ++i)
        x = i;
    pthread_mutex_lock(&m);
        r--;
        printf("Value read %d\n",i);
        printf("No. of Readers waiting %d\n",r);
        if (r == 0)
            pthread_cond_signal(&write_cv);
    pthread_mutex_unlock(&m);

    return 0;
}

// Writer thread
void *writer(void *params){
    int i;
    pthread_mutex_lock(&m);
        while (r > 0)
            pthread_cond_wait(&write_cv, &m);
        
        for (i = 0; i < 5; ++i)
            x = *((int *)params);

        printf("Value written %d\n", *((int *)params));
        printf("No. of Readers waiting %d\n", r);
    pthread_mutex_unlock(&m);

    return 0;
}