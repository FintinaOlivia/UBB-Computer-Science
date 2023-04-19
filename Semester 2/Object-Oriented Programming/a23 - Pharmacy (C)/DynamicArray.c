#include <stdlib.h>
#include <string.h>
#include "DynamicArray.h"

MedicineDynamicArray* createMedicineDynamicArray(int capacity)
{
	MedicineDynamicArray* dynamicArray = malloc(sizeof(MedicineDynamicArray));

	if (dynamicArray == NULL)
		return NULL;

	dynamicArray->capacity = capacity;
	dynamicArray->size = 0;
	dynamicArray->elements = malloc(capacity * sizeof(TElem));

	if (dynamicArray->elements == NULL)
		return NULL;

	return dynamicArray;
}

void addElementToMedicineDynamicArray(MedicineDynamicArray* dynamicArray, 
										TElem element)
{
	if (dynamicArray->size == dynamicArray->capacity)
		resizeMedicineDynamicArray(dynamicArray);

	dynamicArray->elements[dynamicArray->size] = element;
	dynamicArray->size++;
}


void resizeMedicineDynamicArray(MedicineDynamicArray* dynamicArray)
{
	if (dynamicArray == NULL)
		return;

	int cap = dynamicArray->capacity * 2;

	dynamicArray->capacity *= 2;
	void* aux = realloc(dynamicArray->elements, cap * sizeof(TElem));

	if (aux == NULL)
		return;

	dynamicArray->capacity = cap;
	dynamicArray->elements = aux;
}

void destroyMedicineDynamicArray(MedicineDynamicArray* dynamicArray)
{
	if (dynamicArray == NULL)
		return;

	free(dynamicArray->elements);
	free(dynamicArray);
}

//Getters

int getMedicineDynamicArraySize(MedicineDynamicArray* dynamicArray)
{
	return dynamicArray->size;
}

int getMedicineDynamicArrayCapacity(MedicineDynamicArray* dynamicArray)
{
	return dynamicArray->capacity;
}

OperationDynamicArray* createOperationDynamicArray(int capacity)
{
	OperationDynamicArray* dynamicArray = malloc(sizeof(OperationDynamicArray));

	if (dynamicArray == NULL)
		return NULL;

	dynamicArray->capacity = capacity;
	dynamicArray->size = 0;
	dynamicArray->elements = malloc(capacity * sizeof(Operation));

	if (dynamicArray->elements == NULL)
		return NULL;

	return dynamicArray;
}

void addElementToOperationDynamicArray(OperationDynamicArray* dynamicArray, 
										Operation element)
{
	if (dynamicArray->size == dynamicArray->capacity)
		resizeOperationDynamicArray(dynamicArray);

	dynamicArray->elements[dynamicArray->size] = element;
	dynamicArray->size++;
}


void resizeOperationDynamicArray(OperationDynamicArray* dynamicArray)
{
	if (dynamicArray == NULL)
		return;

	int cap = dynamicArray->capacity * 2;

	dynamicArray->capacity *= 2;
	void* aux = realloc(dynamicArray->elements, cap * sizeof(Operation));

	if (aux == NULL)
		return;

	dynamicArray->capacity = cap;
	dynamicArray->elements = aux;
}

void destroyOperationDynamicArray(OperationDynamicArray* dynamicArray)
{
	if (dynamicArray == NULL)
		return;

	free(dynamicArray->elements);
	free(dynamicArray);
}

int getOperationDynamicArraySize(OperationDynamicArray* dynamicArray)
{
	return dynamicArray->size;
}

int getOperationDynamicArrayCapacity(OperationDynamicArray* dynamicArray)
{
	return dynamicArray->capacity;
}