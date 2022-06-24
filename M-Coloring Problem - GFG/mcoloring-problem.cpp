// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.

bool isPossible(vector<int> &assignedColor, vector<int> &adjOfCurNode, int color){
    for(auto &child : adjOfCurNode){
        int colorOfChild = assignedColor[child];
        if(colorOfChild == color)return false;
    }
    
    return true;
}

bool aux(vector<int> adj[], vector<int> &assignedColor, int limit, int lastNode, int curNode = 0){
    if(curNode == lastNode){
        return true;
    }
    
    for(int i = 0; i < limit; ++i){
        if(isPossible(assignedColor, adj[curNode], i)){
            assignedColor[curNode] = i;
            if(aux(adj, assignedColor, limit, lastNode, curNode + 1)){
                return true;
            }
        }
    }
    assignedColor[curNode] = -1;
    return false;
}



bool graphColoring(bool graph[101][101], int m, int n) {
    vector<int> adj[n];
    vector<int> assignedColor(n, -1); // -1 means no color assigned.
    
    bool isEdge = 1;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(graph[i][j] == isEdge){
                adj[i].push_back(j);
            }
        }
    }
    
    return aux(adj, assignedColor, m, n);
    
    // return false;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends