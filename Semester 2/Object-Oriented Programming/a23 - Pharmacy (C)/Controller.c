#include <string.h>
#include <stdlib.h>

#include "Repository.h"
#include "DynamicArray.h"
#include "Controller.h"

int uniqueId = -1;

int getNextId(){ 
	return ++uniqueId; 
};

void sortMedicinesArrayAscendingByName(MedicineDynamicArray* medicines)
{
	for (int i = 0; i < medicines->size - 1; i++)
		for (int j = i + 1; j < medicines->size; j++)
		{
			if (strcmp(medicines->elements[i].name, medicines->elements[j].name) > 0)
			{
				Medicine aux = medicines->elements[i];
				medicines->elements[i] = medicines->elements[j];
				medicines->elements[j] = aux;
			}
		}
}

void sortMedicinesArrayDescendingByName(MedicineDynamicArray* medicines)
{
	for (int i = 0; i < medicines->size - 1; i++)
		for (int j = i + 1; j < medicines->size; j++)
		{
			if (strcmp(medicines->elements[i].name, medicines->elements[j].name) < 0)
			{
				Medicine aux = medicines->elements[i];
				medicines->elements[i] = medicines->elements[j];
				medicines->elements[j] = aux;
			}
		}
}

MedicineDynamicArray *sortMedicinesArrayByConcentration(MedicineDynamicArray *repository)
{
    MedicineDynamicArray* medicinesSortedByConcentration = createMedicineDynamicArray(2);

	for (int i = 0; i < getMedicineDynamicArraySize(repository); i++)
	{
		addElementToMedicineDynamicArray(medicinesSortedByConcentration, 
										repository->elements[i]);
	}

	for (int i = 0; i < medicinesSortedByConcentration->size - 1; i++)
		for (int j = i + 1; j < medicinesSortedByConcentration->size; j++)
		{
			if (medicinesSortedByConcentration->elements[i].concentration < 
				medicinesSortedByConcentration->elements[j].concentration)
			{
				Medicine aux = medicinesSortedByConcentration->elements[i];

				medicinesSortedByConcentration->elements[i] =
				medicinesSortedByConcentration->elements[j];

				medicinesSortedByConcentration->elements[j] = aux;
			}
		}
	return medicinesSortedByConcentration;
}

MedicineDynamicArray* getAllMedicinesController(MedicineDynamicArray* repository)
{
	MedicineDynamicArray* allMedicines = createMedicineDynamicArray(2);

	for (int i = 0; i < getMedicineDynamicArraySize(repository); i++)
	{
		addElementToMedicineDynamicArray(allMedicines, repository->elements[i]);
	}

	sortMedicinesArrayAscendingByName(allMedicines);

	return allMedicines;
}

void addMedicineController(MedicineDynamicArray* repository, 
							OperationDynamicArray* undoArray, 
							OperationDynamicArray* redoArray,
							int id, 
							char* name, 
							int concentration, 
							int quantity, 
							int price)
{
	redoArray->size = 0;
	MedicineDynamicArray* allMedicines = createMedicineDynamicArray(2);

	for (int i = 0; i < getMedicineDynamicArraySize(repository); i++)
	{
		addElementToMedicineDynamicArray(allMedicines, repository->elements[i]);
	}

	int medicineExists = 0;
	
	for (int i = 0; i < getMedicineDynamicArraySize(allMedicines); i++)
	{
		if (!strcmp(getMedicineName(&allMedicines->elements[i]), name)
			&& getMedicineConcentration(allMedicines->elements[i]) == concentration)
		{
			repository->elements[i].quantity += quantity;
			medicineExists = 1;
		}
	}

	if (!medicineExists)
	{
		Medicine addedMedicine = addMedicineToRepository(repository, 
														id, 
														name, 
														concentration, 
														quantity, 
														price);
		Operation undoOperation;
		strcpy(undoOperation.operation, "add");
		undoOperation.medicine = addedMedicine;

		addElementToOperationDynamicArray(undoArray, undoOperation);
	}

	destroyMedicineDynamicArray(allMedicines);
}

