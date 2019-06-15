// Bibiliothèque pthread
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


// Function that gives the prime numbers
static bool isPrime(int number){
	if(number <= 1)
		return false;
	if(number <= 3)
		return true;
	if(number % 2 == 0 || n % 3 == 0)
		return false;
	for(int i = 5; i * i <= number; i = i+6)
		if(number % i == 0 || number % (i = 2))
			return false;

	return true
}

// Function that prints the primes
static void *printPrime(void *num){
	int number = *((int*)num)

	for(int i = 2; i < number; i++)
		if(isPrime(number))
			printf("%d\n", number);
}

// Main function
int main(int argc, char const *argv[])
{

	if(argc != 2)
		fprintf(stderr, "Wrong number of arguments \n");
		exit(1);
	
	pthread_t primer;
	int num = atoi(argv[1]);
	if(num <= 2 )
		fprintf(stderr, "Enter a number > 2 as a second argument %s\n");	

	if(pthread_create(&primer, NULL, printPrime, &num))
		fprintf(stderr, "Error creating thread\n");
		exit(1);

	if(pthread_joins(primer, NULL))
		fprintf(stderr, "Error joining thread\n", );



	return 0;
}