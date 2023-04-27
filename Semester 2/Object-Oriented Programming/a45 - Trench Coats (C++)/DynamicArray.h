#pragma once

#include<string>
#include<typeinfo>
#include<fstream>
#include<iostream>
#include<random>

using namespace std;

template <class Type>
class dynamicVector {
    private:
        int size{};
        int capacity{};
        Type* elements;

    public:
        explicit dynamicVector(int capacity = 10);
        dynamicVector(const dynamicVector& dynamicVectorToCopy);
        ~dynamicVector();
        dynamicVector<Type>& operator = (const dynamicVector &other);
        
        
        void append(Type element);
        void remove(int index);

    __attribute__((unused)) void update(int index, Type element);

        Type operator[](int index);
        int getSize();
        int getCapacity();
    
};

template <class Type>
inline dynamicVector<Type>::dynamicVector(int capacity)
{
    this->size = 0;
    this->capacity = capacity;
    this->elements = new Type[capacity];
}

template <class Type>
inline dynamicVector<Type>::dynamicVector(const dynamicVector &dynamicVectorToCopy)
{
    this->size = dynamicVectorToCopy.size;
    this->capacity = dynamicVectorToCopy.capacity;
    this->elements = new Type[this->capacity];
    for (int i = 0; i < this->size; i++)
    {
        this->elements[i] = dynamicVectorToCopy.elements[i];
    }
}

template <class Type>
inline dynamicVector<Type>::~dynamicVector()
{
    delete[] this->elements;
}

template <class Type>
inline dynamicVector<Type> &dynamicVector<Type>::operator=(const dynamicVector &other)
{
    this->size = other.size;
    this->capacity = other.capacity;
    delete[] this->elements;
    this->elements = new Type[other.capacity];

    for(int i = 0;i < other.capacity;i++){
        this->elements[i] = other.elements[i];
    }
    return *this;
}

template <class Type>
inline void dynamicVector<Type>::append(Type element)
{
    if (this->size == this->capacity)
    {
        this->capacity *= 2;
        Type* newElements = new Type[this->capacity];
        for (int i = 0; i < this->size; i++)
        {
            newElements[i] = this->elements[i];
        }
        delete[] this->elements;
        this->elements = newElements;
    }
    this->elements[this->size] = element;
    this->size++;
}

template <class Type>
inline void dynamicVector<Type>::remove(int index)
{
    if (index < 0 || index >= this->size){
        return;
    }

    for (int i = index; i < this->size - 1; i++)
    {
        this->elements[i] = this->elements[i + 1];
    }
    this->size--;
}

template <class Type>
__attribute__((unused)) inline void dynamicVector<Type>::update(int index, Type element)
{
    if (index < 0 || index >= this->size)
    {
        return;
    }
    this->elements[index] = element;
}

template <class Type>
inline Type dynamicVector<Type>::operator[](int index)
{
    return this->elements[index];
}

template <class Type>
inline int dynamicVector<Type>::getSize(){
    return this->size;
}

template <class Type>
inline int dynamicVector<Type>::getCapacity(){
    return this->capacity;
}

