OBJS=src/world.cpp src/screen.cpp src/controller.cpp src/tvtennis.cpp

CC=clang++-9

COMPILER_FLAGS=-I/usr/include -Iinclude

LINKER_FLAGS=-L/usr/lib/x86_64-linux-gnu -lSDL2 -lSDL2main -Xlinker

OBJ_NAME=build/tvtennis

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o$(OBJ_NAME)

clean :
	$(RM) build/*
	$(RM) obj/*
