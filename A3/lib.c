#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//random number generator function
void randNumGen(int* nums, int x){
	int space=4;
	for(int i =0; i< x; i++){
		nums[i]=(rand()%100);
		printf("%*s",space," ");
		printf("%d", nums[i]);
	}
}

//sorting function using insertion sort
void sort(int * array, int x){
	for (int k=1; k<x; k++){
		int elem=array[k];
		int i=k;
		while((i>0) && (array[i-1]>elem)){
			array[i]=array[i-1];
			i=i-1;
		}
	array[i]=elem;
	}
}

//function that calls both the randNumGen and Sort and prints the appropriate statements
void mixAndSort(int x){
	int array[x];
	int space =4;
	printf("%*s", space, "");
	char *str1= "Insertion sort process started";
	printf("%*s\n",space, str1);
	
	printf("%*s", space, "");
	char *str2= "Random Numbers Generated";
	printf("%*s\n",space, str2);
	
	randNumGen(array,x);
	printf("\n");
	
	printf("%*s", space, "");
	char *str3 = "Sorted Sequence:";
	printf("%*s\n",space, str3);
		
	sort(array,x);
	for (int j=0; j<x; j++){
		printf("%*s",space," ");
		printf("%d",array[j]);
	}
	printf("\n");
	printf("%*s", space, " ");
	char *str4 = "Insertion sort process exits";
 	printf("%*s\n",space, str4);
	
}

//recursive fibonacci algorithm that returns a long
long fib(int n){
	if (n <= 2){
		return 1;
	}
	else{
		return fib(n-1)+fib(n-2);
	}
}

//function that calls recurisve fib function and prints the appropriate fib value
void fibNth(int y){
	int space=7;
	printf("%*s", space, " "); 
	char *str1="Fibonacci process started";
	printf("%*s\n",space, str1);
	
	printf("%*s", space, " ");
	char *str2 = "Input Number:";
	printf("%*s",space, str2);
	printf("%d", y);

	printf("\n");

	printf("%*s",space," "); 
	printf("Fibbonacci Number f(%d) is ", y);
	long val = fib(y);
	printf("%1ld", val);

	printf("\n"); 
	char *str4 = "Fibonacci Process exits";
	 printf("%*s",space, " ");
	printf("%*s\n",space,str4);
}





