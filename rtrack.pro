# Version
VERSION='0.0.1'
VERSTR='\\"$${VERSION}\\"'
DEFINES += PROJECT_VERSION=\"$${VERSTR}\"

folder_01.source = qml/rtrack
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

QML_IMPORT_PATH =

# Symbian
symbian {
    TARGET.UID3 = 0xE06CAE3C
    #TARGET.CAPABILITY += NetworkServices

    # Sensor
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000

    CONFIG += qt-components
}

CONFIG += mobility qdeclarative-boostable
MOBILITY += sensors

SOURCES += main.cpp \
    src/ctrack.cpp \
    src/caccelerometerfilter.cpp \
    src/caccelerometer.cpp \
    src/crotation.cpp \
    src/crotationfilter.cpp

# Please do not modify the following two lines. Required for deployment.
include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()

OTHER_FILES += \
    qtc_packaging/debian_harmattan/rules \
    qtc_packaging/debian_harmattan/README \
    qtc_packaging/debian_harmattan/manifest.aegis \
    qtc_packaging/debian_harmattan/copyright \
    qtc_packaging/debian_harmattan/control \
    qtc_packaging/debian_harmattan/compat \
    qtc_packaging/debian_harmattan/changelog

HEADERS += \
    src/ctrack.h \
    src/caccelerometerfilter.h \
    src/caccelerometer.h \
    src/crotation.h \
    src/crotationfilter.h
