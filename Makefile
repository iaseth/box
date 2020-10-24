AMP = @

CC = ${AMP}gcc
CC_FLAGS = -fPIC -Wall

INCLUDE_FLAG = -Iinclude
LINK_FLAG = -lbox

AR = ${AMP}ar
RM = ${AMP}rm -f

BOX_NAMES = 
BOX_NAMES += box
BOX_NAMES += box_types
BOX_NAMES += box_owner
BOX_NAMES += box_box
BOX_NAMES += box_macros

BOX_OBJ_NAMES = ${addsuffix .o, ${BOX_NAMES}}
BOX_OBJS = ${addprefix build/, ${BOX_OBJ_NAMES}}

BOX_STATIC_LIB = build/libbox.a
BOX_DYNAMIC_LIB = build/libbox.so

MAIN_SRC = src/main.c
MAIN_OBJ = build/main.o

BIN = build/box

default: clean lib ${BIN}

lib: ${BOX_STATIC_LIB} ${BOX_DYNAMIC_LIB}

debug:
	${eval AMP := }

${BIN}: ${MAIN_OBJ} ${BOX_OBJS}
	${CC} $^ -o $@

${MAIN_OBJ}: ${MAIN_SRC}
	${CC} -c ${CC_FLAGS} $< -o $@ ${INCLUDE_FLAG}

${BOX_OBJS}: build/%.o: lib/%.c include/%.h
	${CC} -c ${CC_FLAGS} $< -o $@ ${INCLUDE_FLAG}

${BOX_STATIC_LIB}: ${BOX_OBJS}
	${AR} rcs $@ $^

${BOX_DYNAMIC_LIB}: ${BOX_OBJS}
	${CC} -shared $^ -o $@

redo: clean default

run: ${BIN}
	@${BIN}

move:
	sudo cp ${BIN} /usr/bin

clean:
	${RM} ${BIN}
	${RM} ${MAIN_OBJ}
	${RM} ${BOX_OBJS}
	${RM} ${BOX_STATIC_LIB}
	${RM} ${BOX_DYNAMIC_LIB}


