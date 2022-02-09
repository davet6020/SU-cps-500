#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int bubbleSort(int A[]);
// int secondLargest(int A[], int N);
int* createArray(int size);
// double distance(struct Point* p1, struct Point* p2);

int main() {
    // Question 1
    printf("_-= Question 1 =-_\n");
    int arrSat[SIZE];
    // Seed the random number generator with the current time so it changes every time the program is run.
    srand(time(NULL)); 
    
    // Build the array with ten random elements between 1-1000
    for(int i=0; i<10; i++) {
        arrSat[i] = rand() % 1000 + 1;
    }
  
    printf("\n2nd Largest Value in Array: %d\n", bubbleSort(arrSat));
	// printf("\n2nd Largest Value in Array: %d\n", secondLargest(arrSat, sizeof(arrSat)));
	
    // Question 2
    printf("\n_-= Question 2 =-_\n");
    createArray(77);
	
    // Question 3
    printf("\n_-= Question 3 =-_\n");
	
//    struct Point {
//        int x, y;
//    };
//    
//    struct Point *p1, *p2, q, w;
//    p1 = &q;
//    p2 = &w;
//    
//    (*p1).x = 2;
//    (*p1).y = 2;
//    (*p2).x = 3;
//    (*p2).y = 3;
    
    // distance(p1, p2);
	
	return 0;
}

//double distance(struct Point *p1, struct Point *p2) {
//    double fx, fy;
//	
//    fx = (*p1).x - (*p2).x;
//    fy = (*p1).y - (*p2).y;
//    return sqrt((fx * fx) + (fy * fy));
//    
//    // square root[(í¤†íµ± âˆ’ í¤†íµ²)2+ (í¤†í¶± âˆ’ í¤†í¶²)2]
//    printf("here\n");
//}


int bubbleSort(int A[]) {
    int tmp;
	
    printf("Array Sorted Descending: ");
	
	for(int i=1; i<SIZE; i++) {
		for(int j=0; j<SIZE; j++) {
			if(A[i] > A[i+1]) {
				tmp = A[i];
				A[i] = A[i+1];
				A[i+1] = tmp;
			}
		}
	}
	
    
//    for (int i=0; i<SIZE; i++) {          // loop - all elements of N as i
//        for (int j = i+1; j<size_N; j++) {  // loop - all elements of N as j
//           if(A[i] < A[j]) {                // if A[i] < A[j] store A[i] in tmp
//               tmp = A[i];
//               A[i] = A[j];                 // now A[i] = A[j] 
//               A[j] = tmp;
//           }     
//        }     
//    }    
    
    for(int i=0; i<SIZE; i++) {
        printf("%d, ", A[i]);
    }
        
    // Return the 2nd element of A which is the 2nd largest element.
    return A[1];
}

/**
 * Return the 2nd largest value in the array
 * A The array
 * N The size of array A
 * @return 
 * Note: arrays passed as a parameter are pointers so sizeof them is the sizeof the pointer
 * Since we know that we are passing in the array as int A[] we know its in int but we do
 * not know the size of the integer because this platform could be 32-bit or 64-bit.
 */
int secondLargest(int A[], int N) {
    // size_N = # of elements in N. Derived from 
    // (# bytes in N) / (size of N data type) eg 40 / 4.
    int size_N = N / sizeof(int);
    int tmp = 0;
	
    printf("Array Sorted Descending: ");
    
    for (int i=0; i<size_N; i++) {          // loop - all elements of N as i
        for (int j = i+1; j<size_N; j++) {  // loop - all elements of N as j
           if(A[i] < A[j]) {                // if A[i] < A[j] store A[i] in tmp
               tmp = A[i];
               A[i] = A[j];                 // now A[i] = A[j] 
               A[j] = tmp;
           }     
        }     
    }    
    
    for(int i=0; i<size_N; i++) {
        printf("%d, ", A[i]);
    }
        
    // Return the 2nd element of A which is the 2nd largest element.
    return A[1];
}

int* createArray(int size) {
    int *A;
    A = (int *) malloc(sizeof(int));
    *A = size;
	
    printf("sizeof(A): %d\n", *A);
}
