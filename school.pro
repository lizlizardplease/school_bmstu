QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adds.cpp \
    administrator.cpp \
    change.cpp \
    course.cpp \
    guest.cpp \
    main.cpp \
    mainwindow.cpp \
    money.cpp \
    pay.cpp \
    student.cpp \
    tutor.cpp

HEADERS += \
    adds.h \
    administrator.h \
    change.h \
    course.h \
    guest.h \
    mainwindow.h \
    money.h \
    pay.h \
    student.h \
    tutor.h

FORMS += \
    adds.ui \
    administrator.ui \
    change.ui \
    course.ui \
    guest.ui \
    mainwindow.ui \
    money.ui \
    pay.ui \
    student.ui \
    tutor.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
