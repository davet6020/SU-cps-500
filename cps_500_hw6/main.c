#include <stdio.h>
#include <string.h>

void q1(int *A, int size, int pos, int *R);
int q2(int n, int p);
void q3(char *is, int pos, int istrlen);
void swap(char *x, char *y);
int factorial(int n);
void printArray(int *arr, int cnt);

int main() {
	printf("Question 1:\n");
	// int A[] = {1, 2, 3, 4, 5};
	int A[] = {2, 4, 6, 5, 3, 1, 9};
	int size = sizeof(A)/sizeof(A[0]);
	int R[size];
	
	printArray(A, size);
	q1(A, size, 0, R);
	printArray(A, size);
	
	printf("\nQuestion 2:\n");
	int n = 2;
	int p = 8;
	int result = q2(2, 8);
	printf("Result: %d^%d = %d\n\n", n, p, result);
	
	printf("Question 3:\n");
	char istr[] = "ABCD";
	int istrlen = strlen(istr);
	int fact = factorial(istrlen);

	printf("Input String: %s is length of %d\n", istr, istrlen);
	printf("Factorial of %d: %d\n", istrlen, fact);
	printf("%s has %d possible permutations\n\n", istr, fact);
	
    q3(istr, 0, (istrlen - 1));
	
	printf("\n\n");
	
	return 0;
}

// For a list of permutations on letters
// 3 letters is a permutation of 6
// Each letter starts the permutation 6/3 times
// (# permutations / # letters)
// 4 letters generates 24 permutations
// 24 / 4 = 6
// A,B,C,D | A,C,B,D | A,D,C,B | A,C,D,B | A,B,D,C | A,D,B,C
void q3(char *is, int pos, int istrlen) {
	int i;
	if (pos == istrlen) {
		printf("%s | ", is);
	} else {
		for (i = pos; i <= istrlen; i++) {
			swap((is+pos), (is+i));
			q3(is, pos+1, istrlen);
			swap((is+pos), (is+i));
		}
	}
}

// Swap the values to skip what doesnt need to be updated
void swap(char *ispos, char *isi) {
    char tmp;
    tmp = *ispos;
    *ispos = *isi;
    *isi = tmp;
}

/**
 * Pass in a number and a power, use recursion to multiply that number by
 * itself power number of times. Do until while the power > 1 which is the
 * base case and good math, prevents divide by 0 and itself time 1 is itself
 * so no need to bother
 * @param n is the number to multiply by itself
 * @param p the power you want to get to
 * @return the recursed final value of number * (q2(n, power - 1))
 */
int q2(int n, int p) {
	while(p > 1) {
		return (n * q2(n, p - 1));
	}
	
	return n;
}


/**
 * Recursively replace elements 0-n of A[] with product of all elements except pos.
 * @param A Array to do math on
 * @param size of A[]
 * @param pos for tracking where we are
 * @param R empty array same size as A[] and used to store changes.
 * @return R with new values
 */
void q1(int *A, int size, int pos, int *R) {
	int x = 1;	// Start as 1 so no divide by 0
	
	// base case so we fall out of loop
	if(pos == (size+1)) {
		return;
	}
	
	for(int i=0; i<size; i++) {
		if(i != pos) {	// Do * on all elements except pos
			x *= A[i];
		}
	}
	
	R[pos] = x;	// Replace R with the new value.
	pos++;

	q1(A, size, pos, R);	// Call q1 again with new values
	
	// Replace A[] with R[]
	for(int i=0; i<size; i++) {
		A[i] = R[i];
	}
}


void printArray(int *arr, int cnt) {
	printf("arr = {");
	for(int i=0; i<cnt; i++) {
		printf("%d, ", arr[i]);
	}
	printf("\b\b}\n");
}

int factorial(int n) {
	if(n==0) {
		return 1;
	} else {
		return n * factorial(n-1);
	}
}