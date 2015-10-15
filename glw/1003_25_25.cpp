#include <iostream>
#include <deque>
#include <vector>
#define INF 99999
int rescue[505]={0}, road[505][505];
int N, M, C1, C2, count, max;
int traveled[505]={0};
std::vector<std::vector<int> > paths;
std::vector<int> path;
// standard DFS
void dfs(int current, int length, int res) {
	if(current == C2) {
		path.push_back(length); 
		path.push_back(res); 
		paths.push_back(path); 
		path.clear();
		return;
	}
	for(int i = 0; i < N; i++) {
		if( !traveled[i] && road[current][i] != INF) {
			traveled[i] = 1;
			dfs(i, length + road[current][i], res + rescue[i]);
			traveled[i] = 0;	
		}
	}
	return;
}

int main() {
	for(int i = 0; i < 505; i++)
		for(int j = 0; j < 505; j++) {
			road[i][j] = INF;
		}
	for(int i = 0; i < 505; i++) {
		road[i][i] = 0;
	}
	freopen("input.txt", "r", stdin);
	std::cin >> N >> M >> C1 >> C2;
	count = 0; max = -1;
	for(int i = 0; i < N; i++) {
		int tmp;
		std::cin >> tmp;
		rescue[i] = tmp;
	}
	for(int i = 0; i < M; i++) {
		int from, to, dis;
		std::cin>> from >> to >> dis;
		road[from][to] = dis;
		road[to][from] = dis;
	}
	traveled[C1] = 1;
	dfs(C1, 0, rescue[C1]);
	int min = INF;
	for(int i = 0; i < paths.size(); i++) {
		if(paths[i][0] < min) min = paths[i][0]; 
	}
	for(int i = 0; i < paths.size(); i++) {
		if(paths[i][0] == min) { 
			++count;
			if(paths[i][1] > max) {
				max = paths[i][1];
			}
		}
	}
	std::cout << count << " " << max << std::endl;
	return 0;
}

// int dist[505];
/* Dijkstra for a try
void dijkstra(int from) {
	std::vector<int> visited;
	for(int i = 0; i < N; i++) if(i != from) visited.push_back(i);
	for(int i = 0; i < N; i++) {
		dist[i] = road[from][i];
	}
	dist[from] = 0;
	for(int i = 0; i < N-1; i++) {
		int min = INF;
		int add = -1;
		int pos;
		for(int j = 0; j < visited.size(); j++) {
			if(dist[visited[j]] < min) {
				min = dist[visited[j]];
				add = visited[j];
				pos = j;
			}
		}
		if(add != -1) visited.erase(visited.begin() + pos);
		for(int j = 0; j < visited.size(); j++) {
			if(dist[add] + road[add][visited[j]] < dist[visited[j]])
				dist[visited[j]] = dist[add]+road[add][visited[j]];
		}
	}
	return;
}
*/