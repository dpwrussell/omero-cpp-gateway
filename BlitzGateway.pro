TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
    blitzgateway.cpp \
    metadataservicewrapper.cpp \
    servicewrapper.cpp \
    wrapper/objectwrapper.cpp \
    wrapper/tagsetwrapper.cpp \
    wrapper/tagwrapper.cpp \
    queryservicewrapper.cpp \
    wrapper/experimenterwrapper.cpp


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../Ice/home/Ice-3.3.1/lib64/release/ -lIce -lIceUtil -lGlacier2
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../Ice/home/Ice-3.3.1/lib64/debug/ -lIce -lIceUtil -lGlacier2
else:symbian: LIBS += -lIce -lIceUtil -lGlacier2
else:unix: LIBS += -L$$PWD/../../../../Ice/home/Ice-3.3.1/lib64/ -lIce -lIceUtil -lGlacier2

INCLUDEPATH += $$PWD/../../../../Ice/home/Ice-3.3.1/include
DEPENDPATH += $$PWD/../../../../Ice/home/Ice-3.3.1/include

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../Ice/omero/OMERO.cpp-4.4.5-ice33-posix-gcc-4.6.3-64dbg/lib/release/ -lomero_client
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../Ice/omero/OMERO.cpp-4.4.5-ice33-posix-gcc-4.6.3-64dbg/lib/debug/ -lomero_client
#else:symbian: LIBS += -lomero_client
#else:unix: LIBS += -L$$PWD/../../../../Ice/omero/OMERO.cpp-4.4.5-ice33-posix-gcc-4.6.3-64dbg/lib/ -lomero_client

#INCLUDEPATH += $$PWD/../../../../Ice/omero/OMERO.cpp-4.4.5-ice33-posix-gcc-4.6.3-64dbg/include
#DEPENDPATH += $$PWD/../../../../Ice/omero/OMERO.cpp-4.4.5-ice33-posix-gcc-4.6.3-64dbg/include


#Laptop
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../Ice/omero/OMERO.cpp-4.4.4-DEV-ice33-darwin-gcc-4.2.1-64dbg/lib/release/ -lomero_client
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../Ice/omero/OMERO.cpp-4.4.4-DEV-ice33-darwin-gcc-4.2.1-64dbg/lib/debug/ -lomero_client
else:symbian: LIBS += -lomero_client
else:unix: LIBS += -L$$PWD/../../../../Ice/omero/OMERO.cpp-4.4.4-DEV-ice33-darwin-gcc-4.2.1-64dbg/lib/ -lomero_client

INCLUDEPATH += $$PWD/../../../../Ice/omero/OMERO.cpp-4.4.4-DEV-ice33-darwin-gcc-4.2.1-64dbg/include
DEPENDPATH += $$PWD/../../../../Ice/omero/OMERO.cpp-4.4.4-DEV-ice33-darwin-gcc-4.2.1-64dbg/include

HEADERS += \
    blitzgateway.h \
    metadataservicewrapper.h \
    servicewrapper.h \
    wrapper/objectwrapper.h \
    wrapper/tagsetwrapper.h \
    wrapper/tagwrapper.h \
    queryservicewrapper.h \
    wrapper/experimenterwrapper.h \
    omerowrap.h



