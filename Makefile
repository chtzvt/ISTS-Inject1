CC=cc
GCC=gcc
TARGETS=bst.o

all: $(TARGETS)

bst.o: bst.c
	$(GCC) $< -o $@ -w

test: bst.o
	./bst.o 5 < input.txt
