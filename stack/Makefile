all: stack main

main: 
	g++ -L./ -Wl,-rpath=./ -Wall -o stack main.cpp -lstack

stack:
	g++ -c -Wall -Werror -fPIC -shared main.cpp -o stack.o
	g++ -shared -o libstack.so stack.o

run: main
	./stack

clean:
	rm stack stack.o libstack.so
