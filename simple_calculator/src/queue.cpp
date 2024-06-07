#include "../headers/queue.h"
#include <iostream>
#include <vector>

using namespace std;

// Add to queue
void Queue::enqueue(char value){
    queue.push_back(value);
}

// Remove item that was first in
void Queue::dequeue(){
    queue.erase(queue.begin());
}

void Queue::print(){
    for (int i = 0; i < queue.size(); i++){
        cout << queue[i];
    }
    cout << endl;
}