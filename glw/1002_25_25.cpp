#include <iostream>

int main() {
	int a,b, count = 0;
	double an[1005] = {0}, bn[1005] = {0};
	std::cin >> a;
	for(int i = 0; i < a; i++) {
		int expo; double coef;
		std::cin >> expo >> coef;
		an[expo] = coef;
	}
	std::cin >> b;
	for(int i = 0; i < b; i++) {
		int expo; double coef;
		std::cin >> expo >> coef;
		bn[expo] = coef;
	}
	for(int i = 1004; i >= 0; --i) {
		an[i] += bn[i];
		if(an[i] != 0) {
			++count;
		}
	}
	printf("%d", count);
	for(int i = 1004; i >= 0; --i) {
		if(an[i] != 0) {
			printf(" %d %.1lf", i, an[i]);
		}
	}
	std::cout << std::endl;
	return 0;
}

