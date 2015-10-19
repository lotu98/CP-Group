#include <iostream>
#include <string>

std::string dic[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight","nine"};

int main() {
	std::string number;
	std::cin >> number;
	int sum = 0;
	for(int i = 0; i < number.length(); ++i) {
		sum += int(number[i]) - 48; // ASCII table
	}
	std::string result = std::to_string(sum);
	for(int i = 0; i < result.length() - 1; ++i) {
		std::cout << dic[int(result[i]) - 48] << " ";
	}
	std::cout << dic[int(result[result.length() - 1]) - 48];
	std::cout << std::endl;

}