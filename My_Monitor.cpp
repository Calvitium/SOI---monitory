//
// Created by mateusz on 01.01.19.
//
#include "My_Monitor.h"


void My_Monitor::print_buffer()
{
    printf("============================================================\n");
    printf("BUFFER: | ");
    for(int iter = 1; iter<buffer[0] + 1; iter++)
        printf("%d | ", buffer[iter]);
    for(int iter = buffer[0]+1; iter<BUFFER_SIZE +1; iter++)
        printf("- | ");
    puts("");
    printf("============================================================\n");
    printf("\n\n\n");
}
void My_Monitor::append()
{
    int value = rand() % 100;
    buffer[buffer[0]+1] = value;
    ++buffer[0];
}
void My_Monitor::popFirst()
{
    int i;
    for(i = 1; i < buffer[0] + 1; i++)
        buffer[i] = buffer[i + 1];
    --buffer[0];
}
void  My_Monitor::producerA()
{
    while(true)
    {
        enter();
        if(buffer[0] + 1 > BUFFER_SIZE)
            wait(prA);
        append();
        printf("Producer A produces: %d\n", buffer[buffer[0]]);
        print_buffer();
        if(buffer[0] >= 4)
            signal(three_or_less);
        if(buffer[0] >= 5)
            signal(four_or_less);
        leave();
        random_sleep();
    }
}


void  My_Monitor::producerB()
{
    while(true)
    {
        enter();
        if(buffer[0] + 3 > BUFFER_SIZE)
           wait(prB);
        append();
        append();
        append();
        printf("Producer B produces: %d, %d, %d\n", buffer[buffer[0]-2], buffer[buffer[0]-1], buffer[buffer[0]]);
        print_buffer();
        if(buffer[0] >= 4)
            signal(three_or_less);
        if(buffer[0] >= 5)
            signal(four_or_less);
        leave();
        random_sleep();
    }
}


void  My_Monitor::consumerA()
{
    while(true)
    {
        enter();
        if(buffer[0] < 4)
            wait(three_or_less);
        printf("Consumer A eats: %d\n", buffer[1]);
        popFirst();
        print_buffer();
        signal(prA);
        if(buffer[0] <= BUFFER_SIZE - 3)
            signal(prB);
        leave();
        random_sleep();
    }

}


void  My_Monitor::consumerB()
{
    while(true)
    {
        enter();
        if(buffer[0] < 5)
            wait(four_or_less);
        printf("Consumer B eats: %d, %d\n", buffer[1], buffer[2]);
        popFirst();
        popFirst();
        print_buffer();
        signal(prA);
        if(buffer[0] <= BUFFER_SIZE - 3)
            signal(prB);
        leave();
        random_sleep();
    }
}
void My_Monitor::random_sleep()
{
    useconds_t microseconds = rand()%150000;
    usleep(microseconds);
}