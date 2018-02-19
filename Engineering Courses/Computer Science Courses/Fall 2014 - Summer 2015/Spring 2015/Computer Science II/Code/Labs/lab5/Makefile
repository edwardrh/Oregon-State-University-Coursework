prog.exe: car.o motorcycle.o skateboard.o bike.o vehicle.o Date.o main.o
	g++ car.o motorcycle.o skateboard.o bike.o vehicle.o Date.o main.o -o prog.exe
car.o: car.cpp
	g++ -c car.cpp
motorcycle.o: motorcycle.cpp
	g++ -c motorcycle.cpp
skateboard.o: skateboard.cpp
	g++ -c skateboard.cpp
bike.o: bike.cpp
	g++ -c bike.cpp
vehicle.o: vehicle.cpp
	g++ -c vehicle.cpp
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm -f *.o *.out *.exe