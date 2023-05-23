#include <QApplication>
#include <QPushButton>
#include "Repository/Repository.h"
#include "Controller/Controller.h"
#include "GUI/GUI.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    test_getNumberOfCarsByManufacturer();
    Repository repository;
    Controller controller(repository);
    GUI gui(controller);
    gui.show();
    return QApplication::exec();
}
