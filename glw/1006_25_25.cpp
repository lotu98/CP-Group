#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

bool less(std::vector<std::string> a, std::vector<std::string> b) {
	return a[1] < b[1];
}

bool gr(std::vector<std::string> a, std::vector<std::string> b) {
	return a[2] > b[2];
}

int main() {
	std::vector<std::vector<std::string> > logs;
	int n;
	// freopen("input.txt", "r", stdin);
	std::cin >> n;
	for(int i = 0; i < n; ++i) {
		std::string ID, inTime, outTime;
		std::vector<std::string> tmp;
		std::cin >> ID >> inTime >> outTime;
		tmp.push_back(ID), tmp.push_back(inTime), tmp.push_back(outTime);
		logs.push_back(tmp);
	}
	sort(logs.begin(), logs.end(), less);
	std::cout << logs[0][0] << " ";
	sort(logs.begin(), logs.end(), gr);
	std::cout << logs[0][0] << std::endl;
	return 0;
}