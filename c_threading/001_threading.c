#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>

// Pthread expect function definition like this
// void * (*)(void *)
void* perform(void *arg)
{
    int i;
    // dereferencing void to int
    // i.e., The compiler expects void *
    int n = *((int *)arg);
    printf("processing from thread\r\n");
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
    /* int pthread_create (pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
        - pthread_attr_t is thread attributes
        - start_routine is a function that will be executed
        - arg is argument that passes to function
    */ 
    ret = pthread_create(&thread, NULL, perform, &n);
    if (ret)
    {
        printf("\n pthread_create() failed with error [%s]\n",strerror(errno));
        return -1;
    }
    int c = getchar(); // hold app to exit
    return 0;
}
