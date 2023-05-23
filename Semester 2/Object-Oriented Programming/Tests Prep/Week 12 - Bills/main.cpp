#include <QApplication>
#include "GUI/GUI.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Repository repository;
    Service service(repository);
    GUI gui(service);
    gui.show();
    return QApplication::exec();
}
