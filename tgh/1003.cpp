#include <iostream>
using namespace std;

int main()
{
	int n, m, c1, c2;

	cin >> n >> m >> c1 >> c2;

	int team[n];

	for (int i = 0; i < n; i ++) {
		cin >> team[i];
	}

	int **city;

	city = new int*[n];
	for (int i = 0; i < n; i ++) {
		city[i] = new int[n];
	}
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			city[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i ++) {
		int tmp1, tmp2, len;
		cin >> tmp1 >> tmp2 >> len;
		city[tmp1][tmp2] = city[tmp2][tmp1] = len;
	}

	int dist[n];
	bool done[n];
	int count = 0;

	for (int i = 0; i < n; i ++) {
		dist[i] = city[c1][i];
		done[i] = false;
	}

	dist[c1] = 0;
	done[c1] = true;

	for (int i = 1; i < n; i ++) {
		int mindist = 65535;
		int next = c1;

		for (int j = 0; j < n; j ++) {
			if (!done[j] && dist[j] < mindist) {
				next = j;
				mindist = dist[j];
			}
		}
		done[next] = true;
		cout << mindist << " ";
		if (next == c2) {
			break;
		}

		for (int j = 0; j < n; j ++) {
			if (!done[j] && city[next][j] < 65535) {
				if (dist[next] + city[next][j] < dist[j]) {
					dist[j] = dist[next] + city[next][j];
				}
			}
		}

	}

	cout << dist[c2];

	return 0;
}