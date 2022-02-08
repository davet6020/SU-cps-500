#include <stdio.h>
#include <stdlib.h>

void setDifference(int* S, int countS, int* T, int countT);
int properSubset(int* S, int countS, int* T, int countT);
int subsetSum(int* set, int count, int sum);
int chkTwo(int val1, int val2, int sum);
int chkThree(int val1, int val2, int val3, int sum);


int main() {
	int S[] = {1, 2, 9};
	int T[] = {1, 2, 3, 4, 5, 6};
	int countS = sizeof(S)/sizeof(S[0]);
	int countT = sizeof(T)/sizeof(T[0]);
	
	setDifference(S, countS, T, countT);
	
	// Set this to 3 for next question.
	S[2] = 3;

	if(properSubset(S, countS, T, countT)) {
		printf("S is a subset of T\n\n");
	} else {
		printf("S is not subset of T\n\n");
	}

	int set[] = {3, 34, 4, 12, 5, 2};
	int count = sizeof(set)/sizeof(set[0]);
	int sum = 9;	
	
	subsetSum(set, count, sum);
	
	return 0;
}

// Sorts an array in ascendending order
int sortAsc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}


// For question 3 extra credit
int subsetSum(int* set, int count, int sum) {
	printf("=== Question 3 ===\n");
	
	// Sort the array ascending to the process is faster
	qsort(set, count, sizeof(int), sortAsc);
	
	printf("set = {");
	for(int i=0; i<count; i++) {
		if(set[i] != 0) {
			printf("%d, ", set[i]);
		}
	}
	printf("\b\b}\n\n");
	
	printf("Test value of sum is 9\n");
	for(int i=0; i<count; i++) {
		if(set[i] <= sum && set[i+1] <= sum) {
			int x = chkTwo(set[i], set[i+1], sum);
			if(x == 1) {
				break;
			}
		}
	}

	printf("Test value of sum is 9\n");
	for(int i=0; i<count; i++) {
		if(set[i] <= sum && set[i+1] <= sum && set[i+2]) {
			int x = chkThree(set[i], set[i+1], set[i+2], sum);
			if(x == 1) {
				break;
			}
		}
	}

	// Check more multiple consecutive elements at a time
	// Add elements until value found or end of loop
	printf("Test value of sum is 14\n");
	sum = 14;			// test value
	int quit = 0;		// tells us when to quit the loop
	int X[9] = {0};		// stores temp values
	int a = 0;
	
	while(a <= sum && quit == 0) {
		for(int i=0; i<count; i++) {
			if(set[i] <= sum) {		// Only add elements where value <= sum because > sum will never equal sum
				X[i] = set[i];
				a += set[i];
				
				// If we find sum
				if(a == sum) {
					int countX = sizeof(X)/sizeof(X[0]);
					printf("These numbers summed: ");
					for(i=0; i<countX; i++) {
						if(X[i] != 0) {		// Only print non 0 elements
							printf("%d, ", X[i]);
						}
					}
					printf("\b\b = %d\n\n", sum);
					quit = 1;
					break;
				}
			}
		}
		// If we did not find sum
		if(quit == 0) {
			printf("Sum not found\n");
		}
	}
	
	return 0;
}

// Check two numbers at a time.
int chkTwo(int val1, int val2, int sum) {
	if(val1 + val2 == sum) {
		printf("%d + %d = %d\n\n", val1, val2, sum);
		return 1;
	} else {
		return 0;
	}
}

// Check three numbers at a time.
int chkThree(int val1, int val2, int val3, int sum) {
	if(val1 + val2 + val3 == sum) {
		printf("%d + %d + %d = %d\n\n", val1, val2, val3, sum);
		return 1;
	} else {
		return 0;
	}
}

// Checkif S is a subset of T
int properSubset(int* S, int countS, int* T, int countT) {
	printf("=== Question 2 ===\n");
	int FOUND[countS];
	
	printf("set S = {");
	for(int i=0; i<countS; i++) {
		if(S[i] != 0) {
			printf("%d, ", S[i]);
		}
	}
	printf("\b\b}\n");
	
	printf("set T = {");
	for(int i=0; i<countT; i++) {
		if(T[i] != 0) {
			printf("%d, ", T[i]);
		}
	}
	printf("\b\b}\n");
	
	// For each S, search T for the same value
	for(int s=0; s<countS; s++) {
		for(int t=0; t<countT; t++) {
			// Toggle found variable as a tracker
			if(S[s] == T[t]) {
				FOUND[s] = 1;
				break;
			} else {
				FOUND[s] = 2;
			}
		}
	}
	
	int subset = 0;
	
	for(int f=0; f<countS; f++) {
		if(FOUND[f] == 2) {
			subset = 0;
			break;
		} else {
			subset = 1;
		}
	}
	
	if(subset == 1) {
		return 1;
	} else {
		return 0;
	}
}


// Get the difference of S -> T
void setDifference(int *S, int countS, int *T, int countT) {
	int DIFF[countS + countT];
	int countD = sizeof(DIFF)/sizeof(DIFF[0]);
	
	printf("=== Question 1 ===\n");
	printf("set S = {");
	for(int i=0; i<countS; i++) {
		if(S[i] != 0) {
			printf("%d, ", S[i]);
		}
	}
	printf("\b\b}\n");
	
	printf("set T = {");
	for(int i=0; i<countT; i++) {
		if(T[i] != 0) {
			printf("%d, ", T[i]);
		}
	}
	printf("\b\b}\n");
	
	int found = 0;
	
	// For each S, search T for the same value
	for(int s=0; s<countS; s++) {
		for(int t=0; t<countT; t++) {
			// Toggle found variable as a tracker
			if(S[s] == T[t]) {
				found = 1;
			} else {
				found = 0;
			}
			
			// Found in T so dont keep it
			if(found) {
				break;
			} else {
				// No match found so put keep this one in the result set
				if(t==(countT-1)) {
					for(int d=0; d<countD; d++) {
						if(DIFF[d] == 0) {
							DIFF[d] = S[s];
							break;
						}
					}	
				}
			}
		}
	}
	
	// Display results
	printf("S - T = {");
	for(int i=0; i<countD; i++) {
		if(DIFF[i] != 0) {
			printf("%d, ", DIFF[i]);
		}
	}
	printf("\b\b}\n\n");
}
