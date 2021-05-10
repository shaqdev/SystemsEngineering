THREADS CASE STUDY : PTHREADS
-----------------------------

V1 : Lesson Preview
    -> pthread is multi-threaded system in unix environment. pthread library is system call library in C library available in Unix systems that provide interface via system call APIs.
    -> POSIX - Portable OS Interface, is a standard system call interface most of the UNIX systems follows. This will allow inter operable between OS.
    -> posix threads is the thread library supported by UNIX systems to create and manage threads and their synchronization and concurrancy.

V2 : pthread creation
    -> pthread supports pthread_t(thread abstraction in posix) & pthread_create & pthread_join (mechanism to create thread). These are analogues to birrels proposed thread abstraction and fork/join mechanisms.
    -> Signature of pthread_create & pthread_join

        pthread_t aThread;
        
        int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void * (*start_routine)(void *), void * arg);

        int pthread_join(pthread_t thread, void **status);

    -> pthread_attr_t data type is used to specify attributes like stack size, scheduling policy, priority ... for newly created thread.
    -> NULL to pthread_attr_t * will set all attributes to their default values.
    -> pthread_attr_init and pthread_attr_destroy functions are used to initialize and destroy pthread_attr_t in the memory.
    -> pthread_attr_{set/get}{attribute} function is used to set or get attributes. 
    -> Additional features pthread has over birrels threads are DETACHING PTHREADS.
    -> In case of Joinable threads, a parent thread should exit only when child thread exits or else it will lead to zombie thread. In case of Detachable threads, a child thread is detached from parent thread and executes and exits independently from parent thread.
    -> We can set a pthread as detachable using seperate funciton or setting pthread_attr_setdetachablestate().

V3 : Compiling Threads
    -> #include <pthread.h>
    -> gcc main.c -o main_out -lpthread (or -pthread)
    -> We have to link libraries that are not inside C standard Library.

V4-9 : Programs and quiz on thread creation, how global values can lead DATA RACE problem and using private
       individual values can avoid such corruption of data.

v10 : pthread Mutexes
    -> Mutex offers mechanism to solve mutual exclusion problems like DATA RACE among concurrent threads.
    -> It controls the modifications to shared variables by allowing only one thread to modify at a time.
    -> The mechanism involves, mutex abstraction and lock/unlock operations.
    -> pthread mutex mechanism is shown below,

        pthread_mutex_t aMutex;

        int pthread_mutex_lock(pthread_mutex_t *mutex);
        // Critical Section
        int pthread_mutex_unlock(pthread_mutex_t *mutex);

    -> pthread_mutex supported operations,

        int pthread_mutex_init(pthread_mutex_t *mutex, pthread_mutexattr_t *attr); // attr specifies the pthread mutex behaviour. eg: mutex is private to current process or shared between processes.

        int pthread_mutex_trylock(pthread_mutex_t *mutex); // It wont block calling thread if critical section is already locked. It will be used when we want calling thread to perform some action rather than waiting for acquiring lock.

        int pthread_mutex_destroy(pthread_mutex_t *mutex);

    -> Mutex Safety Tips:
        1. Shared data/Critical section should always be accessed through single mutex.
        2. Mutex must be declared as global variable.
        3. globally order locks. If we specify specific order to lock mutliple mutex, then ensure all threads will lock in the same order.
        4. Always unlock correct mutex.

V11 : pthread Conditional Variable
    -> Similar to Conditional Varialbles in Birrels paper, pthread CVs will block threads until they notify when a specific condition has met.
    -> pthread's CV mechanism involves CV abstraction and wait, signal & broadcast operations.
    -> The pthread's CV mechanism is shown below, 

        pthread_cond_t aCond;

        int pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex); // CV should be associated with mutex.

        int pthread_cond_signal(pthread_cond_t *cond);

        int pthread_cond_broadcast(pthread_cond_t *cond);

    -> pthread operations

        int pthread_cond_init(pthread_cond_t *cond, pthread_condattr_t *attr);

        int pthread_cond_destroy(pthread_cond_t *cond);

    -> Safety tips for CV
        1. Always notify correct CV, when ever a predicate changes.
        2. if doubtful to use signal/broadcast, better use broadcast but has performace loss.
        3. Sometimes using signal/broadcast out of lock/unlock is appropriate.

V12-14: PRODUCER-CONSUMER Example - SUCCESFULLY EXECUTED

