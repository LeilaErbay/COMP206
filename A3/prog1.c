#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Fibonacci Sequence Iterative Algorithm
int fib(int n) {
	int f[n+1];
	f[1]=f[2]=1;
	for (int i = 3; i <= n; i++) {
		f[i] = f[i-1] + f[i-2];
	}
	return f[n];

}

int main(int argc, char* argv[]) {
//Read from file
FILE *file = fopen(argv[1], "r");

//if file is empty
if (file == NULL) {
	printf("Input txt file doesn't exist\n");
	exit(0);
}
int count = 0, num;
char c;
	//determine the number of Integers that are in the file
	while (!feof(file)) {
		fscanf(file, "%d ", &num);
		count = count +1;
	}
fclose(file);
 

FILE *file2 = fopen(argv[1], "r");
int size = count;
int nums[size];
//fill an array with the numbers from the input.txt file
for (int i=0; i<= size-1; i++){
	fscanf(file2, "%d ", &nums[i]);
}
fclose(file2);

int sum = 0;
//determine the sum of the integers from the input file
for(int i = 0; i<=size-1; i++){
	sum +=nums[i];
}
printf("The sum of the numbers is %d \n", sum);

printf("The Fibonnaci Sequence is: \n");
//print 
for (int i = 0; i<= size-1; i++){
	printf("Fib(%d) is %d", nums[i], fib(nums[i]));
	printf("\n");
	}
EXIT_SUCCESS;
}
