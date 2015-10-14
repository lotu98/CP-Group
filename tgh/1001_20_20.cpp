#include <iostream>
using namespace std;

int main() {
	long a, b;

	cin >> a;
	cin >> b;

	long sum = a + b;
	int count;

	// Count the number of segments
	if ((sum / 1000) != 0) {
		if ((sum / 1000000) != 0) {
			count = 2;
			cout << sum / 1000000;
		} else {
			count = 1;
			cout << sum / 1000;
		}
	} else {
		count = 0;
		cout << sum;
	}

	// Remove the symbol except the first segment
	sum = abs(sum);

	// Print the following segments
	while (count != 0) {
		int tmp = (sum / (count == 2? 1000 : 1)) % 1000;

		// Deal with commas and zeros
		if (tmp >= 100) {
			cout << "," << tmp;
		} else if (tmp >= 10) {
			cout << ",0" << tmp;
		} else if (tmp >= 0){
			cout << ",00" << tmp;
		}
		count --;
	}

	return 0;
}