void deleteMedicineController(MedicineDynamicArray* repository, 
								OperationDynamicArray* undoArray, 
								OperationDynamicArray* redoArray,
								char* name, 
								int concentration)
{
	redoArray->size = 0;
	Medicine deletedMedicine = deleteMedicineFromRepository(repository, 
															name, 
															concentration);

	Operation undoOperation;
	strcpy(undoOperation.operation, "delete");
	undoOperation.medicine = deletedMedicine;

	addElementToOperationDynamicArray(undoArray, undoOperation);
}

void updateMedicineNameController(MedicineDynamicArray* repository, 
									OperationDynamicArray* undoArray, 
									OperationDynamicArray* redoArray, 
									char* name, 
									int concentration, 
									char* newName)
{
	redoArray->size = 0;
	Medicine updatedMedicine = updateMedicineNameInRepository(repository, 
																name, 
																concentration, 
																newName);

	Operation undoOperation;
	strcpy(undoOperation.operation, "update");
	undoOperation.medicine = updatedMedicine;

	addElementToOperationDynamicArray(undoArray, undoOperation);
}

void updateMedicineConcentrationController(MedicineDynamicArray* repository, 
											OperationDynamicArray* undoArray,
											OperationDynamicArray* redoArray, 
											char* name, 
											int concentration, 
											int newConcentration)
{
	redoArray->size = 0;
	Medicine updatedMedicine = updateMedicineConcentrationInRepository(repository, 
																		name, 
																		concentration, 
																		newConcentration);

	Operation undoOperation;
	strcpy(undoOperation.operation, "update");
	undoOperation.medicine = updatedMedicine;

	addElementToOperationDynamicArray(undoArray, undoOperation);
}

void updateMedicineQuantityController(MedicineDynamicArray* repository, 
										OperationDynamicArray* undoArray, 
										OperationDynamicArray* redoArray,
										char* name, 
										int concentration, 
										int newQuantity)
{
	redoArray->size = 0;
	Medicine updatedMedicine = updateMedicineQuantityInRepository(repository, 
																	name, 
																	concentration, 
																	newQuantity);

	Operation undoOperation;
	strcpy(undoOperation.operation, "update");
	undoOperation.medicine = updatedMedicine;

	addElementToOperationDynamicArray(undoArray, undoOperation);
}

void updateMedicinePriceController(MedicineDynamicArray* repository, 
									OperationDynamicArray* undoArray, 
									OperationDynamicArray* redoArray,
	char* name, int concentration, int newPrice)
{
	redoArray->size = 0;
	Medicine updatedMedicine = updateMedicinePriceInRepository(repository, 
																name, 
																concentration, 
																newPrice);

	Operation undoOperation;
	strcpy(undoOperation.operation, "update");
	undoOperation.medicine = updatedMedicine;

	addElementToOperationDynamicArray(undoArray, undoOperation);
}

MedicineDynamicArray* getMedicinesByGivenNameController(MedicineDynamicArray* repository, 
														char* givenName)
{

	MedicineDynamicArray* allMedicines = createMedicineDynamicArray(2);

	for (int i = 0; i < getMedicineDynamicArraySize(repository); i++)
	{
		addElementToMedicineDynamicArray(allMedicines, repository->elements[i]);
	}

	if (!strcmp(givenName, "") || !strcmp(givenName, "\n"))
	{
		sortMedicinesArrayAscendingByName(allMedicines);
		return allMedicines;
	}

	MedicineDynamicArray* matchedMedicines = createMedicineDynamicArray(2);

	for (int i = 0; i < getMedicineDynamicArraySize(allMedicines); i++)
	{
		if (strstr(repository->elements[i].name, givenName))
			addElementToMedicineDynamicArray(matchedMedicines, repository->elements[i]);
	}

	destroyMedicineDynamicArray(allMedicines);

	sortMedicinesArrayAscendingByName(matchedMedicines);
	return matchedMedicines;
}

