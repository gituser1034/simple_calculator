#ifndef QUEUE_H
#define QUEUE_H
#include <vector>
using namespace std;

// FIFO data structure for storing data
class Queue{
    public:
        Queue(){}
        ~Queue(){}
        // Add item to beginning
        void enqueue(char value);
        // Removes item from end
        void dequeue();
        void print();
    private:
        // What data type for the queue?
        vector<char> queue;
};

#endif