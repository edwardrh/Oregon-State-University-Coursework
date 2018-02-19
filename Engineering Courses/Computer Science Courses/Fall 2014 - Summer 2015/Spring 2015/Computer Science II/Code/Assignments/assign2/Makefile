prog.exe: movie.o netflix.o main.o
	g++ movie.o netflix.o main.o -o prog.exe
movie.o: movie.cpp
	g++ -c movie.cpp
netflix.o: netflix.cpp
	g++ -c netflix.cpp
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm -f *.o *.out *.exe
