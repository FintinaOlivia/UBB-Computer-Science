#include "UI.h"
#include "Tests.h"

int main() {
    Tests::testAddBill();
    Tests::testTotalSumOfBills();
    Repository repository;
    Controller controller(repository);
    UI ui(controller);
    ui.startApplication();
    return 0;
}
