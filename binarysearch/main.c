#include <stdio.h>

int binarySearch(int *arr, int val, int lo, int hi);
void printArray(int *arr, int cnt);

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	int val = 4;
	int lo = 0;
	int hi = 4;
	
	printArray(arr, 4);
	int x;
	x = binarySearch(arr, val, lo, hi);
	printf("x: %d\n", x);
}

int binarySearch(int *arr, int val, int lo, int hi) {
	if(lo > hi) {
		return -1;
	}
	
	printf("lo: %d, hi: %d, val: %d\n", lo, hi, val);
	
	int middle = (hi - lo) / 2;
	printf("middle: %d\n", middle);
	if(arr[middle] == val) {
		return middle;
	} else if(arr[middle] < val) {
		return binarySearch(arr, val, middle+1, hi);
	} else {
		return binarySearch(arr, val, lo, middle-1);
	}
}

void printArray(int *arr, int cnt) {
	printf("arr = {");
	for(int i=0; i<=cnt; i++) {
		printf("%d, ", arr[i]);
	}
	printf("\b\b}\n\n");
}
