#include <stdio.h>
#include <stdlib.h>

void print(int c) {
	if (c == 0) {
		printf("0\n");
		return;
	}
	int digit_ocunt = 0;
	int k = 0;
	char s[14];
	//transform to non-negative number
	if (c < 0) {
		putchar('-');
		c = -c;
	}
	//insert comma into number
	while (c != 0) {
		s[digit_ocunt] = c % 10 + '0';
		c /= 10; 
		++ digit_ocunt;
		++ k;
		if (k % 3 == 0 && c != 0) {
			s[digit_ocunt] = ',';
			++digit_ocunt;
		}
	}
	//print the inversed string 
	while (digit_ocunt > 0) {
		-- digit_ocunt;
		putchar(s[digit_ocunt]);
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	int a, b;
	scanf("%d %d", &a, &b);
	print(a+b);
	return 0;
}