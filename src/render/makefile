FILES = window game_render
all: $(FILES)
	ld -r $(FILES:%=${BIN}/${NAME}_%.o) -o ${BIN}/${NAME}.o
$(FILES):
	$(COMPILE) -c $@.cpp  -o ${BIN}/${NAME}_$@.o
