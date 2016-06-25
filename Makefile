CC=g++
SOURCES=$(shell echo src/*.cpp)
OBJS=$(SOURCES:.cpp=.o)
MAIN=src/main.cpp
MAINOBJ=src/main.o
EXECUTABLE=pasc
CFLAGS=-Iinclude -c -g 
LDFLAGS=

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

test: $(OBJS)
	rm $(MAINOBJ)
	$(CC) $(CFLAGS) $(MAIN) -DRUN_TESTS  -o $(MAINOBJ)
	$(CC) $(LDFLAGS) $(OBJS) -o $(EXECUTABLE)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf src/*.o $(EXECUTABLE)
