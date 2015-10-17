#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    
    cin >> N >> M;
    
    int **nodes;
    nodes = new int*[N];
    for (int i = 0; i < N; i ++) {
        nodes[i] = new int[N];
    }
    
    // Initialize the matrix
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            nodes[i][j] = 0;
        }
    }
    
    // Store relationship as an adjacency matrix
    for (int i = 0; i < M; i ++) {
        int parent, k;
        cin >> parent >> k;
        for (int j = 0; j < k; j ++) {
            int child;
            cin >> child;
            nodes[parent-1][child-1] = 1;
        }
    }
    
    vector<int> parent;
    parent.push_back(0);
    int count = 1;
    
    while (count != 0) {
        count = 0;
        vector<int> children;
        // Find the children of each parent
        for (int i = 0; i < parent.size(); i ++) {
            bool hasChild = false;
            for (int j = 0; j < N; j ++) {
                // Store the children for the next time search
                if (nodes[parent[i]][j] == 1) {
                    hasChild = true;
                    children.push_back(j);
                }
            }
            // Count the number of parents with children
            if (hasChild) {
                count ++;
            }
        }
        
        // Leaf nodes with no children
        cout << parent.size() - count;
        if (count != 0) {
            cout << " ";
        }

        // Prepare for the next search
        parent = children;
    }
    
    return 0;
}