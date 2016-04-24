CC=g++
SOURCES=$(shell echo src/*.cpp)
OBJS=$(SOURCES:.cpp=.o)
EXECUTABLE=pasc
CFLAGS=-Iinclude -c -g -DRUN_TESTS
LDFLAGS=

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf src/*.o $(EXECUTABLE)
