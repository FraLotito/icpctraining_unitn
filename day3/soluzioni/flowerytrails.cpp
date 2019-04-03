#include <bits/stdc++.h>

using namespace std;

typedef long long T; // Change here for different weights

const T INF = INT64_MAX; // Also remember to change infinity accordingly

struct maxPQ {
    int operator()(const pair<T,int>& a, const pair<T,int>& b) { return a.first > b.first; }
};

void Dijkstra(vector<vector<pair<int,T> > > &graph, int source, vector<T> &dist) {
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
    int p,t;
    cin >> p >> t;
    vector<vector<pair<int,T> > > graph(p);
    vector<pair<pair<int,int>,T> > edges;
    for (int i=0; i<t; i++) {
        int u,v; T d;
        cin >> u >> v >> d;
        graph[u].push_back(make_pair(v,d));
        graph[v].push_back(make_pair(u,d));
        edges.push_back(make_pair(make_pair(u,v),d));
    }
    
    vector<T> dist1(p);
    vector<T> dist2(p);
    Dijkstra(graph,0,dist1);
    Dijkstra(graph,p-1,dist2);
    
    long long weigth=0;
    for (auto e : edges) {
        // cout << dist1[e.first.first] << " + " << e.second << " + " << dist2[e.first.second] << " = " << dist1[p-1] << endl;
        if (dist1[e.first.first] + e.second + dist2[e.first.second] == dist1[p-1]
            || dist1[e.first.second] + e.second + dist2[e.first.first] == dist1[p-1])
            weigth += e.second;
    }

    cout << weigth*2 << endl;
}