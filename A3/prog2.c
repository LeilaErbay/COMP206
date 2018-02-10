#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//method for reading in strings
char* read_in(){
	int i = 0;
	int size = 1;
	char *string = (char*)malloc(size*sizeof(char));
	int c;	 

	while(EOF != (c=getchar()) && c != '\n' && c!= '\r'){
		string[i] = c;
		string = (char*)realloc(string,size*sizeof(char));
		size++;
		i++;
		}
	string[i++] = '\0';
	return string;
} 
//mystrncpy
char* mystrncpy(char* s, char* t, int n) {
	char * copy=s;
        for (int i =0; i< n; i++){
                *copy++ = *t++;
        }
        *copy='\0';
	return s;
}



//strlen
int mystrnlen (char* input){
	int length=0;
	int i =0;
	for(; input[i] != '\0'; i++){
		length++;
	}
	return length;
}

//mystrncat
char *mystrncat(char * copy, char * s, int n){
        size_t copyLen=strlen(copy);
	char *ret = copy+copyLen;

	*ret++= ' ';
	while(n--){
		*ret++ = *s++;
	}
	*ret = '\0';
	return copy;
}

//mystrncmp
int mystrncmp(char* s, char* t, int n) {
	int diff = 0;
	for(int i =0; i< n; i++){
		if (*s > *t){
			 diff = *s-*t;
	        }
        	if (*s < *t) {
			diff = *s-*t;
        	}
        	if (*s == *t) {
			diff= 0;
        	}
		}
	return diff;
}

int main() {
	//string 1
	char *s;

	//string 2
	char *t;

	//number 
	int n;	

	//Prompt user for String 1 and store the string in s
	printf("Enter the first string: ");
	s = read_in();

	//prompt the user for string 2 and store the string in t
	printf("Enter the second string: ");
	t = read_in();	

	//prompt the user for a number
	printf("Enter a number: ");
	scanf("%d", &n); 
	
	//length of s
	int lenS = 0;
	for (int c = 0; s[c]!='\0'; c++){
		lenS++;
	}

	//copy of string 1
	char *copyS = (char*) malloc(lenS+1);
	int b = 0;
	int z=1;
	for (;b<lenS+1; b++){
		copyS[b] = s[b];
		copyS=(char*) realloc(copyS,z*sizeof(char)); 
		z++;
	}
	copyS[b++] = '\0';

	//strncpy elements from t to s
	s= mystrncpy(s, t, n);
	printf("strncpy is \"%s\" \n", s);


	

	char copy2 [strlen(copyS)];
	int q=0;
	for (; q < strlen(copyS); q++) {
		copy2[q]= copyS[q];
		}
	copy2[q++] = '\0';
		
	
	//strncat s to copyS
	char *str = mystrncat(copyS, s, n);
	printf("strncat is \"%s\"\n", str);
	

	//strncmp
	int ret = mystrncmp(copy2, t, n);
	if (ret > 0){
		printf("strncmp is \"%s\" > \"%s\"\n", copy2, t);
	}
	if (ret < 0){
               printf("strncmp is \"%s\" < \"%s\"\n", copy2, t);
	}
	if (ret == 0) {
		 printf("strncmp is \"%s\" = \"%s\"\n", copy2, t);	
	}
EXIT_SUCCESS;	
}
 
