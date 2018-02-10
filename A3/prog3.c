#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
int x = atoi(argv[1]);
int y = atoi(argv[2]);

//tell user if there are too few or too many arguments
if (argc <= 1) {
	printf("you have too few arguments\n");
	EXIT_FAILURE;
	}

if (argc > 3){
	printf("you have too many arguments\n");
	EXIT_FAILURE;
}

//main process
printf("Main Process Started\n");
printf("Number of Random Numbers = %d\n", x);
printf("Fibonacci Input = %d\n", y);


pid_t child1, child2;

//child1 performs the randomization and sorting
if (!(child1=fork())){
	printf("Insertion Sort Process Created\n");
	mixAndSort(x);
	exit(0);
}
//child2 performs the fib number
if(!(child2=fork())) {
	printf("Fibonacci Process Created\n");
	fibNth(y);
	exit(0);
}
else{
	printf("Main process waits\n");
	wait(&child1),wait(&child2);
	printf("Main Process exits\n");
}
EXIT_SUCCESS;
}
