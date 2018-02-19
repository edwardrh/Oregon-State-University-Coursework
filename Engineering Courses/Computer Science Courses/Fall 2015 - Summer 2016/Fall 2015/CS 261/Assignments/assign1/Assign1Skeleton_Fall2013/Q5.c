/* CS261- Assignment 1 - Q.5*/
/* Name: Rhea Mae Edwards
 * Date: October 9th, 2015
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void studly(char* word){
     /*Convert to studly caps*/
	 int i, j;
	 for(j = 0; j < 100; j++){
		 for(i = 0; i < 100; i+=2){
			 word[i] = toUpperCase(word[i]);
	     }
		 for(i = 1; i < 100; i+=2){
			 word[i] = toLowerCase(word[i]);
		 }
		 if(word[j] == 0){
			 break;
		 }
	 }
}

int main(){
    /*Read word from the keyboard using scanf*/
    char* word;
	word = malloc(100 * sizeof(char));
	printf("Enter a Word: ");
	scanf("%s", word);
    /*Call studly*/
    studly(word);
    /*Print the new word*/
    printf("New Word: %s\n", word);
    return 0;
}
