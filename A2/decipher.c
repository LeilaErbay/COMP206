#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//undo encription function
char decipher (char input, int key) {
char c =input;
       if (input == 32){
                 c = 32;
        }
	//range for Uppercase letters
       if (input >= 65 && input<=90){
                c = c + key;
		// if char is out of bounds of upper case letters
                if (c > 90) {
                	c = c - 26;
                if (c < 65) {
                	c = c + 26;
                }
        }
	//range for lowercase letters
        else if (c >= 97 && c <= 122) {
                c = c - key;
		//conditions if char is out of bounds of lower case letters
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
	//open file inputed by user
        FILE *file =fopen(argv[1],"r");

	//if file is NULL tell user
        if (file=='\0'){
                printf("Please enter an existing file name");
                exit(0);
        }

        else {
        char c;
        int count=0;
        int key=atoi(argv[2]);

	//determine number of chars in the file
	while((c=fgetc(file))){
                if (c == EOF){
                        break;
                }
                count=count+1;
        }
	int size = count;
	fclose(file);
	
	FILE *file2=fopen(argv[1], "r"); 
   	//create a char array of the size of the number of chars in the file
        char array[size];
	
	//put each char into an index in the char array
        for(int i=0; i<=size-1; i++) {
                array[i]=fgetc(file2);
        }
        fclose(file2);


        char toFile[count];
        FILE *fileN=fopen(argv[1],"w+");
	
	//deciphering occurs here
        for(int i=0; i<=size-1; i++){
		//call to the decipher function
                toFile[i]=decipher(array[i],key);
		//put each char into the file
                fputc(toFile[i],fileN);
                 }
         fclose(fileN);
	 }

return 0;
}
