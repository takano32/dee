# Makefile

UNAME=$(shell uname)
PREFIX=/usr/local/

CC=gcc
CFLAGS= -Wall -O0 -g `sdl-config --cflags` `freetype-config --cflags` -msse2 -flax-vector-conversions -DPREFIX=\"$(PREFIX)\"
OBJECTS=rom.o nes.o M6502.o const.o util.o main.o

SYS_LIBS=-lm -ldl

ifeq ($(UNAME),Darwin)
SYS_LIBS=
endif

LIBS= $(SYS_LIBS) -lSDL `sdl-config --libs` `freetype-config --libs` -lSDL_image $(FUSE_LIBS) 

COBJ=$(CC) -std=c99 $(CFLAGS) $(DEFINES) $(INCLUDEDIRS) -c
C90OBJ=$(CC) -std=c99 $(CFLAGS) $(DEFINES) $(INCLUDEDIRS) -c
CAPP=$(CC) -std=c99 $(CFLAGS) $(DEFINES) $(INCLUDEDIRS) $(OBJECTS) $(LIBS)

all: dee
clean:
	rm -f *.o
	rm -f dee

dee: Makefile $(OBJECTS)
	$(CAPP) -o dee

main.o: Makefile main.c const.h nes.h rom.h
	$(COBJ) main.c

const.o: Makefile const.c const.h
	$(COBJ) const.c

dasm.o: Makefile dasm.c
	$(COBJ) dasm.c

rom.o: Makefile rom.c rom.h
	$(COBJ) rom.c

nes.o: Makefile nes.c nes.h
	$(COBJ) nes.c

M6502.o: Makefile M6502.c M6502.h Codes.h Tables.h
	$(COBJ) M6502.c
