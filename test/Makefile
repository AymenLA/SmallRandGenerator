#########################################################
#
# project name : Random Generator Lib
# date : 08-25-2022
# author : aymen.laouini@ymail.com
#
# %.o : it is the relative object file of a source file
# %.c : it is the relative source file of an object file
# $@  : it is what we find on the left of the colomn ":"
# $^  : it is what we find on the right of the colomn ":"
# $<  : it is the first item in the dependencies list
#
#########################################################
IDIR=.
CC=gcc
BINUTILS=ar
COPY=cp
MD=mkdir
REMOVE=rm
EXEC=testlibsrng

CFLAGS=-I$(IDIR)
SFLAGS=

ODIR=./obj
LIBS=-lsrng

SRCS =  $(OBJ:.o=.c)
SRCDIRS = .

HEADIRS = .

_DEPS = testfile1.h SmallRandGenerator.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o testfile1.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SRCDIRS)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(SFLAGS)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(SFLAGS)  -static -L. $(LIBS)
	chmod +x $(EXEC)

.PHONY: clean

libsrng:
	$(MD) $(ODIR)
	$(CC) -I../include/ -c ../src/SmallRandGenerator.c -o $(ODIR)/SmallRandGenerator.o
	$(BINUTILS) -rcs libsrng.a $(ODIR)/SmallRandGenerator.o
	$(COPY) ../include/SmallRandGenerator.h .

clean:
	$(REMOVE) -rf $(ODIR)/*.o
	$(REMOVE) -rf $(ODIR)
	$(REMOVE) libsrng.a SmallRandGenerator.h
	$(REMOVE) $(EXEC)
