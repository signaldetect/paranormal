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
  $$files(contrib/*.h) \
  $$files(proc/*.h) \
  $$files(view/*.h) \
  $$files(world/geom/*.h) \
  $$files(world/*.h) \
  $$files(*.h)

SOURCES += \
  $$files(contrib/*.cpp) \
  $$files(proc/*.cpp) \
  $$files(view/*.cpp) \
  $$files(world/geom/*.cpp) \
  $$files(world/*.cpp) \
  $$files(*.cpp)
