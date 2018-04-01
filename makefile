# vim:noexpandtab:ts=8

SHELL=/bin/sh

default: \
	trim

makeo: \
makefile makemake
	./makemake o > makeo
	chmod +x makeo

makex: \
makefile makemake
	./makemake x > makex
	chmod +x makex

maketargets: \
makefile makemake
	./makemake targets > maketargets

clean: \
maketargets
	rm -f `cat maketargets`

trim.o: \
makeo trim.c
	./makeo trim

trim: \
makex trim.o
	./makex trim
