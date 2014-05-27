#-------------------------------------------------
#
# Project created by QtCreator 2014-05-15T13:29:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Authorization
TEMPLATE = app


SOURCES +=\
    main.cpp \
    Email_Address_Retrieval_Application.cpp \
    Main_Window.cpp \
    Show_Messages.cpp

HEADERS  += \
    Email_Address_Retrieval_Application.h \
    Interactive_Certificate_Verifier.hpp \
    Main_Window.h \
    Show_Messages.h \
    Time_Out_Handler.h \
    Tracer.h

FORMS    += mainwindow.ui \
    ShowMessages.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/local/lib/release/ -lvmime
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/local/lib/debug/ -lvmime
else:unix: LIBS += -L$$PWD/../../../../usr/local/lib/ -lvmime

INCLUDEPATH += $$PWD/../../../../usr/local/include/vmime
DEPENDPATH += $$PWD/../../../../usr/local/include/vmime

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../usr/local/lib/release/libvmime.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../usr/local/lib/debug/libvmime.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../usr/local/lib/release/vmime.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../usr/local/lib/debug/vmime.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../usr/local/lib/libvmime.a
