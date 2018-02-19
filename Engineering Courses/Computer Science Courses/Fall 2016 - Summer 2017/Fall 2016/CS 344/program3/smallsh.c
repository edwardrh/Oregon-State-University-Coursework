/* ********************************************************************
 * Program: smallsh.c
 * Author: Rhea Mae Edwards
 * Date: 11/17/2016
 *
 * Overview:
 * - Will run command line instructions and return the results
 * - Will allow the rediretion of standardd input and standard output
 * - Will support both foreground and background proocesses
 * - Will support three build-in commands:
 *   - exit
 *   - cd
 *   - status
 * - Will also support comments
 *   (lines beginning wiht the character #)
 * *******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

struct child {
   int num;
   pid_t * children;
} PIDarray;

int shell_status = 0;

void init_PIDarray();
// function to push onto the array, 
// void push_PIDarray(pit_t child);
//pit_t pop_PIDarray();
void delete_PIDarray();
void line_input();
void shell_prompt();
//void ctrlC(int num);
//void cd();
//void exitc();
// function wait and check a child has died
// void dead_child(int num);
// function checks background processes,
// background(pid_t pid);

int main() {

   // initializes process id array
   init_PIDarray();
   
   //signal(SIGINT, ctrlC);
   //signal(SIGCHLD, child_died);
   
   // beginning on the analysis of the shell
   shell_prompt();

   return 0;
}

void init_PIDarray(){

   // initalizing attributes of the child structure
   PIDarray.num = 0;
   PIDarray.children = malloc(246 * sizeof(pid_t));

   // random size in creating such an array

}

/*pid_t pop_PIDarray(){

   if(PIDarray.num > 0){
      PIDarray.num--;
      return PIDarray.children[(PIDarray.num + 1)];
   }
   else {
      return 0;
   }
}*/

void delete_PIDarray(){

   // freeing up the array
   free(PIDarray.children);

}

void line_input(){

}

void shell_prompt(){
   int len = 0;
   char * input = NULL;
   size_t siz = 0;
   
   // colon symbol as prompt for each command line
   printf(":");
   fflush(stdout);
   printf("\n");
   fflush(stdout);

   /*while((len = getline(&input, &siz, stdin)) > 0){
      line_input(input, len);
      printf(":");
      fflushd(stdout);
   }*/

   // extra clean up, just in case
   delete_PIDarray();
}

/*void ctrlC(int num){
   int status;
   pid_t child;

   while(child = pop_PIDarray()){
      kill(child, SIGKILL);
      waitpid(child, &status, 0);
   }
}*/

/*void exitc(){
   ctrlC(0);
   delete_PIDarray();
   exit(0);
}*/

// create a function with the cd command cd()

// create a parsing function that does what is explained below
// fork() and exec()
// with the use of parent and child
// waiting and sleeping happening

