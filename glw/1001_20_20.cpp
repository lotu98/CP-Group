#include <iostream>
#include <string>

int main() {
	int a,b,c;
	std::string result;
	std::cin >> a >> b;
	c = a+b;
	result = std::to_string(c);
	for(int t = 0; t < result.length(); t++) {
		if(result[0] != '-') {
			(result.length() - t - 1) % 3 == 2 && result.length() > 3 ? 
			std::cout << ',' << result[t] : std::cout << result[t];
		} else {
			(result.length() - t - 2) % 3 == 2 && result.length() > 4 && t != 0? 
			std::cout << result[t] << ',' : std::cout << result[t];
		}
	}
	std::cout << std::endl;
	return 0;
}
