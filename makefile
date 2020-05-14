#OBJS=src/world.cpp src/screen.cpp src/controller.cpp src/game.cpp src/tvtennis.cpp
OBJS=src/lab_events.cpp

CC=clang++

INCLUDE_PATHS=-Ih:/factory/include -I./include

LIBRARY_PATHS=-Lh:/factory/library

#COMPILER_FLAGS=-w -Wl,-subsystem,windows
COMPILER_FLAGS=

#LINKER_FLAGS=-lshell32 -lSDL2main -lSDL2 -Xlinker /subsystem:console
LINKER_FLAGS=-lshell32 -Xlinker /subsystem:console

#OBJ_NAME=build/tvtennis.exe
OBJ_NAME=build/lab_events.exe

all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o$(OBJ_NAME)

clean :
	$(RM) build/*
	$(RM) obj/*
