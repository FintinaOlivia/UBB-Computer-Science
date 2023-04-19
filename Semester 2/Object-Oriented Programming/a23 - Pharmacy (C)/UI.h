#pragma once
#include "DynamicArray.h"

void printMenu();

void printAllMedicines(MedicineDynamicArray* repository);

void addMedicine(MedicineDynamicArray* repository, 
					OperationDynamicArray* undoArray, 
					OperationDynamicArray* redoArray);

void deleteMedicine(MedicineDynamicArray* repository, 
					OperationDynamicArray* undoArray, 
					OperationDynamicArray* redoArray);

void updateMedicineName(MedicineDynamicArray* repository, 
						OperationDynamicArray* undoArray, 
						OperationDynamicArray* redoArray);

void updateMedicineConcentration(MedicineDynamicArray* repository, 
									OperationDynamicArray* undoArray, 
									OperationDynamicArray* redoArray);

void updateMedicineQuantity(MedicineDynamicArray* repository, 
							OperationDynamicArray* undoArray,
							OperationDynamicArray* redoArray);

void updateMedicinePrice(MedicineDynamicArray* repository, 
							OperationDynamicArray* undoArray,
							OperationDynamicArray* redoArray);

void printMedicinesByFilter(MedicineDynamicArray* repository);

int inputCommand();

void undo(MedicineDynamicArray* repository, 
			OperationDynamicArray* undoArray, 
			OperationDynamicArray* redoArray);

void redo(MedicineDynamicArray* repository, 
			OperationDynamicArray* undoArray, 
			OperationDynamicArray* redoArray);

int interpretCommand(MedicineDynamicArray* repository, 
					OperationDynamicArray* undoArray,
					OperationDynamicArray* redoArray,
					int userSelectedCommand);

void runConsole(MedicineDynamicArray* repository, 
				OperationDynamicArray* undoArray, 
				OperationDynamicArray* redoArray);