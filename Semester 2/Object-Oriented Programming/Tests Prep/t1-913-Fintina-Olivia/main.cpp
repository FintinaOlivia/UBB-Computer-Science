//
// Created by theo on 26.04.2023.
//

#include "UI.h"

int main() {
    Repository repository;
    Controller controller(repository);
    UI ui(controller);
    ui.runApplication();
    return 0;
}