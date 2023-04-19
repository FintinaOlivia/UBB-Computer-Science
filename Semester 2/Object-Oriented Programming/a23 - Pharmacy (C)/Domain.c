#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "Domain.h"

int getMedicineId(TElem medicine)
{
	return medicine.id;
}

char* getMedicineName(TElem* medicine)
{
	return medicine->name;
}

int getMedicineConcentration(TElem medicine)
{
	return medicine.concentration;
}

int getMedicineQuantity(TElem medicine)
{
	return medicine.quantity;
}

int getMedicinePrice(TElem medicine)
{
	return medicine.price;
}

void setMedicineName(TElem* medicine, 
					char* newName)
{
	strcpy(medicine->name, newName);
}

void setMedicineConcentration(TElem* medicine, 
								int newConcentration)
{
	medicine->concentration = newConcentration;
}

void setMedicineQuantity(TElem* medicine, 
						int newQuantity)
{
	medicine->quantity = newQuantity;
}

void setMedicinePrice(TElem* medicine, int newPrice)
{
	medicine->price = newPrice;
}

char* getUndoOperation(Operation* undoOperation)
{
	return undoOperation->operation;
}

Medicine getUndoOperationMedicine(Operation undoOperation)
{
	return undoOperation.medicine;
}

void setUndoOperation(Operation* undoOperation, 
						char* newUndoOperation)
{
	strcpy(undoOperation->operation, newUndoOperation);
}

void setUndoOperationMedicine(Operation undoOperation, 
								Medicine newUndoOperationMedicine)
{
	undoOperation.medicine = newUndoOperationMedicine;
}

char* getRedoOperation(Operation* redoOperation)
{
	return redoOperation->operation;
}

Medicine getRedoOperationMedicine(Operation redoOperation)
{
	return redoOperation.medicine;
}

void setRedoOperation(Operation* redoOperation, 
						char* newRedoOperation)
{
	strcpy(redoOperation->operation, newRedoOperation);
}

void setRedoOperationMedicine(Operation redoOperation, 
								Medicine newRedoOperationMedicine)
{
	redoOperation.medicine = newRedoOperationMedicine;
}