prog.exe: Rock.o Paper.o Scissors.o Tool.o RPSGame.o play_game.o
	g++ Rock.o Paper.o Scissors.o Tool.o RPSGame.o play_game.o -o prog.exe
Rock.o: Rock.cpp
	g++ -c Rock.cpp
Paper.o: Paper.cpp
	g++ -c Paper.cpp
Scissors.o: Scissors.cpp
	g++ -c Scissors.cpp
Tool.o: Tool.cpp
	g++ -c Tool.cpp
RPSGame.o: RPSGame.cpp
	g++ -c RPSGame.cpp
play_game.o: play_game.cpp
	g++ -c play_game.cpp
clean:
	rm -f *.o *.out *.exe