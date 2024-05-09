QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    additem.cpp \
    admin.cpp \
    adminfunctions.cpp \
    checkout.cpp \
    final.cpp \
    inventory.cpp \
    main.cpp \
    login.cpp \
    newuserlogin.cpp \
    productmanagement.cpp \
    shopping.cpp \
    userfunctions.cpp \
    usermanagement.cpp

HEADERS += \
    additem.h \
    admin.h \
    adminfunctions.h \
    checkout.h \
    final.h \
    inventory.h \
    item.h \
    login.h \
    newuserlogin.h \
    productmanagement.h \
    shopping.h \
    userfunctions.h \
    usermanagement.h

FORMS += \
    additem.ui \
    admin.ui \
    adminfunctions.ui \
    checkout.ui \
    final.ui \
    inventory.ui \
    login.ui \
    newuserlogin.ui \
    productmanagement.ui \
    shopping.ui \
    userfunctions.ui \
    usermanagement.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../OneDrive/Documents/admininfo.docx \
    admindatalol \
    adminuserhandling \
    itemsmenu \
    userdata

RESOURCES += \
    data.qrc \
    pic.qrc
