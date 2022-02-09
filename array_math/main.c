#include <stdio.h>

int main(int argc, char **argv) {
	int S[] = {1, 2, 9};
	int T[] = {1, 2, 3, 4, 5, 6};
	int U[] = [*S,*T];
	
	int countS = sizeof(S)/sizeof(S[0]);
	int countT = sizeof(T)/sizeof(T[0]);
	int countU = sizeof(U)/sizeof(U[0]);
	
	printf("set S: {");
	for(int i=0; i<countS; i++) {
		if(S[i] != 0) {
			printf("%d, ", S[i]);
		}
	}
	printf("\b\b}\n");
	
	printf("set T: {");
	for(int i=0; i<countT; i++) {
		if(T[i] != 0) {
			printf("%d, ", T[i]);
		}
	}
	printf("\b\b}\n");
	
	printf("set U: {");
	for(int i=0; i<countU; i++) {
		if(U[i] != 0) {
			printf("%d, ", U[i]);
		}
	}
	printf("\b\b}\n\n");
	
	return 0;
}
