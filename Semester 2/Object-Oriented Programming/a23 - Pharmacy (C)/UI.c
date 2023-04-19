#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "UI.h"
#include "Controller.h"

void printMenu()
{
	printf("\n");
	
	printf("+----------------------------------------------------------------------------+\n");
	printf("|   Welcome to the \"Smiles\" Pharmacy! What would you like to do today?       | \n");
	printf("+----------------------------------------------------------------------------+\n");

	printf("1. Print a list of all medicines;\n");
	printf("2. Add a medicine to the list;\n");
	printf("3. Delete a medicine from the list;\n");
	printf("4. Update a medicine's name;\n");
	printf("5. Update a medicine's concentration;\n");
	printf("6. Update a medicine's quantity;\n");
	printf("7. Update a medicine's price;\n");
	printf("8. Search for medicines;\n");
	printf("9. Search for medicines short in supply;\n");
	printf("10. Undo; \n");
	printf("11. Redo; \n");
	printf("12. Exit.\n");
}

void waitForNextInput()
{
	printf("Press any key to return.");
	getchar();
}

void printMedicinesFromDynamicArray(MedicineDynamicArray* medicines)
{
	for (int i = 0; i < medicines->size; i++)
	{
		printf("%d. Name = %s ", i + 1, getMedicineName(&medicines->elements[i]));
		printf("Concentration = %d ", getMedicineConcentration(medicines->elements[i]));
		printf("Quantity = %d ", getMedicineQuantity(medicines->elements[i]));
		printf("Price = %d\n", getMedicinePrice(medicines->elements[i]));
	}
}

void printAllMedicines(MedicineDynamicArray* repository)
{
	MedicineDynamicArray* allMedicines = getAllMedicinesController(repository);

	printf("All medicines are listed below:\n");

	printMedicinesFromDynamicArray(allMedicines);

	destroyMedicineDynamicArray(allMedicines);
}

void addMedicine(MedicineDynamicArray* repository, 
				OperationDynamicArray* undoArray, 
				OperationDynamicArray* redoArray)
{
	char name[30];
	int concentration, quantity, price;

	printf("Please enter the name: ");
	scanf("%s", name);

	printf("Please enter the concentration: ");
	scanf("%d", &concentration);

	printf("Please enter the quantity: ");
	scanf("%d", &quantity);

	printf("Please enter the price: ");
	scanf("%d", &price);

	addMedicineController(repository, undoArray, redoArray, 
						getNextId(), 
						name, concentration, quantity, price);
}

void deleteMedicine(MedicineDynamicArray* repository, 
					OperationDynamicArray* undoArray, 
					OperationDynamicArray* redoArray)
{
	char name[30];
	int concentration;

	printf("Please enter the name of the medicine you want to delete: ");
	scanf("%s", name);

	printf("Please enter the concentration of the medicine you want to delete: ");
	scanf("%d", &concentration);

	deleteMedicineController(repository, undoArray, redoArray, 
							name, concentration);
}

void updateMedicineName(MedicineDynamicArray* repository,
						OperationDynamicArray* undoArray, 
						OperationDynamicArray* redoArray)
{
	char name[30], newName[30];
	int concentration;

	printf("Please enter the name of the medicine you want to update: ");
	scanf("%s", name);

	printf("Please enter the concentration of the medicine you want to update: ");
	scanf("%d", &concentration);

	printf("Please enter the new name of the medicine: ");
	scanf("%s", newName);

	updateMedicineNameController(repository, undoArray, redoArray, 
								name, concentration, newName);
}

void updateMedicineConcentration(MedicineDynamicArray* repository, 
								OperationDynamicArray* undoArray, 
								OperationDynamicArray* redoArray)
{
	char name[30];
	int concentration, newConcentration;

	printf("Please enter the name of the medicine you want to update: ");
	scanf("%s", name);

	printf("Please enter the concentration of the medicine you want to update: ");
	scanf("%d", &concentration);

	printf("Please enter the new concentration of the medicine: ");
	scanf("%d", &newConcentration);

	updateMedicineConcentrationController(repository, undoArray, redoArray, 
										name, concentration, newConcentration);
}

void updateMedicineQuantity(MedicineDynamicArray* repository, 
							OperationDynamicArray* undoArray, 
							OperationDynamicArray* redoArray)
{
	char name[30];
	int concentration, newQuantity;

	printf("Please enter the name of the medicine you want to update: \n>");
	scanf("%s", name);

	printf("Please enter the concentration of the medicine you want to update: \n>");
	scanf("%d", &concentration);

	printf("Please enter the new quantity of the medicine: \n>");
	scanf("%d", &newQuantity);

	updateMedicineQuantityController(repository, undoArray, redoArray, 
									name, concentration, newQuantity);
}

