QT += widgets
QTPLUGIN += qjpeg
CONFIG -= app_bundle

SOURCES += \
    main.cpp \
    function.cpp \
    matrix.cpp \
    funcvector.cpp \
    linearsystemsolver.cpp \
    equationsystemsolver.cpp \
    keplerequation.cpp \
    locationdetector.cpp \
    satellitedata.cpp \
    locationshift.cpp \
    table.cpp \
    transforms.cpp

HEADERS += \
    function.h \
    matrix.h \
    funcvector.h \
    linearsystemsolver.h \
    equationsystemsolver.h \
    keplerequation.h \
    satellite.h \
    fundamental.h \
    locationdetector.h \
    satellitedata.h \
    locationshift.h \
    table.h \
    transforms.h

OTHER_FILES +=
