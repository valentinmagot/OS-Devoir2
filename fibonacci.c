// Bibiliothèques
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int arr[100];

void* fibonacci (void* arg){
	int n = *((int*) arg);

	int i, t1 = 0, t2 = 1, nextTerm;
	
	printf("Fibonacci Serie: ");

    for (i = 0; i <= n; ++i)
    {	
    	arr[i] = t1;
        printf("%d, ", arr[i]);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");

}

// void* printFibonacci (void* arg){
// 	int n = *((int*) arg);

// 	for (int i = 0; i < n; ++i)
// 	{
// 		printf("%d", arr[i]);
// 	}
// }

int main(int argc, char const *argv[])
{
	if(argc != 2 ){
		fprintf(stderr, "Wrond number of arguments. \n");
		exit(EXIT_FAILURE);
	}

	int num = atoi(argv[1]);
	int arr[num+1];

	pthread_t fibonaccer;

	if(pthread_create(&fibonaccer, NULL, fibonacci, &num)){
		fprintf(stderr, "Error creating thread. \n");
		exit(EXIT_FAILURE);
	}

	// if(pthread_create(&fibonaccer, NULL, printFibonacci, &num)){
	// 	fprintf(stderr, "Error creating thread. \n");
	// 	exit(EXIT_FAILURE);
	// }

	if(pthread_join(fibonaccer, NULL)){
		fprintf(stderr, "Error joining thread. \n");
		(EXIT_FAILURE);
	}

	return 0;
}