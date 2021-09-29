#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>

// Pthread expect function definition like this
// void * (*)(void *)
void* perform(void *arg)
{
    int i;
    // pthread_t pthread_self (void);
    pthread_t tid;
    int n = *((int *)arg);
    printf("\nprocessing from thread\r\n");
    tid = pthread_self();
    printf("\nThread id: %d \r\n",(int)tid);
    for(i=0;i<n;i++)
    {
        printf("%d ",i);
    }
}

int main()
{
    pthread_t thread;
    int ret;
    errno = 0;
    int n = 10;
    ret = pthread_create(&thread, NULL, perform, &n);
    if (ret)
    {
        printf("\n pthread_create() failed with error [%s]\n",strerror(errno));
        return -1;
    }
    ret = pthread_create(&thread, NULL, perform, &n);
    if (ret)
    {
        printf("\n pthread_create() failed with error [%s]\n",strerror(errno));
        return -1;
    }
    int c = getchar(); // hold app to exit
    return 0;
}
