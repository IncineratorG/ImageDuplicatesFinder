QT += quick
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    Services/ImageDuplicatesFinderService/IDFService.cpp \
    Services/ImageDuplicatesFinderService/Data/IDFServiceInputData.cpp \
    Services/ImageDuplicatesFinderService/Data/IDFServiceOutputData.cpp \
    Services/ImageDuplicatesFinderService/Data/IDFServiceInputDataItem.cpp \
    Services/ImageDuplicatesFinderService/Data/Path.cpp \
    Services/ImageDuplicatesFinderService/Data/Paths.cpp \
    Services/ImageDuplicatesFinderService/Data/ImageDuplicatesGroup.cpp \
    Services/ImageDuplicatesFinderService/Data/ImagesDuplicatesGroups.cpp \
    Services/ImageDuplicatesFinderService/Data/ImageHistogram.cpp \
    Services/ImageDuplicatesFinderService/Data/ImagePath.cpp \
    Services/ImageDuplicatesFinderService/Data/ImagesPaths.cpp \
    Services/ImageDuplicatesFinderService/Data/ImagesHistograms.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Services/ImageDuplicatesFinderService/IDFService.h \
    Services/ImageDuplicatesFinderService/Data/IDFServiceInputData.h \
    Services/ImageDuplicatesFinderService/Data/IDFServiceOutputData.h \
    Services/ImageDuplicatesFinderService/Data/IDFServiceInputDataItem.h \
    Services/ImageDuplicatesFinderService/Data/Path.h \
    Services/ImageDuplicatesFinderService/Data/Paths.h \
    Services/ImageDuplicatesFinderService/Data/ImageDuplicatesGroup.h \
    Services/ImageDuplicatesFinderService/Data/ImagesDuplicatesGroups.h \
    Services/ImageDuplicatesFinderService/Data/ImageHistogram.h \
    Services/ImageDuplicatesFinderService/Data/ImagePath.h \
    Services/ImageDuplicatesFinderService/Data/ImagesPaths.h \
    Services/ImageDuplicatesFinderService/Data/ImagesHistograms.h
