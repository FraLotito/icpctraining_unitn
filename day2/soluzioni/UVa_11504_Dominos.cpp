#include <bits/stdc++.h>

using namespace std;

int n,m;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;

vvi graph;
vvi graphT;

vector<bool> visited;

// Holds top-sort for the second visit
stack<int> S;
// Holds scc-ID for every node
vector<int> scc;

int sccCount = 0;

void Kosaraju(int u, int pass) {      // pass = 1 (original), 2 (transpose)
    visited[u] = true;
    vi neighbor;
    if (pass == 1) neighbor = graph[u]; else neighbor = graphT[u];
    for (int j = 0; j < (int)neighbor.size(); j++) {
        int v = neighbor[j];
        if (!visited[v])
            Kosaraju(v, pass);
    }
    if (pass == 1) S.push(u); 
    else scc[u] = sccCount; // Set connected component to current
}

int main() {
    int test;
    cin >> test;
    for (int t=0; t<test; t++) {
        cin >> n >> m;
        graph.clear(); graphT.clear();
        graph.resize(n+1); graphT.resize(n+1);
        visited.clear();
        visited.resize(n+1,false);
        scc.clear(); scc.resize(n+1,-1);
        int u,v;
        for (int i=0; i<m; i++) {
            cin >> u >> v;
            graph[u].push_back(v);
            graphT[v].push_back(u);
        }

        for (int i=1; i<=n; i++) {
            if (!visited[i]) {
                Kosaraju(i,1);
            }
        }

        // Find scc and assign IDs to nodes
        fill(visited.begin(), visited.end(), false);
        while (!S.empty()) {
            if (!visited[S.top()]) {
                Kosaraju(S.top(), 2);
                sccCount++;
            }
            S.pop();
        }
        
        // Find scc that do not have an entering edge
        vector<bool> connectedSCC(sccCount, false);
        for (int i=1; i<=n; i++) {
            for (int j=0; j<graph[i].size(); j++) {
                if (scc[i] != scc[graph[i][j]] && !connectedSCC[scc[graph[i][j]]]) {
                    sccCount--;
                    connectedSCC[scc[graph[i][j]]] = true;
                }
            }
        }
        
        cout << sccCount << endl;
        sccCount = 0;
    }

    return 0;
}