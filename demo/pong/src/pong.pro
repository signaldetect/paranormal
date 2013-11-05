TARGET = pong
TEMPLATE = app

CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += \
  ../../../../paranormal/include \
  ../3rdparty/SFML-2.1/include

LIBS += \
  -L"../3rdparty/SFML-2.1/lib" \
  -lsfml-system \
  -lsfml-window \
  -lsfml-graphics

HEADERS += \
  paddle.h \
  ball.h \
  game.h \
  gameeffector.h \
  window.h \
  windoweffector.h \
  fieldeffector.h \
  field.h

SOURCES += \
  main.cpp \
  paddle.cpp \
  ball.cpp \
  game.cpp \
  window.cpp \
  field.cpp
