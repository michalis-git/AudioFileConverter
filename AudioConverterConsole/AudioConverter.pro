QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

#DEPENDPATH += . ../libConverter
#INCLUDEPATH += ../libConverter
#LIBS += -L../libConverter/debug -libConverter
#DEPENDPATH += . ../testLib
#INCLUDEPATH += ../testLib
#LIBS += -L../testLib/debug -ltestLib
#LIBS += ../converterLib


#LIBS += -lconverter

#LIBS += -L/libs/converter/lib

#INCLUDEPATH += /libs/converter/include/


#LIBS += -L$$PWD/ -lsharedlib

#DEPENDPATH += . ../converterLib
#INCLUDEPATH += ../converterLib
#LIBS += -L../converterLib/debug -lconverterLib
#DEPENDPATH += . ../libConverter
#INCLUDEPATH += ../libConverter
#LIBS += -L../libConverter/debug -llibConverter

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../build-Converter-Desktop_Qt_5_15_2_clang_64bit-Debug/release/ -lConverter
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../build-Converter-Desktop_Qt_5_15_2_clang_64bit-Debug/debug/ -lConverter
else:unix: LIBS += -L$$PWD/../../build-Converter-Desktop_Qt_5_15_2_clang_64bit-Debug/ -lConverter

INCLUDEPATH += $$PWD/../../build-Converter-Desktop_Qt_5_15_2_clang_64bit-Debug
DEPENDPATH += $$PWD/../../build-Converter-Desktop_Qt_5_15_2_clang_64bit-Debug
