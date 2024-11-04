#include <iostream>
#include <thread>
#include <vector>
#include "Buffer/Buffer.h"

std::vector<int> vector1;
std::vector<int> vector2;
int sum = 0;

void consumer(Buffer* buffer){
    for(int i = 0; i < vector1.size(); i++){
        int value = buffer->get();
        sum += value;
        std::cout<<"Consumer: sum is " << sum << "\n";
    }

    std::cout<<"The final sum is " << sum << "\n";
}

void producer(Buffer* buffer){
    for(int i = 0; i < vector1.size(); i++){
        int val1 = vector1[i];
        int val2 = vector2[i];
        std::cout<<"Producer: sending " << val1 << " * " << val2 << " = " << val1 * val2 << "\n";
        int result = val1 * val2;
        buffer->put(result);
    }
}

int main ()
{
    for(int i = 0; i < 100; i++){
        vector1.push_back(1);
        vector2.push_back(i+1);
    }

    auto* buffer = new Buffer();
    std::thread Consumer(consumer, buffer);
    std::thread Producer(producer, buffer);

    Consumer.join();
    Producer.join();

    return 0;
}