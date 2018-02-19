/* *************************************************************
 * Program: edwardrh.adventure.c
 * Author: Rhea Mae Edwards
 * Date: 10/27/2016
 *
 * Overview:
 * - Program will first create series of files
 *   - That'll hold descripton of rooms and 
 *     how they're connected
 * - Then offer player an interface for playing
 * - Player begins in "starting room"
 *   - Then win automatically upon entering "ending room"
 * - Player can also enter command, 
 *   then returns current time
 *   (This functionality utilizes mutexes and multithreading)
 * - Finally, program exits, then displays path taken by player
 * ************************************************************/

#include <stdio.h>
#include <pthread.h>

int main(){

   /*
   // Create all connections in graph
   while(IsGraphFull() == false){
      AddRandomConnection();
   }
   */

   /*
   // Parsing through created files
   sscanf(line, "ROOM NAME: %s", room_name);
   sscanf(line, "CONNECTION 1: %s", connection_array[0]);
   sscanf(line, "CONNECTION 2: %s", connection_array[1]);
   sscanf(line, "CONNECTION 3: %s", connection_array[2]);
   sscanf(line, "CONNECTION 4: %s", connection_array[3]);
   sscanf(line, "CONNECTION 5: %s", connection_array[4]);
   sscanf(line, "CONNECTION 6: %s", connection_array[5]);
   */

   printf("\nCURRENT LOCATION: \n");
   printf("POSSIBLE CONNECTIONS: \n");
   printf("WHERE TO? >\n");

   /*
   // When an exact room is not entered
   printf("\nHUH? I DON'T UNDERSTAND THAT ROOM. TRY AGAIN.\n");
   */

   // Once player reaches End Room
   printf("\nYOU HAVE FOUND THE END ROOM. CONGRATULATIONS!\n");
   printf("YOU TOOK # STEPS. YOUR PATH TO VITORY WAS:\n\n");
   // Then pathway listed out here afterwards
   
   /*
   // Format when time is called
   printf("\n00:00am, Day of Week, Month Day, Year\n");
   */

   return 0;
}

/*
// Retuns true if all rooms have 3 to 6 outbound connections,
// false otherwise
bool IsGraphFull(){

}

// Adds a random, valid outbound connection from a Room to another Room
void AddRandomConnection(){
   Room A;
   Room B;
   // Or however you track that messing with the connections for two rooms

   while(true){
      A = GetRandomRoom();
      if(CanAddConnectionFrom(A) == true){
	 break;
      }
   }

   do{
      B = GetRandomRoom();
   }
   while(CanAddConnectionFrom(B) == false || IsSameRoom(A, B) == true)

   ConnectRoom(A, B);
   ConnectRoom(B, A);  
}

// Returns a random Room, does NOT validate if connection can be added
Room GetRandomRoom(){

}

// Returns true if a connection can be added from Room x,
// flase otherwise
bool CanAddConnectionFrom(Room x){

}

// Connects Rooms x and y together,
// does not check if this connection is valid
void ConnectRoom(Room x, Room y){

}

// Returns true if Room x and y are the same Room,
// false otherwise
bool IsSameRoom(Room x, Room y){

}
*/

/**************************************************************
 * Things to Do (i.e. Checklist):
 * 
 * 1) Generate 7 different room files
 *    - In directory edwardrh.rooms.<process.id>
 *      - "edwardrh.rooms." [hard-coded]
 * 
 * 2) Each Room has... [struct]
 *    - Room Name
 *    - At least 3 outgoing connections (at most 6)
 *      - These are randomly generated
 *      - Possibly use double-linked list??
 *    - Room Type
 *    
 *    File of Each Room Format:
 *    ROOM NAME: <room name>
 *    CONNECTION 1: <room name>
 *    ... // Additional Room Connections
 *    ROOM TYPE: <room type>
 *
 * 3) Choose list of ten different Room Names [hard-coded]
 *    - 7 of the 10 will be used each game
 *    - START_ROOM, END_ROOM, MID_ROOM
 *      - Randomly assigned rooms get these start/end
 *        (Randomization procedure not actually graded..)
 *
 * 4) After rooms are generated, present interface to player
 *    - Room data must be read back in program from files
 *    - Either can be read all immediately after writing,
 *      or read as needed throughout game
 *    
 *    Interface:
 *    - List where plater currently is
 *    - List possible connections can be followed
 *    - Then have a prompt
 *
 *    Format:
 *    CURRENT LOCATION: XYZZY // room name
 *    POSSIBLE CONECTIONS: PLOVER, Dungeon, twisty. // room name(s)
 *    WHERE TO? > [user input]
 *    
 *    // Cursor should be placed after > sign
 *    // colons (:), commas (,), and period (.) are all required
 *
 *    a) When exact name entered, hits return,
 *       program writes new line and continues running like before
 *    b) Enters anything else,
 *       program return error line
 *       "HUH? I DON'T UNDERSTAND THAT ROOM. TRY AGAIN"
 *       then repeats current location as prompt
 *       - An incorrect location doesn't increment
 *         path history/step count
 *
 * 5) Once read End Room, program indicated have been reached
 *    - Should print out path to get there,
 *                       number of steps,
 *                       congratulatory message
 *
 *    Format:
 *    YOU HAVE FOUND THE END ROOM. CONGRATULATIONS!
 *    YOU TOOK <#> STEPS. YOUR PATH TO VICTORY WAS:
 *    twisty // room name
 *    Dungron // room name
 *    ... // any more additional rooms
 *    
 * 6) When program exits,
 *    set error code to 0
 *    leave the rooms directory in place (so it can be examined)
 *
 * 7) If you use temporary files,
 *    leave in directory you create above
 *     - Don't leave any behind when program is finished
 *       (Early termination is not graded..)
 *
 * Time Keeping:
 * - Program must be able to return current time of day,
 *   utilizing a second thread and mutex(es)
 * - Use classic pthread library
 *
 * 1) When player types command "time", hits enter,
 *    second thread writes current time and file called 
 *    "currentTime.txt"
 *
 *    Format:
 *    WHERE TO? > time 
 *
 *    1:03pm, Tuesday, September 13, 2016
 *
 *    WHERE TO? >
 *
 * 2) Then main thread reads time value from file,
 *                     then prints out to user
 *    - Can either (new time keeping thread)
 *      - be created and destroyed as part of this "time" command
 *      - keep running during execution of main program,
 *        merely invoke need of command
 *    - In any event, at least one mutex must aid in
 *      controlling execution between two threads
 *
 * Additional Knowledge:
 * - Must figure how C reads input from keyboard,
 *   and pause until input is received
 *   - fgets() function (recommended)
 * - Becoming proficient reading and writing files:
 *   - May use older open, close, lseek methods, or...
 *   - STDIO standrad input library methods 
 *     fopen, fclose, and fseek
 * - If see ^M character(s):
 *   $dos2unix bustedFile
 * **********************************************************/
