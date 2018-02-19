str.exe: connect_four.o play_cf.o
	g++ connect_four.o play_cf.o -o str.exe
connect_four.o: connect_four.cpp
	g++ -c connect_four.cpp
play_cf.o: play_cf.cpp
	g++ -c play_cf.cpp
clean:
	rm -f *.o *.out *.exe
