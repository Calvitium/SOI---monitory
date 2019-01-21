#include <iostream>
#include "My_Monitor.h"
#include <pthread.h>
#include <cstdlib>
using namespace std;

My_Monitor monitor;

void *consumerA(void* args)
{
    monitor.consumerA();
}
void *consumerB(void* args)
{
    monitor.consumerB();
}
void *producerA(void* args)
{
    monitor.producerA();
}
void *producerB(void* args)
{
    monitor.producerB();
}

int main()
{
    pthread_t pA, pB, cA, cB;
    pthread_create(&pA, NULL, producerA, NULL);
    pthread_create(&pB, NULL, producerB, NULL);
    pthread_create(&cA, NULL, consumerA, NULL);
    pthread_create(&cB, NULL, consumerB, NULL);
    puts("================================");
    puts("        SIMULATION START");
    puts("================================");
    printf("\n\n\n\n\n\n");
    pthread_join(pA, NULL);
    pthread_join(pB, NULL);
    pthread_join(cA, NULL);
    pthread_join(cB, NULL);
    puts("================================");
    puts("        SIMULATION END");
    puts("================================");
    return 0;
}