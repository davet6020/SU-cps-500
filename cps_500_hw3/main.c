#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 10
	struct Point {
		int x, y;
	} X, Y;
	
int bubbleSort(int A[]);
int* createArray(int size);
double distance(struct Point p1, struct Point p2);


	
int main() {
    // Question 1
    printf("_-= Question 1 =-_\n");
    int A[SIZE];
    // Seed the random number generator with the current time so it changes every time the program is run.
    srand(time(NULL)); 
    
    // Build the array with ten random elements between 1-1000
    for(int i=0; i<10; i++) {
        A[i] = rand() % 1000 + 1;
    }
  
    printf("\n2nd Largest Value:\t%d\n", bubbleSort(A));
	
    // Question 2
    printf("\n_-= Question 2 =-_\n");
    createArray(rand() % 1000 + 1);
	
    // Question 3
    printf("\n_-= Question 3 =-_\n");
	
	// Set some values in my structs
	X.x = 6;
	X.y = 3;
	Y.x = 2;
	Y.y = 2;
	
	printf("The Distance between X and Y is: %f\n", distance(X, Y));
	
	return 0;
}

double distance(struct Point p1, struct Point p2) {
    double length;
    length = sqrt(pow((p1.x - p1.y), 2) + pow((p2.x - p2.y), 2));
    return length;
}


int bubbleSort(int A[]) {
    int tmp;
	
	printf("\tSorted Random:\t\t");
	for(int i=0; i<SIZE; i++) {
        printf("%d, ", A[i]);
    }

    for (int i=0; i<SIZE; i++) {
        for (int j = i+1; j<SIZE; j++) {
           if(A[i] < A[j]) {
               tmp = A[i];
               A[i] = A[j];
               A[j] = tmp;
           }     
        }     
    } 

	printf("\nSorted Descending:\t");	
    for(int i=0; i<SIZE; i++) {
        printf("%d, ", A[i]);
    }
        
    // Return the 2nd element of A which is the 2nd largest element.
    return A[1];
}


int* createArray(int size) {
    int *A;
    A = (int *) malloc(sizeof(int));
    *A = size;
	
    printf("sizeof(array A): %d\n", *A);
	
	return 0;
}
