#pragma once
#include "Domain.h"

typedef struct
{
	TElem* elements;
	int size, capacity;
} MedicineDynamicArray;

typedef Medicine TElem;

MedicineDynamicArray* createMedicineDynamicArray(int capacity);

void addElementToMedicineDynamicArray(MedicineDynamicArray* dynamicArray, 
										TElem element);
void resizeMedicineDynamicArray(MedicineDynamicArray* dynamicArray);
int getMedicineDynamicArraySize(MedicineDynamicArray* dynamicArray);
int getMedicineDynamicArrayCapacity(MedicineDynamicArray* dynamicArray);
void destroyMedicineDynamicArray(MedicineDynamicArray* dynamicArray);

typedef struct
{
	Operation* elements;
	int size, capacity;
} OperationDynamicArray;

OperationDynamicArray* createOperationDynamicArray(int capacity);

void addElementToOperationDynamicArray(OperationDynamicArray* dynamicArray, 
										Operation element);
void resizeOperationDynamicArray(OperationDynamicArray* dynamicArray);
int getOperationDynamicArraySize(OperationDynamicArray* dynamicArray);
int getOperationDynamicArrayCapacity(OperationDynamicArray* dynamicArray);
void destroyOperationDynamicArray(OperationDynamicArray* dynamicArray);