#include <stdio.h>

void swap(int *px, int *py);

int main() {
	// char ch = 'k';
	
	int x = 1, y = 2, z[10];
	int *ip;
	printf("x: %d, y: %d\n", x, y);
	
	ip = &x;
	printf("ip(x): %d\n", *ip);
	printf("ip(addr): %p\n", ip);
	
	y = *ip;
	printf("y(ip): %d\n", y);

	*ip = 0;
	printf("ip: %d\n", *ip);
	printf("x: %d, y: %d\n", x, y);
	
	ip = &z[0];
	printf("ip(z[0]): %d\n", *ip);
	printf("ip(addr): %p\n", ip);
	
	z[0] = 3;
	printf("ip(z[0]): %d\n", *ip);
	printf("ip(addr): %p\n", ip);	
	
	++*ip;
	printf("ip: %d\n", *ip);
	printf("ip(addr): %p\n", ip);
	
	(*ip)++;
	printf("ip: %d\n", *ip);
	printf("ip(addr): %p\n", ip);	
	
	int *iq = ip;
	printf("iq: %d\n", *iq);
	printf("iq(addr): %p\n", iq);
	printf("x: %d, y: %d\n", x, y);
	printf("z[0]: %d\n", z[0]);
	
	(*iq)++;
	printf("iq: %d\n", *iq);
	printf("iq(addr): %p\n", iq);
	printf("z[0]: %d\n", z[0]);
	
	int a = 4, b = 14;
	printf("main() - a: %d, b: %d\n", a, b);
	printf("main(addr) - a: %p, b: %p\n", &a, &b);
	swap(&a, &b);
	printf("main() - a: %d, b: %d\n", a, b);
	return 0;
}

void swap(int *px, int *py) {
	int temp;
	
	temp = *px;
	*px = *py;
	*py = temp;
	
	printf("swap() - a: %d, b: %d\n", *px, *py);
}
