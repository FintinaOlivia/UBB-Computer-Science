#include "Domain.h"
#include "Repository.h"
#include "Controller.h"
#include "DynamicArray.h"
#include <assert.h>

void testDomain()
{
    Medicine medicine = {1, "Paracetamol", 500, 10, 10};
    assert(getMedicineId(medicine) == 1);
    assert(getMedicineConcentration(medicine) == 500);
    assert(getMedicineQuantity(medicine) == 10);
    assert(getMedicinePrice(medicine) == 10);
    //assert(strcmp(getMedicineName(medicine), "Paracetamol") == 0);
}

void testRepository(){
    MedicineDynamicArray* repository = createRepository();
    Medicine medicine = {1, "Paracetamol", 500, 10, 10};
    addMedicineToRepository(repository, 1, "Paracetamol", 500, 10, 10);
    assert(getMedicineDynamicArraySize(repository) == 1);
    assert(getMedicineId(repository->elements[0]) == 1);
    assert(getMedicineConcentration(repository->elements[0]) == 500);
    assert(getMedicineQuantity(repository->elements[0]) == 10);
    assert(getMedicinePrice(repository->elements[0]) == 10);
    //assert(strcmp(getMedicineName(repository->elements[0]), "Paracetamol") == 0);
    deleteMedicineFromRepository(repository, "Paracetamol", 500);
    assert(getMedicineDynamicArraySize(repository) == 0);
}

void testController()
{
    MedicineDynamicArray* repository = createRepository();
    OperationDynamicArray* undoArray = createOperationDynamicArray(2);
    OperationDynamicArray* redoArray = createOperationDynamicArray(2);
    initController(repository);
    addMedicineController(repository, undoArray, redoArray, 1, "Paracetamol", 500, 10, 10);
    assert(getMedicineDynamicArraySize(repository) == 1);
    addMedicineController(repository, undoArray, redoArray, 2, "Panadol", 150, 10, 20); 
    assert(getMedicineDynamicArraySize(repository) == 2);
    updateMedicineConcentrationController(repository, undoArray, redoArray, "Paracetamol", 500, 1000);
    assert(getMedicineConcentration(repository->elements[0]) == 1000);
    updateMedicineQuantityController(repository, undoArray, redoArray, "Paracetamol", 1000, 20);
    assert(getMedicineQuantity(repository->elements[0]) == 20);
    updateMedicinePriceController(repository, undoArray, redoArray, "Paracetamol", 1000, 30);
    assert(getMedicinePrice(repository->elements[0]) == 30);
    getMedicinesByGivenNameController(repository, "Paracet");
    
}

void testAll()
{
    testDomain();
    testRepository();
    testController();
}

int main()
{
    testAll();
    return 0;
}