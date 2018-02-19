#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

   pid_t spawnid = fork();
   switch(spawnid) {
      case -1: exit(1); break;
      case 0: exit(0); break;
      default: break;
   }
   printf("XYZZY\n");

   return 0;
}
