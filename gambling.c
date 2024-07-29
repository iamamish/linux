#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define NUM_HANDS 10
#define PERCENT_CHANCE 58
#define SEED_ENABLED 1
 
int evaluate_hand(int i);

int main(int a) {

	int i = 0;
	int stackSize = 1000;

	if (SEED_ENABLED) {
		srand(time(NULL) + (time(NULL) % a));
	} 

	for (i =0; i< NUM_HANDS; i++)
	{
	     stackSize += evaluate_hand(i);
	}

	printf("%d\n", stackSize);
	return 0;

}


int evaluate_hand(int offset) {

	int random = 0;

	random = rand() % 100;


	/* printf("random number is: %d\n", random); */

	if (random < PERCENT_CHANCE) {
		printf("returning 100\n");
		return 100;
	} else {
		printf("returning -100\n");
		return -100;
	}
}