/* ********************************************************************
 * Notes/Things to Do (i.e. Checklist):
 *
 * Specifications:
 *
 * The Prompt:
 * - : (colon symbol) as prompt for each command line
 * - Flush out output buffer each time you print
 *   - Outputting text doesn't reach screen
 *     until some kind of interactive program
 *     - Call fflush() immediately after every output text
 * 
 * General Syntax is...
 *   command [arg1 arg2 ...] [< input_file] [> output_file] [&]
 * - Items in [] are optional
 * - Assume command words seperated by spaces
 * - Special symbols >, <, and & are recongized
 *   - Must be surrounded by spaces like other words
 *
 * - If command line executed in background,
 *   last word must be &
 * - If standard input or output is to be redirected,
 *   > or < followed by filename, must appear after all arguments
 * - Input redirection can appear before or after output redirection
 * - Does not need to support quoting 
 * - Must support command lines:
 *   - Maximum Length of 2048 characters
 *   - Maximum of 512 arguments
 *   - Don't need to do any error checking on syntax
 * - Shell should allow blank lines and comments
 *   - Line begins with # is a comment line, should be ignored
 *   - Blank line (without any commands), should do nothing
 *     - Shell should just re-prompt for another command
 *
 * Command Execution:
 * - Will use fork(), exec(), and waitpid() to execute commmands
 * - From conceptual perspective, consider setting up shell to run like..
 *   - Let the parent process (your shell) continue running
 *   - Whenever a non-built-in command is received,
 *     have parent fork() off a child
 *     - This child does any input/output redirection
 *       before running exec() on the command given
 *
 * Note: When doing redirection, that after using dup2() 
 * 	 to set up the redirection, 
 * 	 the redirection symbol and redirection destination/source
 * 	 are NOT passed into following exec command
 * 	 (i.e. if command given ls > more, do redirection,
 * 	       then simly pass ls into exec())
 *
 * Note: exec() will fail.
 * 	 Return reason why.
 * 	 - If told execute something can't do 
 * 	   (like a program doesn't exist),
 * 	   shell should indicate to user command couldn't be executed,
 * 	   and set value retrieved by built-in status commands to 1
 *
 * - PATH variable to look for non-built-in commands,
 *   should allow shell scripts to be executed
 *   - If command fails because shell couldn't find command to run,
 *     shell print out error message,
 *     set exit status to 1
 * - After fork(), before exec(),
 *   must do input/output redirection with dup2()
 *   - Redirected input file --> read only,
 *     if shell cannot open, print error message, and
 *     			     exit statts to 1
 *   - Redirected output file --> write only,
 *     be truncated if already exists, or 
 *        created if doesn't exist
 *   - If shell cannot open output file,
 *     print error message, and
 *     set exit status to 1
 *
 * Background and Foreground:
 * - Shell should wait() for completion of foreground commands,
 *   					   (commands without &)
 *   before prompting next command
 *   - Parent shell does NOT return command line access and control to user,
 *     until child terminates
 *   - Recommended parent simly calls waitpid() on child
 * - Shell will not wait for background commands to complete
 *   - Parent returns command line access and control to user,
 *     immediately after forking off child
 *     - Parent shell need periodically checks
 *       background child process to complete
 *       (with waitpid(...NOHANG...))
 *       - So get cleaned up as shell continues to run nd process commands
 *   - Consider storing PIDs of non-completed background processes
 *     in array, so can be periodically checked for
 *     OR
 *     - Alternatively, may use signal handler to immediately
 *       wait() for child processes that terminate
 *   - When to print out background processes have completed,
 *     just BEFORE command line access and control 
 *     are returned to the user, every time that happens
 *   - Should have standard input redirected from 
 *     /dev/null if user didn't specify some other file
 *    		 to take standard input from
 *   **Background commands should not send standard output
 *     to the screen
 * - Shell print process id of background process when it begins
 *   when terminates, message showing/printing process id
 * 				     	       exit status
 *   - Should check any background process completed,
 *     just before prompt new command, then print this message
 *     **So will not appear during other running commands,
 *       through user have to wait until complete some other command
 *       to see these messages
 *       - Probably want use waitpid() to check
 *         completed background processes
 *
 * Signals:
 * - CNTL-C command sends SIGINT signal
 *   to your parent process and all children at the same time
 *   - Make sure SIGINT doesn't terminate your shell,
 *     only forground command if one is running
 *     - Have create appropriate signal handlers wiht sigcaption()
 *     - Parent should not attempt to terminate foreground
 *       child process when SIGINT signal recieved
 *       - Instead foreground child (if any)
 *         must terminate itself
 * - If child foreground process killed by signal,
 *   parent must print out number of the signal,
 *   before prompting user next command
 * - Background process not terminated by SIGINT signal
 *   - It'll terminate themselves,
 *   	     continue running, or
 *   	     terminated when shell exits
 * 
 * Built-In Commands:
 * - Shell supports 3 built-in commands:
 *   - exit
 *   - cd
 *   - status
 *     - Don't need to support input/output redirection, or
 *   			       have to set an exit status
 *   - Ones shell has to handle itself
 *     (others simply passed on to a member of exec() family
 *	  of function (which member up to you))
 * - exit command exits shell
 *   - Takes no arguments
 *   - Must kill any other processes or jobs before terminating
 *     itself (shell)
 * - cd command changes directories
 *   - By itself, changes in HOME environment variable
 *   - Can also take one argument
 *   		     (the path of directory changing to)
 *   Note: Is a working directory.
 * 	   When smallsh exits,
 * 	   the pwd will be original pwd when smallsh was launched
 *   - Supports both absolute and relative paths
 * - Status command prints out either exit status, or
 *   				      the terminating signal
 *   				      of last foreground process
 *   				      (not both)
 *
 * Example:
 * 
 * $ smallsh
 * : ls
 * junk  smallsh  smallsh.c
 * : ls > junk
 *  : status
 *  exit value 0
 * : cat junk
 * junk
 * smallsh
 * smallsh.c
 * : wc < junk
 * 	  3	3     23
 * : test -f badfile
 * : status
 * exit value 1
 * : wc < badfile
 * cannot open badfile for input
 * : status
 * exit value 1
 * : badfile
 * badfile: no such file or directory
 * : sleep 5
 * ^Cterminated by signal 2
 * : status
 * terminated by signal 2
 * : sleep 15 &
 * background pid is 4923
 * : ps
 * 	PID TTY		TIME CMD
 *     4923 pts/4	0:00 sleep
 *     4564 pts/4	0:03 tcsh-6.0
 *     4867 pts/4	1:32 smallsh
 * :
 * :
 * : # that was a blank command line, this is a comment line
 * background pid 4923 is done: exit value 0
 * : # the background sleep finally finished
 * : sleep 30 &
 * background pid is 4941
 * : kill -15 4941
 * background pid 4941 is done: terminated by signal 15
 * : pwd
 * /nfs/stak/faculty/b/brewsteb/CS344/prog3
 * : cd
 * : pwd
 * /nfs/stak/faculty/b/brewsteb
 * : cd CS344
 * : pwd
 * /nfs/stak/faculty/b/brewsteb/CS344
 * : exit
 * $
 * 
 * Hints:
 * - Program built-in commands first,
 *   then fork(), exec(), and waitpid() specifications
 * - Don't forget use fflush(stdout),
 *   may help before accept input
 * Re-Entrancy:
 * - Important when considering signal handlers
 *   jumping in execution that causes problems with certian functions
 * - Note printf() family of functions is NOT re-entrant
 *   - In signal handlers, when outputting text,
 *   			   use other output functions  
 * - If see ^M characters:
 *   $ dos2unix bustedFile
 * 
 * What to Submit:
 * - Single zip file:
 *   - File called readme.txt
 *   		   (instruction how to compile code)
 *     - Can compile however you want
 * - Make sure it compiles!
 *   - Especially ls, status, and exit
 * ********************************************************************/
