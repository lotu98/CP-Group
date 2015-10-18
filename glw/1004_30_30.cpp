#include <iostream>
#include <vector>
#include <map>

std::map<int, std::vector<int> > tree;
int childrenCount[1000]={0};
int maxDepth = 0;

void dfs(int currentID, int depth) {
	if(tree[currentID].empty()) {
		++childrenCount[depth];
		// std::cout << "ID: " << currentID << " Depth: " << depth << std::endl;
		if(maxDepth < depth) maxDepth = depth;
		return;
	}
	std::vector<int>::iterator it = tree[currentID].begin();
	for(; it != tree[currentID].end(); ++it) {
		dfs(*it, depth+1);
	}
	return;
}

int main() {
	// freopen("input.txt", "r", stdin);
	int N, M;
	std::cin >> N >> M;
	for(int i = 0; i < M; i++) {
		int ID, K;
		std::cin >> ID >> K;
		for(int j = 0; j < K; j++) {
			int tt;
			std::cin >> tt;
			tree[ID].push_back(tt);
		}
	}
	dfs(01, 0);
	if(maxDepth > 0) {
		for(int i = 0; i < maxDepth; i++)
			std::cout << childrenCount[i] << " ";
		std::cout << childrenCount[maxDepth] << std::endl;
	} else {
		std::cout << childrenCount[maxDepth] << std::endl;
	}
	return 0;
}