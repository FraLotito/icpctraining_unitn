#include <bits/stdc++.h>

using namespace std;

/////////////////// UNION FIND SET IMPLEMENTATION //////////////////////
int *p;
int *r;

int find(int a) {
    if (p[a] == a) {
        return a;
    }
    return (p[a] = find(p[a])); // Path compression
}

void merge(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa == pb) {
        return;
    }
    // Rank heuristics
    if (r[pa] < r[pb]) { // Swap pa and pb
        int tmp = pa;
        pa = pb;
        pb = tmp;
    }
    p[pb] = pa;
    if (r[pa] == r[pb]) {
        r[pa]++;
    }
}
//////////////////////////////////////////////////////////////////////////

/////////////////////// KRUSKAL'S ALGORITHM //////////////////////////////
typedef int T; // Change here for different weight types

struct edge {
    int u, v;
    T d;
};

vector <edge> mst;

struct edgeCmp {
    int operator()(const edge& a, const edge& b) { return a.d > b.d; }
};

int find(vector <int>& C, int x) { return (C[x] == x) ? x : C[x] = find(C, C[x]); }

// The graph is represented as an adjacency matrix [0..n-1]x[0..n-1]
T Kruskal(vector <vector <pair<int, T> > >& w) {
    mst.clear(); // In case you have to use the algorithm more than once
    int n = w.size();
    p = new int[n];
    r = new int[n];
    T weight = 0;

    // Initialize MFSet
    for(int i=0; i<n; i++) { p[i] = i; r[i] = 0; }
    
    priority_queue <edge, vector <edge>, edgeCmp> E;
    
    for(int i=0; i<n; i++) {
        for(pair<int,int> p : w[i]) {
            edge e;
            e.u = i; e.v = p.first; e.d = p.second;
            E.push(e);
        }
    }
        
    while(mst.size() < n-1 && !E.empty()) {
        edge cur = E.top(); E.pop();
        
        int uc = find(cur.u), vc = find(cur.v);
        if(uc != vc) {
            mst.push_back(cur); weight += cur.d;
            merge(cur.u, cur.v);
        }
    }
    
    return weight;
}
//////////////////////////////////////////////////////////////////////////
int n,m;

bool sorter(edge &e1, edge& e2) {
    if (min(e1.u,e1.v) < min(e1.u,e1.v)) return true;
    if (min(e1.u,e1.v) == min(e1.u,e1.v)) return (max(e1.u,e1.v) < max(e1.u,e1.v));
    else return false;
}

int main() {
    while (cin >> n >> m) {
        if (n==0 && m==0) break;

        vector<vector<pair<int, T> > > w(n);
    
        int u,v,d;
        for(int i=0; i<m; i++) {
            cin >> u >> v >> d;
            w[u].push_back(make_pair(v,d));
        }
                
        int k = Kruskal(w); 
        
        if (mst.size() == n-1) {
            cout << k << endl;
            vector<pair<int,int> > sorted(n-1);
            for (int i=0; i<n-1; i++) {
                int u = mst[i].u, v = mst[i].v;
                sorted[i] = make_pair(min(u,v),max(u,v));
            }
            sort(sorted.begin(),sorted.end());
            for (auto e : sorted) {
                cout << e.first << " " << e.second << endl;
            }
        } else {
            cout << "Impossible" << endl;
        }
    }
}