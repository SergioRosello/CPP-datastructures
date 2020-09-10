all: clean main

clean:
	rm -rf main

main:
	g++ -o main main.cpp -Wall -Werror -lpthread

run: all
	./main
