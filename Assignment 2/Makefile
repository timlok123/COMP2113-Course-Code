FLAGS = g++ -pedantic-errors -std=c++11

dsboh.o: d2boh.cpp d2boh.h
	$(FLAGS) -c d2boh.cpp

main.o: main.cpp d2boh.h
	$(FLAGS) -c main.cpp

main: main.o d2boh.o
	$(FLAGS) $^ -o main

clean:
	rm -f main main.o d2boh.o 

.PHONY:clean



