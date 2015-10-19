#include <iostream>

int main() {
	int k;
	int sequence[10005];
	// freopen("input.txt", "r", stdin);
	std::cin >> k;
	int tmp, max, mid, negcount, start, end;
	for(int i = 0; i < k; ++i) {
		int n;
		std::cin >> n;
		if(n < 0) ++negcount;
		sequence[i] = n;
	}
	if(negcount == k) {
		std::cout << 0 << " " << sequence[0] << " " << sequence[k-1] << std::endl;
		return 0;
	}
	start = tmp = max = 0;
	end = k - 1;
	int tempi = 0;
	int tempj = 0;
	for(int i = 0; i < k; ++i) {
		if (tmp < 0) {
			tmp = sequence[i];
			tempi = i;
			tempj = i;
		} else {
			tmp += sequence[i];
			tempj = i;
		}
		if (tmp > max || (tmp == 0 && end == k - 1)) {
			max = tmp;
			start = tempi;
			end = tempj;
		}
	}
	std::cout << max << " " << sequence[start] << " " << sequence[end] << std::endl;
	return 0;
}