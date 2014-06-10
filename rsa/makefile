# Not used for a while
# LDIR =../lib
# LIBS=-lm

# Program name
PROGRAM_NAME=rsa

# Some directories
INCLUDE_DIR=.
INCLUDE_NTL=lib/ntl-6.1.0/include
LIB_NTL=lib/lib/libntl.a
OBJECT_DIR=obj
BIN_DIR=bin

CC=g++
CFLAGS=-I$(INCLUDE_DIR) -I$(INCLUDE_NTL)

_DEPS = RSA.h
DEPS = $(patsubst %,$(INCLUDE_DIR)/%,$(_DEPS))

_OBJ = tests.o main.o RSA.o RSA_gcd.o RSA_xgcd.o RSA_generateCipherKey.o RSA_generateDecipherKey.o \
			RSA_getBigPrime.o RSA_cipher.o RSA_decipher.o RSA_isPrime.o RSA_totient.o RSA_bigRandom.o \
			RSA_bigPower.o
OBJ = $(patsubst %,$(OBJECT_DIR)/%,$(_OBJ))

testOnly=obj/main.o
mainOnly=obj/tests.o

$(OBJECT_DIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(filter-out $(mainOnly), $(OBJ)) $(LIB_NTL)
	$(CC) -o $(BIN_DIR)/$(PROGRAM_NAME) $^ $(LIB_NTL) $(CFLAGS)

debug: $(filter-out $(mainOnly), $(OBJ)) $(LIB_NTL)
	$(CC) -o $(BIN_DIR)/$(PROGRAM_NAME) $^ $(LIB_NTL) $(CFLAGS) -g

tests: $(filter-out $(testOnly), $(OBJ)) $(LIB_NTL)
	$(CC) -o $(BIN_DIR)/$@ $^ $(CFLAGS) $(LIBS)

$(LIB_NTL):
	cd lib/ntl-6.1.0/src && ./configure PREFIX=../.. && make && make install

.PHONY: clean

clean:
	rm -f $(OBJECT_DIR)/*.o *~ $(BIN_DIR)/* $(INCLUDE_DIR)/*~ 

cleanNtl:
	cd lib/ntl-6.1.0/src && make uninstall && make clean
