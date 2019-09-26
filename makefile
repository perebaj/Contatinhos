all: littlecontato

CFLAGS = -W -m64 -Wall -std=c++1z
littlecontato: makedir/main.o makedir/interpreter.o makedir/worker.o
	g++ -o littlecontato makedir/main.o  makedir/worker.o makedir/interpreter.o $(CFLAGS)
makedir/main.o: main.cpp
	g++ -o makedir/main.o -c main.cpp $(CFLAGS)
makedir/interpreter.o: interpreter.cpp
	g++ -o makedir/interpreter.o -c interpreter.cpp $(CFLAGS)
makedir/worker.o: worker.cpp
	g++ -o makedir/worker.o -c worker.cpp $(CFLAGS)


clean:
	rm -rf makedir/*.o
mrproper: clean
	rm -rm littlecontato