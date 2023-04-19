#include <stdlib.h>
#include <string.h>
#include "Repository.h"
#include "DynamicArray.h"
#include "Domain.h"

MedicineDynamicArray* createRepository()
{
	return createMedicineDynamicArray(2);
}

Medicine addMedicineToRepository(MedicineDynamicArray* repository, 
								int id,
								char* name, 
								int concentration, 
								int quantity, 
								int price)
{
	Medicine newMedicine;

	//newMedicine.name = "";
	strcpy(newMedicine.name, name);
	newMedicine.id = id;
	newMedicine.concentration = concentration;
	newMedicine.quantity = quantity;
	newMedicine.price = price;
	
	addElementToMedicineDynamicArray(repository, newMedicine);

	return newMedicine;
}

TElem* getAllMedicinesFromRepository(MedicineDynamicArray* repository)
{
	return repository->elements;
}

int getIndexOfSearchedMedicineFromRepository(MedicineDynamicArray* repository, 
											char* name, 
											int concentration)
{
	for (int i = 0; i < getMedicineDynamicArraySize(repository); i++)
	{
		if (!strcmp(getMedicineName(&repository->elements[i]), name)
			&& getMedicineConcentration(repository->elements[i]) == concentration)
			return i;
	}
	return -1;
}

Medicine deleteMedicineFromRepository(MedicineDynamicArray* repository, 
									char* name, 
									int concentration)
{
	int searchedIndex = getIndexOfSearchedMedicineFromRepository(repository, 
																name, 
																concentration);
	Medicine searchedMedicine = repository->elements[searchedIndex];
	if (searchedIndex != -1)
	{
		for (int i = searchedIndex; i < getMedicineDynamicArraySize(repository) - 1; i++)
			repository->elements[i] = repository->elements[i + 1];

		repository->size--;
	}

	return searchedMedicine;
}

Medicine updateMedicineNameInRepository(MedicineDynamicArray* repository, 
										char* name, 
										int concentration, 
										char* newName)
{
	int searchedIndex = getIndexOfSearchedMedicineFromRepository(repository, 
																name, 
																concentration);
	Medicine updatedMedicine = repository->elements[searchedIndex];

	if (searchedIndex != -1)
		strcpy(repository->elements[searchedIndex].name, newName);

	return updatedMedicine;
}

Medicine updateMedicineConcentrationInRepository(MedicineDynamicArray* repository, 
												char* name, 
												int concentration, 
												int newConcentration)
{
	int searchedIndex = getIndexOfSearchedMedicineFromRepository(repository, 
																name, 
																concentration);
	Medicine updatedMedicine = repository->elements[searchedIndex];

	if (searchedIndex != -1)
		repository->elements[searchedIndex].concentration = newConcentration;

	return updatedMedicine;
}

Medicine updateMedicineQuantityInRepository(MedicineDynamicArray* repository, 
											char* name, 
											int concentration, 
											int newQuantity)
{
	int searchedIndex = getIndexOfSearchedMedicineFromRepository(repository, 
																name, 
																concentration);
	Medicine updatedMedicine = repository->elements[searchedIndex];

	if (searchedIndex != -1)
		repository->elements[searchedIndex].quantity = newQuantity;

	return updatedMedicine;
}

Medicine updateMedicinePriceInRepository(MedicineDynamicArray* repository, 
										char* name, 
										int concentration, 
										int newPrice)
{
	int searchedIndex = getIndexOfSearchedMedicineFromRepository(repository, 
																name, 
																concentration);
	Medicine updatedMedicine = repository->elements[searchedIndex];

	if (searchedIndex != -1)
		repository->elements[searchedIndex].price = newPrice;

	return updatedMedicine;
}