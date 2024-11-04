//
// Created by Theo on 20 Oct 2024.
//

#ifndef BUFFER_H
#define BUFFER_H
#include <condition_variable>
#include <mutex>
#include <queue>


class Buffer {
private:
    std::mutex mutex;
    std::condition_variable readyToSend;
    std::condition_variable readyToReceive;
    std::queue<int> queue;

public:
    Buffer();

    int get();
    void put(int value);
};



#endif //BUFFER_H
