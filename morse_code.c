#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>

#include <windows.h>

char *morseTable[]={
	".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
	".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", 
	"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

char normalTable[]={
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
	'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
};


int main() {
	char input[1000];
	char whatToDo;
	printf("to morse(e), from morse(d), read morse(r):\n");
	scanf("%c\n",&whatToDo);
	gets(input);
	if(whatToDo=='e'){
		for(int i=0;i<strlen(input);i++){
			if(input[i]==' '){
				printf("/ ");
			}
			else{
				printf("%s ",morseTable[tolower(input[i])-97]);
			}	    
		}
	}
	else if(whatToDo=='d'){
		char *token=strtok(input, " ");//razdvaja
		while(token != NULL){
            if(strcmp(token, "/") == 0){
                printf(" ");
            }
            else{
            	for(int i=0; i<26; i++){
                    if(strcmp(token, morseTable[i]) == 0){
                        printf("%c", normalTable[i]);
                        break;
                    }
                }
            }
                token = strtok(NULL, " ");
            }
	}
	else if(whatToDo=='r'){
		for(int i=0;i<strlen(input);i++){
		    if(input[i]=='.'){
		    	Beep(750,200);
		    }
		    else if(input[i]=='-'){
		    	Beep(750,600);
		    }
		    else if(input[i]==' '){
		    	Beep(0,500);
		    }
		}
	}

	else{printf("invalid\n");return 0;}


    return 0;
} 
