#include "UI.h"
#include "Repository.h"
#include "Controller.h"
#include "TestAll.h"

int main()
{
    testDomain();
    testRepository();
    testController();
    {
        Controller controller;
        Repository basket_repository("basket.txt");
        Controller basket_controller(basket_repository);

        UI ui(controller, basket_controller);
        //ui.runApplication();
    }
    return 0;
}