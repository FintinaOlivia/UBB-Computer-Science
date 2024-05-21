#include <QApplication>

#include "AdminModeGUI/AdminModeGUI.h"
#include "UserModeGUI/UserModeGUI.h"
#include "FileRepository/FileRepository.h"
#include "GUI/GUI.h"
#include "Tests/test_domain.h"
#include "Tests/test_repository.h"
#include "Tests/test_service.h"
#include "Tests/test_validation.h"
#include "Console/console.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    FileRepository repo(R"(C:\Users\Th\CLionProjects\A789\text.txt)");
    Repository UserRepo;
    Service service(repo, UserRepo);

    Test_Domain testDomain;
    testDomain.TestAllDomain();
    Test_Repository testRepository;
    testRepository.TestAllRepository();
    Test_Validation testValidation;
    testValidation.TestAllValidation();

//    Console console{service};
//    console.Start();

    GUI gui{service};
    gui.setStyleSheet("QMainWindow {background: 'magenta';}");
    gui.show();

    return a.exec();

}
