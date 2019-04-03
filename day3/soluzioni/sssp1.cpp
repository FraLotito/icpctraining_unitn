#include <bits/stdc++.h>

using namespace std;

typedef long long T; // Change here for different weights

vector<T> dist(10001); 

const T INF = INT64_MAX; // Also remember to change infinity accordingly

struct maxPQ {
    int operator()(const pair<T,int>& a, const pair<T,int>& b) { return a.first > b.first; }
};

void Dijkstra(vector<vector<pair<int,T> > > &graph, int source) {
    fill(dist.begin(), dist.end(), INF);
    priority_queue<pair<T,int>, vector<pair<T,int> >, maxPQ > q;

    dist[source] = 0;
    q.push(make_pair(0, source));

    while (!q.empty()) {
        int u = q.top().second;
        T d = q.top().first;
        q.pop();
        if (d == dist[u]) { // Otherwise it is not the shortest path insertion into the queue
            for (int i=0; i<graph[u].size(); i++) {
                int v = graph[u][i].first; T w = graph[u][i].second;
                if (dist[v] > d+w) {
                    q.push(make_pair(dist[v] = d+w,v));
                }
            }
        }
    }
}

int main() {
    int N, M;
    int s, q, d;
    while (cin >> N >> M >> q >> s) {
        if (N == 0 && M == 0 && q == 0 && s == 0)  break;
        vector<vector<pair<int,T> > > graph(N+3);
        for(int i=0;i<M;i++) {
            int u,v; T c; cin>>u>>v>>c;
            graph[u].push_back(make_pair(v,c));
        }
        Dijkstra(graph, s);
        for (int i=0; i<q; i++) {
            cin >> d;
            if (dist[d] != INF) {
                cout << dist[d] << endl;
            } else {
                cout << "Impossible" << endl;
            }
        }
        cout << endl;
    }
    return 0;
}