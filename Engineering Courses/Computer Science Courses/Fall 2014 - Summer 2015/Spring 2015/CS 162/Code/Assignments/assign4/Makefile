prog.exe: SmartRoomba.o AverageRoomba.o RandomRoomba.o Roomba.o Floor.o room.o Room.hpp.gch simulate_roomba.o
	g++ SmartRoomba.o AverageRoomba.o RandomRoomba.o Roomba.o Floor.o room.o Room.hpp simulate_roomba.o -o prog.exe
SmartRoomba.o: SmartRoomba.cpp
	g++ -c SmartRoomba.cpp
AverageRoomba.o: AverageRoomba.cpp
	g++ -c AverageRoomba.cpp
RandomRoomba.o: RandomRoomba.cpp
	g++ -c RandomRoomba.cpp
Roomba.o: Roomba.cpp
	g++ -c Roomba.cpp
Floor.o: Floor.cpp
	g++ -c Floor.cpp
room.o: room.cpp
	g++ -c room.cpp
Room.hpp.gch: Room.hpp
	g++ -g Room.hpp
simulate_roomba.o: simulate_roomba.cpp
	g++ -c simulate_roomba.cpp
clean:
	rm -f *.o *.out *.exe Room.hpp.gch