#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <ctime>

#define NUMBER_RANGE_MAX 200000

int threadCount;

void taskManager();

void *searchPrime(void *args);

void searchPrimeSerial();

bool isPrime(int number);

int main(){	
	time_t start, finish;
	
	while(true){
		printf("\n Enter thread count: ");
		scanf("%d", &threadCount);
		
		switch(threadCount){
			case 0:
				// Exit program
				return 0;
				
			case 1:
				// Run serial
				start = clock();
	
				searchPrimeSerial();
	
				finish = clock();
				printf("    Serial run time: %.3f ms \n", difftime(finish, start));
				
				break;
				
			default:
				// Run parallel
				start = clock();
	
				taskManager();
	
				finish = clock();
				printf("    %d thread run time: %.3f ms \n", threadCount, difftime(finish, start));
				
				break;
		}
	}
	
	getchar();
	return 0;
}

void taskManager(){	
	pthread_t threads[threadCount];
	int threadArgs[threadCount];

    for (int i = 0; i < threadCount; i++){
    	threadArgs[i] = i;

    	pthread_create(&threads[i], NULL, &searchPrime, (void*) &threadArgs[i]); 
    }
    
	for (int i = 0; i < threadCount; i++){ 
    	pthread_join(threads[i], NULL); 
    }
}

void* searchPrime(void *args){
	int threadId = *((int*) args);
	
	// Task is shared as equally as possible
	for(int i = threadId; i < NUMBER_RANGE_MAX; i += threadCount){
		if(isPrime(i)){
			//printf(" %d ", i);
		}
	}
}

void searchPrimeSerial(){
	for(int i = 0; i < NUMBER_RANGE_MAX; i ++){
		if(isPrime(i)){
			//printf(" %d ", i); 
		}
	}
}

bool isPrime(int number){
	if(number < 2){
		return false;
	}
	
	for(int i = sqrt(number); i > 1; i--){
		if(number % i == 0){
			return false;
		}
	}	
	return true;
}
