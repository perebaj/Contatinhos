all: schagend


CFLAGS = -W -m64 -Wall -std=c++1z

schagend: makedir/main.o
	g++ -o schagend makedir/main.o $(CFLAGS)
makedir/main.o: main.cpp
	g++ -o makedir/main.o -c main.cpp $(CFLAGS)


clean:
	rm -rf makedir/*.o
mproper: clean
	rm -rm schagend