#include <stdio.h>

// void ptr(int x, int *y, int **z);

int main() {
	int x = 789;
	int *y;
	int **z;
	
	ptr(x, &y, &z);
	
	return 0;
}

void ptr(int a, int *b, int **c) {
	b = &a;
	c = &b;
	
	printf("a: %d\n", a);
	printf("a via *b: %d\n", *b);
	printf("a via **c: %d\n", **c);
}

/* OUTPUT
	a: 789
	a via *b: 789
	a via **c: 789
*/