MedicineDynamicArray* getShortInSupplyMedicinesController(MedicineDynamicArray* repository, 
														int quantity,
														int sortAscending)
{
	MedicineDynamicArray* allMedicines = createMedicineDynamicArray(2);

	for (int i = 0; i < getMedicineDynamicArraySize(repository); i++)
	{
		addElementToMedicineDynamicArray(allMedicines, repository->elements[i]);
	}

	MedicineDynamicArray* matchedMedicines = createMedicineDynamicArray(2);

	for (int i = 0; i < getMedicineDynamicArraySize(allMedicines); i++)
	{
		if (getMedicineQuantity(allMedicines->elements[i]) < quantity)
			addElementToMedicineDynamicArray(matchedMedicines, allMedicines->elements[i]);
	}

	destroyMedicineDynamicArray(allMedicines);

	if (sortAscending == 1)
	{
		sortMedicinesArrayAscendingByName(matchedMedicines);
	}else{
		sortMedicinesArrayDescendingByName(matchedMedicines);
	}

	return matchedMedicines;
}

int undoController(MedicineDynamicArray* repository, 
					OperationDynamicArray* undoArray, 
					OperationDynamicArray* redoArray)
{
	// 0 return -> success
	// 1 return -> nothing to undo (undoArray has size 0)
	if (getOperationDynamicArraySize(undoArray) == 0)
		return 1;

	Operation undoOperation = undoArray->elements[getOperationDynamicArraySize(undoArray) - 1];


	if (!strcmp(undoOperation.operation, "add"))
	{
		addElementToOperationDynamicArray(redoArray, undoOperation);
		OperationDynamicArray* tempArray = createOperationDynamicArray(2);

		deleteMedicineController(repository, 
									tempArray, 
									tempArray, 
									undoOperation.medicine.name, 
									undoOperation.medicine.concentration);
		undoArray->size--;

		destroyOperationDynamicArray(tempArray);

		return 0;
	}

	if (!strcmp(undoOperation.operation, "delete"))
	{
		addElementToOperationDynamicArray(redoArray, undoOperation);
		OperationDynamicArray* tempArray = createOperationDynamicArray(2);

		addMedicineController(repository, 
							tempArray, 
							tempArray, 
							undoOperation.medicine.id, 
							undoOperation.medicine.name, 
							undoOperation.medicine.concentration,
			undoOperation.medicine.quantity, undoOperation.medicine.price);
		undoArray->size--;

		destroyOperationDynamicArray(tempArray);

		return 0;
	}

	if (!strcmp(undoOperation.operation, "update"))
	{
		OperationDynamicArray* tempArray = createOperationDynamicArray(2);
		Medicine medicineToDelete;

		for (int i = 0; i < getMedicineDynamicArraySize(repository); i++)
		{
			if (getMedicineId(repository->elements[i]) == getMedicineId(undoOperation.medicine))
			{
				Medicine redoMedicine;

				redoMedicine.id = repository->elements[i].id;
				strcpy(redoMedicine.name, repository->elements[i].name);
				redoMedicine.concentration = repository->elements[i].concentration;
				redoMedicine.quantity = repository->elements[i].quantity;
				redoMedicine.price = repository->elements[i].price;

				Operation newRedoOperation;
				strcpy(newRedoOperation.operation, "update");
				newRedoOperation.medicine = redoMedicine;

				addElementToOperationDynamicArray(redoArray, newRedoOperation);

				medicineToDelete.id = repository->elements[i].id;
				strcpy(medicineToDelete.name, repository->elements[i].name);
				medicineToDelete.concentration = repository->elements[i].concentration;

				break;
			}
		}




		deleteMedicineController(repository, tempArray, 
											tempArray, 
											medicineToDelete.name, 
											medicineToDelete.concentration);

		addMedicineController(repository, tempArray, 
											tempArray, 
											undoOperation.medicine.id, 
											undoOperation.medicine.name, 
											undoOperation.medicine.concentration,
											undoOperation.medicine.quantity, 
											undoOperation.medicine.price);
		undoArray->size--;

		destroyOperationDynamicArray(tempArray);
		
		return 0;
	}
}

