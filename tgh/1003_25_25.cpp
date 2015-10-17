#include <iostream>
using namespace std;

const int MAXINT = 65535;
int n, m, c1, c2;
int **city;
int *team;
bool *done;
int MinDist = 0;
int d = 0, num = 0, t, amount = 0;

void dfs(int p)
{
	// Reach the target node
    if (p == c2) {
        if (d == MinDist) {
            num ++;
            // Update rescure team
            if (amount < t) {
                amount = t;
            }
        }
        return;
    }
    if (d > MinDist) {
        return;
    }
    // Check each path
    for (int i = 0; i < n; i ++) {
        if (!done[i] && city[p][i] < MAXINT) {
        	// DFS for next node i
            d += city[p][i];
            t += team[i];
            done[i] = true;
            dfs(i);
            // Return back to the previous node
            d -= city[p][i];
            t -= team[i];
            done[i] = false;
        }
    }
    
}

int main()
{
    cin >> n >> m >> c1 >> c2;
    
    // Rescue teams
    team = new int[n];
    for (int i = 0; i < n; i ++) {
        cin >> team[i];
    }
    
    city = new int*[n];
    for (int i = 0; i < n; i ++) {
        city[i] = new int[n];
    }
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            city[i][j] = MAXINT;
        }
    }

    // Roads of cities
    for (int i = 0; i < m; i ++) {
        int tmp1, tmp2, len;
        cin >> tmp1 >> tmp2 >> len;
        city[tmp1][tmp2] = city[tmp2][tmp1] = len;
    }
    
    // Dijkstra (shortest path algorithm)
    int dist[n];
    done = new bool[n];
    for (int i = 0; i < n; i ++) {
        dist[i] = city[c1][i];
        done[i] = false;
    }
    
    dist[c1] = 0;
    done[c1] = true;
    
    for (int i = 1; i < n; i ++) {
        int mindist = MAXINT;
        int next = c1;

        // Next node with the shortest distance
        for (int j = 0; j < n; j ++) {
            if (!done[j] && dist[j] < mindist) {
                next = j;
                mindist = dist[j];
            }
        }
        done[next] = true;

        // Update all the distance of nodes
        for (int j = 0; j < n; j ++) {
            if (!done[j] && city[next][j] < MAXINT) {
                if (dist[next] + city[next][j] < dist[j]) {
                    dist[j] = dist[next] + city[next][j];
                }
            }
        }
        
    }

    // Shortest distance from c1 to c2
    MinDist = dist[c2];
    
    for (int i = 0; i < n; i ++) {
        done[i] = false;
    }

    done[c1] = true;
    t = team[c1];

    // Depth first search
    dfs(c1);
    
    cout << num << " " << amount;
    
    return 0;
}