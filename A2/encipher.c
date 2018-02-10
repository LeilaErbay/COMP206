#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//cipher function: encripts char entered with key provided
char cipher (char input, int key) {
char c =input;
       if (input == 32){
                 c = 32;
        }
	//upper case encripting
       if (input >= 65 && input<=90){
                c = c - key;
		//conditions if encripted letter is out of uppercase letter bounds
                if (c < 65) {
                	c = c + 26;
		if (c > 90) {
			c = c - 26;
                }
        }
	//lower case encripting
        else if (c >= 97 && c <= 122) {
                c = c - key;
		//conditions if encripted letter is out of lowercase letter bounds
                if (c > 122){
                         c = c - 26;
                }
                if (c < 97) {
                        c = c + 26;
                }
	}  
      }
return c;
}

int main(int argc, char *argv[]){
	//open file entered by user
	FILE *file =fopen(argv[1],"r");
	//if file NULL tell user
	if (file=='\0'){
 		printf("Please enter an existing file name");
 		exit(0);
	}

	else {
	//read file
	char c;
	int count=0;
	int key=atoi(argv[2]);

	//read chars of file to determine number of chars
	while((c=fgetc(file))){
		if (c == EOF){
			break;
		}
		count=count+1;
	}
 	fclose(file);
		
	FILE *file2 =fopen(argv[1],"r");
	int size = count;
	//create an char array
	char array[size];

	// put each char of file into an index of char array
	for(int i=0; i<=size-1; i++) {
		array[i]=fgetc(file2);		
	}
	fclose(file2);


	char toFile[size];
	FILE *fileN=fopen(argv[1],"w+");
	
	//encripton for the chars
	for(int i=0; i<=size-1; i++){
		//calling cipher
		toFile[i]=cipher(array[i],key);	
		//insert chars into input file
		fputc(toFile[i],fileN);
 		 }
	fclose(fileN);
	 }
return 0;
}

