#pragma once
#include "Repository.h"
#include "DynamicArray.h"

int getNextId();

void sortMedicinesArrayDescendingByName(MedicineDynamicArray* medicines);

MedicineDynamicArray* sortMedicinesArrayByConcentration(MedicineDynamicArray* repository);

MedicineDynamicArray* getAllMedicinesController(MedicineDynamicArray* repository);

void addMedicineController(MedicineDynamicArray* repository, 
							OperationDynamicArray* undoArray, 
							OperationDynamicArray* redoArray,
							int id, 
							char* name, 
							int concentration, 
							int quantity, 
							int price);

void deleteMedicineController(MedicineDynamicArray* repository, 
								OperationDynamicArray* undoArray, 
								OperationDynamicArray* redoArray, 
								char* name, 
								int concentration);

void updateMedicineNameController(MedicineDynamicArray* repository, 
									OperationDynamicArray* undoArray, 
									OperationDynamicArray* redoArray,
									char* name, 
									int concentration, 
									char* newName);

void updateMedicineConcentrationController(MedicineDynamicArray* repository, 
											OperationDynamicArray* undoArray,
											OperationDynamicArray* redoArray, 
											char* name, 
											int concentration, 
											int newConcentration);

void updateMedicineQuantityController(MedicineDynamicArray* repository, 
										OperationDynamicArray* undoArray, 
										OperationDynamicArray* redoArray,
										char* name, 
										int concentration, 
										int newQuantity);

void updateMedicinePriceController(MedicineDynamicArray* repository, 
									OperationDynamicArray* undoArray, 
									OperationDynamicArray* redoArray,	
									char* name, 
									int concentration, 
									int newPrice);

MedicineDynamicArray* getMedicinesByGivenNameController(MedicineDynamicArray* repository, 
														char* givenName);

MedicineDynamicArray* getShortInSupplyMedicinesController(MedicineDynamicArray* repository, 
															int quantity, int sortAscending);

int undoController(MedicineDynamicArray* repository, 
					OperationDynamicArray* undoArray, 
					OperationDynamicArray* redoArray);

int redoController(MedicineDynamicArray* repository, 
					OperationDynamicArray* undoArray, 
					OperationDynamicArray* redoArray);
					
void initController(MedicineDynamicArray* repository);