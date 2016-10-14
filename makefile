LIB_DIR = -L/usr/libs
INC_DIR = -I/usr/include -I/home/justin/atom/sq/src

LIBS = SDL2 GL ncurses

# -D name=definition
DEFINES = -D DEBUG

COMPILE = clang++ -std=c++14 -stdlib=libstdc++ $(DEFINES) $(INC_DIR)
OBJ_LINK = $(LIBS:%=-l%) $(LIB_DIR)

BIN_FOLDER = .bin
# world render
OBJECTS= begin physics debug generation
EXECUTABLE=sq

export COMPILE


all: init $(OBJECTS) link

init:
	mkdir -p .bin

clean:
	rm -rf .bin
	rm -f sq

$(OBJECTS):
	cd src/$@ && make BIN=../../${BIN_FOLDER} NAME=$@

link:
	ld -r $(OBJECTS:%=${BIN_FOLDER}/%.o) -o ${BIN_FOLDER}/${EXECUTABLE}.o
	clang++ ${OBJ_LINK} ${BIN_FOLDER}/${EXECUTABLE}.o -o ${EXECUTABLE}

do:
	./sq
