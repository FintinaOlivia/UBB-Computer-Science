#pragma once

typedef struct
{
	int id;
	char name[30];
	int concentration;
	int quantity;
	int price;

} Medicine;

typedef Medicine TElem;

//Getters
int getMedicineId(TElem medicine);
char* getMedicineName(TElem* medicine);
int getMedicineConcentration(TElem medicine);
int getMedicineQuantity(TElem medicine);
int getMedicinePrice(TElem medicine);

//Setters
void setMedicineName(TElem* medicine, char* newName);
void setMedicineConcentration(TElem* medicine, int newConcentration);
void setMedicineQuantity(TElem* medicine, int newQuantity);
void setMedicinePrice(TElem* medicine, int newPrice);

typedef struct
{
	// add OR delete OR update
	char operation[30]; 
	Medicine medicine;
} Operation; 

// Undo getters
char* getUndoOperation(Operation* undoOperation);
Medicine getUndoOperationMedicine(Operation undoOperation);

//Undo Setters
void setUndoOperation(Operation* undoOperation, char* newUndoOperation);
void setUndoOperationMedicine(Operation undoOperation, 
								Medicine newUndoOperationMedicine);

//Redo Getters
char* getRedoOperation(Operation* redoOperation);
Medicine getRedoOperationMedicine(Operation redoOperation);

//Redo Setters
void setRedoOperation(Operation* redoOperation, char* newRedoOperation);
void setRedoOperationMedicine(Operation redoOperation, 
								Medicine newRedoOperationMedicine);