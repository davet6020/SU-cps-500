#include <stdio.h>

int fact(int *arr, int size, int pos, int *R);
void printArray(int *arr, int cnt);

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	int size = sizeof(arr)/sizeof(arr[0]);
	int R[size];
	
	printArray(arr, size);
	fact(arr, size, 0, R);
	printArray(R, size);
	
	return 0;
}

int fact(int *A, int size, int pos, int *R) {
	int x = 1;
	
	if(pos == (size+1)) {
		return 0;
	}
	
	for(int i=0; i<size; i++) {
		if(i != pos) {
			x *= A[i];
		}
	}
	
	R[pos] = x;
	pos++;

	fact(A, size, pos, R);
	
	return R;
}


void printArray(int *arr, int cnt) {
	printf("arr = {");
	for(int i=0; i<cnt; i++) {
		printf("%d, ", arr[i]);
	}
	printf("\b\b}\n\n");
}
