#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > graph;
vector<int> length;
bool scheduled[400001] = {false};
int deg_in[400001] = { 0 };
priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > q;

int main() {
    int n;
    cin >> n;
    graph.resize(n+1);
    length.resize(n+1);
    int deg,dest,w;
    int i = n-1, maxl = -1;
    for (int i=1; i<=n; i++) {
        cin >> w;
        cin >> deg;
        length[i] = w;
        for (int j=0; j<deg; j++) {
            cin >> dest;
            // Dest has to be performed before i;
            graph[i].push_back(dest);
            deg_in[dest]++;
        }
    }
    for (int i=1; i<=n; i++) {
        if (deg_in[i] == 0) q.push(make_pair(length[i],i));
    }

    while (!q.empty()) {
        auto meeting = q.top(); q.pop();
        maxl = max(maxl, length[meeting.second] + (i--) );
        for (int j=0; j<graph[meeting.second].size(); j++) {
            int m2 = graph[meeting.second][j];
            deg_in[m2]--;
            if (deg_in[m2] == 0)
                q.push(make_pair(length[m2],m2));
        }
    }

    cout << maxl << endl;

    return 0;
}