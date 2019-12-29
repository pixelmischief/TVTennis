all : ./src/tvtennis.cpp
	clang ./src/tvtennis.cpp -Iinclude -Llib -Xlinker /subsystem:console -o build/tvtennis.exe

clean :
	$(RM) ./build/*.*
	$(RM) ./obj/*.*
