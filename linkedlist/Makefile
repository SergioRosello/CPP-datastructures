CC=g++
CFLAGS=-Werror -Wall

DEPS = linkedlist.h 
OBJ = linkedlist.o main.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# OBJ is a variable, it simlpy substitutes
# $@ is the target name
# $^ are the prerequisites 
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clear:
	rm *.o main

run: main
	./main
