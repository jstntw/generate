FILES = view_gen_city
all: $(FILES:%=_%)
	ld -r $(FILES:%=${BIN}/${NAME}_%.o) -o ${BIN}/${NAME}.o
$(FILES:%=_%):
	cd $(@:_%=%) && make BIN=../${BIN} NAME=${NAME}$@
