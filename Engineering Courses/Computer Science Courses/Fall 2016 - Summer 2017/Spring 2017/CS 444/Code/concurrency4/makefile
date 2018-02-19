concurrency4.exe: main.o barbershop.o
	g++  -lpthread main.o barbershop.o -o concurrency4.exe
main.o: main.cpp
	g++ -pthread -c main.cpp
barbershop.o: barbershop.cpp
	g++ -pthread -c barbershop.cpp
clean:
	rm -f *.o *.out *.exe
	