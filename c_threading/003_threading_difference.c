#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <errno.h>
#include <string.h>

void* threaded_ct_dn(void *arg)
{
    // pthread_t pthread_self (void);
    pthread_t tid;
    int n = *((int *)arg);
    printf("\nprocessing from thread\r\n");
    tid = pthread_self();
    printf("\nThread id: %d \r\n",(int)tid);
    while(n > 0)
    {
        n = n - 1;
    }
}

void ct_down(int n){
    while(n > 0){
        n = n - 1;
    }
}

int main()
{
    pthread_t thread[2];
    pthread_attr_t attr;
    void *status;
    int i, ret, start, stop;
    float difference;
    errno = 0;
    int n = 50000000;

    // thread attribute
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    /********************* Test without thread *****************/
    start = clock();
    ct_down(n);
    stop = clock();
    difference = (stop - start);
    printf("\nExecution time without thread is %.4f seconds \n", difference);
    /********************* Test with thread *****************/
    start = clock();
    for(i=0;i<2;i++){
        ret = pthread_create(&thread[i], &attr, threaded_ct_dn, &n);
        if (ret)
        {
            printf("\n pthread_create() failed with error [%s]\n",strerror(errno));
            return -1;
        }
    }
    printf("joining thread\r\n");
    for(i=0;i<2;i++)
    {
        ret = pthread_join(thread[i], &status);
        if (ret)
        {
            printf("\n pthread_join() failed with error [%s]\n",strerror(errno));
            return -1;
        }
        printf("Completed join with thread %ld. Status: %ld\n", i, (int *)status);
    }
    stop = clock();
    difference = (stop - start);
    printf("\nExecution time without thread is %.4f seconds\n", difference);
    int c = getchar(); // hold app to exit
    return 0;
}