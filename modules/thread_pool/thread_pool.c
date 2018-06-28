#include "thread_pool.h"

Thread_pool *pool = NULL;
static Thread_pool pool_1;

void * thread_routine (void *arg);

int pool_init(int max_thread_num)
{
    pool = &pool_1;
    if(!pool)
        return -1;
    pthread_mutex_init(&(pool->queue_lock), NULL); //init lock
    pthread_cond_init(&(pool->queue_ready), NULL); //ready
    pool->queue_head = NULL;                        //clear work queue
    pool->max_thread_num = max_thread_num;          //number of active process
    pool->cur_queue_size = 0;                       //clear work queue
    pool->shutdown = 0;                             //thread close flag
    pool->threadid = (pthread_t *)malloc(max_thread_num*sizeof(pthread_t));
    for(int i=0;i<max_thread_num;i++)
    {
        int ret = pthread_create(&(pool->threadid[i]),NULL,thread_routine,NULL);
        if(ret != 0)
        {
            return ret;
        }
    }
    return 0;
}
void *thread_routine(void *arg)
{
    //printf ("starting thread 0x%x\n", pthread_self ());
    while (1)
    {
        int ret = pthread_mutex_lock(&(pool->queue_lock));
        while(pool->cur_queue_size == 0 && !pool->shutdown)
        {
            //printf ("thread 0x%x is waiting\n", pthread_self ());
            pthread_cond_wait (&(pool->queue_ready), &(pool->queue_lock)); //cond_wait atom operation,
        }

        if(pool->shutdown)
        {
            pthread_mutex_unlock (&(pool->queue_lock));                     // unlock first
            //LOG("thread 0x%x will exit\n", pthread_self ());
            pthread_exit(NULL);
        }
        //printf ("thread 0x%x is starting to work\n", pthread_self ());
        assert (pool->cur_queue_size != 0);
        assert (pool->queue_head != NULL);

        pool->cur_queue_size--;                                         //work queue reduce 1 and delete list head member
        Thread_worker *worker = pool->queue_head;
        pool->queue_head = worker->next;
        pthread_mutex_unlock (&(pool->queue_lock));

        (*(worker->process))(worker->arg);

        free(worker);
        worker = NULL;
    }
}
int pool_add_worker (void *(*process) (void *arg), void *arg)
{
    if(process == NULL)
    {
    	return -1;
    }
    Thread_worker *newworker = (Thread_worker*)malloc(sizeof(Thread_worker));
    newworker->process = process;                   //add process for a thread
    newworker->arg = arg;                           //arguments
    newworker->next = NULL;                         //next work set NULL

    pthread_mutex_lock (&(pool->queue_lock));
    Thread_worker *member = pool->queue_head;       //add new task to list tail
    if (member != NULL)
    {
        while (member->next != NULL)
            member = member->next;
        member->next = newworker;
    }
    else
    {
        pool->queue_head = newworker;
    }

    assert (pool->queue_head != NULL);              //assert

    pool->cur_queue_size++;
    pthread_mutex_unlock (&(pool->queue_lock));

    pthread_cond_signal(&(pool->queue_ready));      //wake up a thread who are blocked
    return 0;
}