void updateMedicinePrice(MedicineDynamicArray* repository, 
						OperationDynamicArray* undoArray, 
						OperationDynamicArray* redoArray)
{
	char name[30];
	int concentration, newPrice;

	printf("Please enter the name of the medicine you want to update: \n>");
	scanf("%s", name);

	printf("Please enter the concentration of the medicine you want to update: \n>");
	scanf("%d", &concentration);

	printf("Please enter the new price of the medicine: \n>");
	scanf("%d", &newPrice);

	updateMedicinePriceController(repository, undoArray, redoArray, 
								name, concentration, newPrice);
}

void printMedicinesByFilter(MedicineDynamicArray* repository)
{
	int typeOfFilter;
	
	printf("Would you like to: \n");
	printf("1. Search by name? \n");
	printf("2. Sort by concentration? \n> ");
	scanf("%d", &typeOfFilter);
	while(typeOfFilter != 1 && typeOfFilter != 2){
		printf("Invalid choice, please try again?\n> ");
		scanf("%d", &typeOfFilter);
	}

	if(typeOfFilter == 1){
		char searchedName[30] = "";
		printf("Please enter the text to search for in medicines' names: ");
		fgets(searchedName, sizeof(searchedName), stdin);
		fgets(searchedName, sizeof(searchedName), stdin);

		searchedName[strlen(searchedName) - 1] = '\0';

		MedicineDynamicArray* foundMedicines = 
		getMedicinesByGivenNameController(repository, searchedName);

		printMedicinesFromDynamicArray(foundMedicines);

		destroyMedicineDynamicArray(foundMedicines);
	}else{
		MedicineDynamicArray* medicinesByConcentration = 
		sortMedicinesArrayByConcentration(repository);

		printMedicinesFromDynamicArray(medicinesByConcentration);

		destroyMedicineDynamicArray(medicinesByConcentration);
	}
}

void getShortInSupplyMedicines(MedicineDynamicArray* repository)
{
	int quantity, sortAscending;

	printf("Please enter the maximum quantity you want to search for in medicines: \n>");
	scanf("%d", &quantity);

	printf("Would you like the medicines to be sorted:\n");
	printf("1. Ascending by name?\n");
	printf("2. Descending by name?\n> ");
	scanf("%d", &sortAscending);
	while(sortAscending != 1 && sortAscending != 2)
	{
		printf("Invalid option! Please try again: \n> ");
		scanf("%d", &sortAscending);
	}
	//sortAscending == 1 means the medicines will be sorted ascending 
	//sortAscending == 2 means the medicines will be sorted descending

	MedicineDynamicArray* foundMedicines = 
	getShortInSupplyMedicinesController(repository, quantity, sortAscending);

	printMedicinesFromDynamicArray(foundMedicines);

	destroyMedicineDynamicArray(foundMedicines);
}

int inputCommand()
{
	int command;
	printf("\nPlease type your option number: \n>");
	scanf("%d", &command);
	
	return command;
}

void undo(MedicineDynamicArray* repository, 
			OperationDynamicArray* undoArray, 
			OperationDynamicArray* redoArray)
{
	int result = undoController(repository, undoArray, redoArray);

	if (result == 1)
	{
		printf("Nothing to undo!\n");
		return;
	}

	printf("Operation undone successfully!\n");
}

void redo(MedicineDynamicArray* repository, 
			OperationDynamicArray* undoArray, 
			OperationDynamicArray* redoArray)
{
	int result = redoController(repository, undoArray, redoArray);

	if (result == 1)
	{
		printf("Nothing to redo!\n");
		return;
	}

	printf("Operation redone successfully!\n");
}

int interpretCommand(MedicineDynamicArray* repository, 
					OperationDynamicArray* undoArray, 
					OperationDynamicArray* redoArray,
					int userSelectedCommand)
{
	switch (userSelectedCommand)
	{
	case 1:
		printAllMedicines(repository);
		waitForNextInput();
		break;

	case 2:
		addMedicine(repository, undoArray, redoArray);
		break;

	case 3:
		deleteMedicine(repository, undoArray, redoArray);
		break;

	case 4:
		updateMedicineName(repository, undoArray, redoArray);
		break;

	case 5:
		updateMedicineConcentration(repository, undoArray, redoArray);
		break;

	case 6:
		updateMedicineQuantity(repository, undoArray, redoArray);
		break;

	case 7:
		updateMedicinePrice(repository, undoArray, redoArray);
		break;

	case 8:
		printMedicinesByFilter(repository);
		waitForNextInput();
		break;

	case 9:
		getShortInSupplyMedicines(repository);
		waitForNextInput();
		break;

	case 10:
		undo(repository, undoArray, redoArray);
		waitForNextInput();
		break;

	case 11:
		redo(repository, undoArray, redoArray);
		waitForNextInput();
		break;

	case 12:
		return 1;

	default:
		break;
	}

	return 0;
}

void runConsole(MedicineDynamicArray* repository, 
				OperationDynamicArray* undoArray, 
				OperationDynamicArray* redoArray)
{
	while (1)
	{
		printMenu();

		int userSelectedCommand = inputCommand();

		int result = interpretCommand(repository, undoArray, redoArray, 
									userSelectedCommand);

		if (result)
			break;
	}
}

