# Written by Jared Weiss with help from:
# gnu.org/software/make/manual/make.html

# The compiler
CC = gcc
# Flags for the compiler
CFLAGS = -Wall -fPIC

# The name of the project
PROJ_NAME = pgm2
# DEPENDANCIES
DEPS = fns.h
# SOURCE FILES
SRCS = main.c read_classes.c display.c search.c
# OBJECT FILES
# - for each word in SRCS replace .c with .o
OBJS = $(SRCS:.c=.o)

# Upon successful compilation, notify the user
all: $(PROJ_NAME)
	@echo Compiled project!

# Executable -> changes based on object files
# comes out as:
# gcc -o pgm2 main.o read_classes.o display.o search.o
$(PROJ_NAME): $(OBJS)
	$(CC) -o $(PROJ_NAME) $(OBJS)

# generic recipe for compiling c files
# makes a .o file based on a .c file
# for example (for main.c), comes out as:
# gcc -Wall fns.h -c main.c
.c.o:
	$(CC) $(CFLAGS) $(DEPS) -c $<

.PHONY: clean
clean:
	rm -f *.o *~ $(PROJ_NAME)

# end makefile
