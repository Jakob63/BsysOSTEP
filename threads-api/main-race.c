#include <stdio.h>
#include <pthread.h>
#include "common_threads.h"
pthread_mutex_t lock;
int balance = 0;

void pTThread_mutex_lock(pthread_mutex_t *lock) {
    int rc = pthread_mutex_lock(lock);
    assert(rc == 0);
}

void pTThread_mutex_init(pthread_mutex_t *lock) {
    int rc = pthread_mutex_init(lock, NULL);
    assert(rc == 0);
}

void pTThread_mutex_unlock(pthread_mutex_t *lock) {
    int rc = pthread_mutex_unlock(lock);
    assert(rc == 0);
}

void pTThread_mutex_destroy(pthread_mutex_t *lock) {
    int rc = pthread_mutex_destroy(lock);
    assert(rc == 0);
}

void* worker(void* arg) {
    pTThread_mutex_lock(&lock);
    balance++; // unprotected access 
    pTThread_mutex_unlock(&lock);
    return NULL;
}

int main(int argc, char *argv[]) {
    pTThread_mutex_init(&lock);
    pthread_t p;
    Pthread_create(&p, NULL, worker, NULL);
    pTThread_mutex_lock(&lock);
    balance++; // unprotected access
    pTThread_mutex_unlock(&lock);
    Pthread_join(p, NULL);
    pTThread_mutex_destroy(&lock);
    return 0;
}