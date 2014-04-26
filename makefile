# Not used for a while
# LDIR =../lib
# LIBS=-lm

# Program name
PROGRAM_NAME=acg

# Some directories
INCLUDE_DIR=.
OBJECT_DIR=obj
BIN_DIR=bin

CC=gcc
CFLAGS=-I$(INCLUDE_DIR)

_DEPS = functions.h
DEPS = $(patsubst %,$(INCLUDE_DIR)/%,$(_DEPS))

_OBJ = tests.o main.o functions.o \
		substitutionCipher.o transpositionCipher.o productCipher.o
OBJ = $(patsubst %,$(OBJECT_DIR)/%,$(_OBJ))

testOnly=obj/main.o
mainOnly=obj/tests.o

$(OBJECT_DIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(filter-out $(mainOnly), $(OBJ))
	$(CC) -o $(BIN_DIR)/$(PROGRAM_NAME) $^ $(CFLAGS) $(LIBS)

tests: $(filter-out $(testOnly), $(OBJ))
	$(CC) -o $(BIN_DIR)/$@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(OBJECT_DIR)/*.o *~ $(BIN_DIR)/* $(INCLUDE_DIR)/*~ 