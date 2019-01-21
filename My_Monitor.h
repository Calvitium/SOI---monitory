//
// Created by mateusz on 01.01.19.
//

#ifndef SOI_MONITORY_MY_MONITOR_H
#define SOI_MONITORY_MY_MONITOR_H

#include "Monitor.h"

#define BUFFER_SIZE 9

class My_Monitor : Monitor
{
private:
    Condition three_or_less, four_or_less, prA, prB;
    int *buffer;
public:
    My_Monitor() : Monitor()
    {
        buffer = new int[BUFFER_SIZE+1];
        buffer[0] = 0;
    }
    ~My_Monitor()
    {
        delete[] buffer;
    }

    void append();
    void popFirst();
    void print_buffer();

    void consumerA();
    void consumerB();

    void producerA();
    void producerB();

    void random_sleep();
};



#endif //SOI_MONITORY_MY_MONITOR_H
