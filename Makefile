CC=g++
CPP_FILES = $(wildcard *.cpp) $(wildcard wrapper/*.cpp)
OBJ_FILES = $(CPP_FILES:.cpp=.o)
CC_FLAGS=-g -Wall
INCLUDES = -I/home/dpwrussell/Ice/home/Ice-3.3.1/include -I/home/dpwrussell/Ice/omero/OMERO.cpp-4.4.5-ice33-posix-gcc-4.6.3-64dbg/include -I.
LIBPATHS = -L/home/dpwrussell/Ice/home/Ice-3.3.1/lib64/ -L/home/dpwrussell/Ice/omero/OMERO.cpp-4.4.5-ice33-posix-gcc-4.6.3-64dbg/lib/
LIBS = -lomero_client -lIce -lIceUtil -lGlacier2

main: $(OBJ_FILES)
	$(CC) -o $@ $^ $(LIBPATHS) $(LIBS)

%.o: %.cpp
	$(CC) $(CC_FLAGS) $(INCLUDES) -c -o $@ $<



clean:
	rm -f main wrapper/*.o *.o

