CC = g++
CFLAGS = -Wall -shared -fPIC
LIBRARY = libraycasting.so
OBJECTS = raycasting.o
HEADERS = src/raycasting.h
SOURCES = src/raycasting.cpp

all: $(LIBRARY)

$(LIBRARY): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJECTS): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -c $(SOURCES) -o $@

clean:
	rm -f $(OBJECTS) $(LIBRARY)