int redoController(MedicineDynamicArray* repository, 
					OperationDynamicArray* undoArray, 
					OperationDynamicArray* redoArray)
{
	if (getOperationDynamicArraySize(redoArray) == 0)
		return 1;

	Operation redoOperation = redoArray->elements[getOperationDynamicArraySize(redoArray) - 1];

	if (!strcmp(redoOperation.operation, "add"))
	{
		OperationDynamicArray* tempArray = createOperationDynamicArray(2);

		addMedicineController(repository, undoArray, 
											tempArray, 
											redoOperation.medicine.id, 
											redoOperation.medicine.name,
											redoOperation.medicine.concentration, 
											redoOperation.medicine.quantity, 
											redoOperation.medicine.price);
		redoArray->size--;

		destroyOperationDynamicArray(tempArray);

		return 0;
	}

	if (!strcmp(redoOperation.operation, "delete"))
	{
		OperationDynamicArray* tempArray = createOperationDynamicArray(2);

		deleteMedicineController(repository, undoArray, 
											tempArray, 
											redoOperation.medicine.name, 
											redoOperation.medicine.concentration);
		redoArray->size--;

		destroyOperationDynamicArray(tempArray);

		return 0;
	}

	if (!strcmp(redoOperation.operation, "update"))
	{
		OperationDynamicArray* tempArray = createOperationDynamicArray(2);
		Medicine medicineToDelete;

		for (int i = 0; i < getMedicineDynamicArraySize(repository); i++)
		{
			if (getMedicineId(repository->elements[i]) == getMedicineId(redoOperation.medicine))
			{
				Medicine undoMedicine;

				undoMedicine.id = repository->elements[i].id;
				strcpy(undoMedicine.name, repository->elements[i].name);
				undoMedicine.concentration = repository->elements[i].concentration;
				undoMedicine.quantity = repository->elements[i].quantity;
				undoMedicine.price = repository->elements[i].price;

				Operation newUndoOperation;
				strcpy(newUndoOperation.operation, "update");
				newUndoOperation.medicine = undoMedicine;

				addElementToOperationDynamicArray(undoArray, newUndoOperation);

				medicineToDelete.id = repository->elements[i].id;
				strcpy(medicineToDelete.name, repository->elements[i].name);
				medicineToDelete.concentration = repository->elements[i].concentration;

				break;
			}
		}

		deleteMedicineController(repository, tempArray, 
											tempArray,
											medicineToDelete.name, 
											medicineToDelete.concentration);

		addMedicineController(repository, tempArray, 
											tempArray, 
											redoOperation.medicine.id, 
											redoOperation.medicine.name,
											redoOperation.medicine.concentration, 
											redoOperation.medicine.quantity, 
											redoOperation.medicine.price);

		redoArray->size--;

		destroyOperationDynamicArray(tempArray);
	}
}

void initController(MedicineDynamicArray* repository)
{
	OperationDynamicArray* undoArray = createOperationDynamicArray(2);
	OperationDynamicArray* redoArray = createOperationDynamicArray(2);

	addMedicineController(repository, undoArray, redoArray, getNextId(), "Paracetamol", 50, 13, 25);
	addMedicineController(repository, undoArray, redoArray, getNextId(), "Abracadabra", 70, 15, 30);
	addMedicineController(repository, undoArray, redoArray, getNextId(), "Imodium", 21, 3, 90);
	addMedicineController(repository, undoArray, redoArray, getNextId(), "Nurofen", 10, 4, 21);
	addMedicineController(repository, undoArray, redoArray, getNextId(), "Trinitrotoluen", 76, 49, 81);
	addMedicineController(repository, undoArray, redoArray, getNextId(), "Brufen", 23, 17, 33);
	addMedicineController(repository, undoArray, redoArray, getNextId(), "FortificatForte", 48, 57, 69);
	addMedicineController(repository, undoArray, redoArray, getNextId(), "Baneocin", 19, 4, 21);
	addMedicineController(repository, undoArray, redoArray, getNextId(), "Valeleu", 70, 92, 84);
	addMedicineController(repository, undoArray, redoArray, getNextId(), "Aualeu", 30, 15, 35);

	destroyOperationDynamicArray(undoArray);
	destroyOperationDynamicArray(redoArray);
}