//
// Created by Theo on 20 Oct 2024.
//

#include "Buffer.h"

#include <iostream>

Buffer::Buffer() = default;

int Buffer::get() {
    std::unique_lock lock(mutex);

    while(queue.empty()) {
        std::cout<<"\nThread with id " << std::hash<std::thread::id>{}(std::this_thread::get_id())<<" : Buffer is currently empty"<<"\n";
        readyToReceive.wait(lock);
    }

    int value = queue.front();
    queue.pop();

    readyToSend.notify_one();
    return value;
}

void Buffer::put(int value) {
    std::unique_lock lock(mutex);

    while(queue.size() == 1) {
        std::cout <<"\nThread with id "
                <<std::hash<std::thread::id>{}(std::this_thread::get_id())
                <<" extracted value "
                << value
                << " from the queue\n";
        readyToSend.wait(lock);
    }

    queue.push(value);

    std::cout<<"\nThread with id "<< std::hash<std::thread::id>{}(std::this_thread::get_id())
            <<" added value " << value << " to the queue\n\n";
    readyToReceive.notify_one();
}

