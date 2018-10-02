# declaring paths for source files
OUT = bin/<outputname>
SRC = $(wildcard src/*.cpp)
DEP = $(wildcard src/*.h)
OBJ = $(patsubst src/%.cpp, obj/%.o, $(SRC))
#OBJ = $(SRC:.c=.o)

# set appropriate flags for appropriate OS
# windows
ifeq ($(OS), Windows_NT)
	DETECTED_OS = $(OS)
	CC = g++
	CFLAGS = -c -IC:/mingwdev/include/SDL2
	INCLUDE = -IC:/mingwdev/include/SDL2
	LFLAGS = -LC:/mingwdev/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -o $(OUT)
# mac
else ifeq ($(shell uname -s), Darwin)
	DETECTED_OS := $(shell uname -s)
	CC = g++ -std=c11
	CFLAGS = -c -I/
	INCLUDE = -I/
	LFLAGS = -o $(OUT) 
# other unix-like
else
	DETECTED_OS := $(shell uname -s)
endif

# adhering to Clark Grubb's Makefile Style Guide phony rules
# target: dependencies
#		recipe
.PHONY: all
all: $(OUT)
	@echo "Success!"

$(OUT): $(OBJ)
	$(CC) $^ $(LFLAGS)

obj/%.o: src/%.cpp
	$(CC) $< $(INCLUDE) -o $@


# extra rules, features, etc.
.PHONY: clean
clean:
	rm -f $(OBJ) $(OUT)

.PHONY: mrclean
mrclean: 
	rm -f *.o *.exe

.PHONY: rebuild
rebuild: clean all
