CC=g++
CFLAGS=-c -Wall -std=c++11
EXECUTABLE=fastcraft
LDFLAGS=-lGL -lGLU -lglut -lsfml-graphics -lsfml-window -lsfml-system -std=c++11
SOURCES=main.cpp game.cpp fps.cpp
OBJECTS=$(SOURCES:.cpp=.o)

all:
	$(CC) -c $(SOURCES) $(CFLAGS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE) $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf demo