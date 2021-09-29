#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(){
    int i, start, stop;
    float difference;
    start = clock();
    for(i=0;i<5;i++){
        sleep(1);
        printf("Testing delay\n");
    }
    stop = clock();
    difference = (stop - start) / 1000;
    printf("Total execution time is: %.2f sec.", difference);
    return 0;
}