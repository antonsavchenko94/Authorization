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
    mail_server.cpp \
    email_address_retrieval_application.cpp \
    interactive_certificate_verifier.cpp \
    main_window.cpp \
    main.cpp \
    time_out_handler.cpp \
    tracer.cpp \
    mail_box.cpp \
    parser_of_string.cpp \
    tests/test_email_and_name.cpp \
    tests/conection_test.cpp \
    mail_viewer.cpp

HEADERS  += \
    mail_server.h \
    email_address_retrieval_application.h \
    interactive_certificate_verifier.hpp \
    main_window.h \
    time_out_handler.h \
    tracer.h \
    mail_box.h \
    parser_of_string.h \
    tests/test_email_and_name.h \
    tests/conection_test.h \
    mail_viewer.h

FORMS    += \
    mail_box.ui \
    main_window.ui \
    mail_viewer.ui

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

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../gtest-1.7.0/lib/.libs/release/ -lgtest
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../gtest-1.7.0/lib/.libs/debug/ -lgtest
else:unix: LIBS += -L$$PWD/../gtest-1.7.0/lib/.libs/ -lgtest

INCLUDEPATH += $$PWD/../gtest-1.7.0/include/
DEPENDPATH += $$PWD/../gtest-1.7.0/include/

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../gtest-1.7.0/lib/.libs/release/libgtest.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../gtest-1.7.0/lib/.libs/debug/libgtest.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../gtest-1.7.0/lib/.libs/release/gtest.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../gtest-1.7.0/lib/.libs/debug/gtest.lib
else:unix: PRE_TARGETDEPS += $$PWD/../gtest-1.7.0/lib/.libs/libgtest.a
