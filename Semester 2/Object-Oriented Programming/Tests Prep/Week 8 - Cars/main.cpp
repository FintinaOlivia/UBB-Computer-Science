#include <iostream>
#include "UI.h"

int main() {
    Repository repository;
    Controller controller(repository);
    UI ui(controller);
    ui.run();
    return 0;
}
