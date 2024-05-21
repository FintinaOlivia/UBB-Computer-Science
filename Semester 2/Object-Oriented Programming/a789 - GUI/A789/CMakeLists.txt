cmake_minimum_required(VERSION 3.25)
project(A789)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.5.0/mingw_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(A789 main.cpp AbstractShoppingBasket/AbstractShoppingBasket.cpp AbstractShoppingBasket/AbstractShoppingBasket.h AbstractShoppingBasket/AbstractShoppingBasket.h AdminModeGUI/AdminModeGUI.cpp AdminModeGUI/AdminModeGUI.h CSVShoppingBasket/CSVShoppingBasket.cpp CSVShoppingBasket/CSVShoppingBasket.h Console/console.cpp Console/console.h Domain/domain.cpp Domain/domain.h Exceptions/Exceptions.cpp Exceptions/Exceptions.h FileRepository/FileRepository.cpp FileRepository/FileRepository.h GUI/GUI.cpp GUI/GUI.h HTMLShoppingBasket/HTMLShoppingBasket.cpp HTMLShoppingBasket/HTMLShoppingBasket.h Repository/repository.cpp Repository/repository.h Service/service.cpp Service/service.h UserModeGUI/UserModeGUI.cpp UserModeGUI/UserModeGUI.h Validation/validation.cpp Validation/validation.h Tests/test_domain.cpp Tests/test_domain.h Tests/test_repository.cpp Tests/test_repository.h Tests/test_service.cpp Tests/test_service.h Tests/test_validation.cpp Tests/test_validation.h)
target_link_libraries(A789
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
