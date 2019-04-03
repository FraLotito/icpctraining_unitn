#include <bits/stdc++.h>

using namespace std;

bool inserted[200001];
int partners[200001];
int rem[200001]; // Parters that are still left to each country

vector<vector<int> >  graph;

int main() {
    int x,c,p,l;

    cin >> c >> p >> x >> l;
    
    int u,v;
    graph.resize(c+1);
    for (int i=0; i<p; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        partners[u]++;
        partners[v]++;
        rem[u]++;
        rem[v]++;
    }
    
    rem[l]=0;
    queue<int> q;
    q.push(l);
    inserted[l] = true;
    while (!q.empty()) {
        int u=q.front(); q.pop();
        if (rem[u] <= partners[u]/2) {
            for (int v : graph[u]) {
                rem[v]--;
                if (!inserted[v] && rem[v] <= partners[v]/2) {
                    q.push(v);
                    inserted[v] = true;
                }
            }
        }
    }
    
    if (rem[x] <= partners[x]/2) cout <<"leave"<<endl;
    else cout<<"stay"<<endl;    
    return 0;
}