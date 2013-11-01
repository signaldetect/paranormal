TARGET = pong
TEMPLATE = app
CONFIG -= qt

#HEADERS += \
#  paddle.h \
#  ball.h

SOURCES += \
  main.cpp
#  paddle.cpp \
#  ball.cpp

INCLUDEPATH += \
  ../../../../paranormal \
  ../3rdparty/SFML-2.1/include

LIBS += \
  -L"../3rdparty/SFML-2.1/lib" \
  -lsfml-system \
  -lsfml-window \
  -lsfml-graphics
