#pragma once

#include "Domain.h"
#include "DynamicArray.h"

MedicineDynamicArray* createRepository();

Medicine addMedicineToRepository(MedicineDynamicArray* repository, 
                                    int id, 
                                    char* name, 
                                    int concentration, 
                                    int quantity, 
                                    int price);

Medicine deleteMedicineFromRepository(MedicineDynamicArray* repository, 
                                        char* name, 
                                        int concentration);

Medicine updateMedicineNameInRepository(MedicineDynamicArray* repository, 
                                        char* name, 
                                        int concentration, 
                                        char* newName);

Medicine updateMedicineConcentrationInRepository(MedicineDynamicArray* repository, 
                                                char* name, 
                                                int concentration, 
                                                int newConcentration);

Medicine updateMedicineQuantityInRepository(MedicineDynamicArray* repository, 
                                            char* name, 
                                            int concentration, 
                                            int newQuantity);

Medicine updateMedicinePriceInRepository(MedicineDynamicArray* repository, 
                                        char* name,
                                        int concentration, 
                                        int newPrice);

int getIndexOfSearchedMedicineFromRepository(MedicineDynamicArray* repository, 
                                            char* name, 
                                            int concentration);
                                            
TElem* getAllMedicinesFromRepository(MedicineDynamicArray* repository);