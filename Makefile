CC=g++
SOURCES=$(shell echo src/*)
OBJS=$(SOURCES:.cpp=.o)
EXECUTABLE=pasc
CFLAGS=-Iinclude -c -Wall
LDFLAGS=

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf src/*.o $(EXECUTABLE)
