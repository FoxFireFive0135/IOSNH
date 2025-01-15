#ifndef PTHREAD_H
#define PTHREAD_H

#include <stdbool.h>
#include <stddef.h>

#define PTHREAD_MUTEX_INITIALIZER  { .locked = false }

typedef struct {
    bool locked;
} pthread_mutex_t;

typedef struct {
    int dummy;  // Placeholder for thread attributes
} pthread_attr_t;

typedef struct {
    void* (*start_routine)(void*);
    void* arg;
    // Add more fields as needed for full thread control (this is a minimal version)
} pthread_t;

int pthread_create(pthread_t* thread, const pthread_attr_t* attr, void* (*start_routine)(void*), void* arg) {
    (void)attr;  // Ignoring attributes for simplicity

    // Here, we're just simulating a thread by directly calling the start_routine
    // In a real implementation, it would create an OS thread
    start_routine(arg);
    return 0;
}

int pthread_mutex_lock(pthread_mutex_t* mutex) {
    while (__atomic_test_and_set(&mutex->locked, __ATOMIC_ACQUIRE)) {
        // Spinlock: wait for the mutex to be unlocked
    }
    return 0;
}

int pthread_mutex_unlock(pthread_mutex_t* mutex) {
    __atomic_clear(&mutex->locked, __ATOMIC_RELEASE);  // Release the lock
    return 0;
}

int pthread_mutex_init(pthread_mutex_t* mutex, const pthread_attr_t* attr) {
    (void)attr;  // Ignoring attributes for simplicity
    mutex->locked = false;
    return 0;
}

int pthread_mutex_destroy(pthread_mutex_t* mutex) {
    (void)mutex;
    return 0;
}

#endif // PTHREAD_H
