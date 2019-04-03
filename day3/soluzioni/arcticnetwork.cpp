#include <bits/stdc++.h>

using namespace std;

typedef double T;

struct edge {
    int u, v;
    T d;
};

struct edgeCmp {
    int operator()(const edge& a, const edge& b) { return a.d > b.d; }
};

vector <edge> Tree;

int find(vector <int>& C, int x) { return (C[x] == x) ? x : C[x] = find(C, C[x]); }

T Kruskal(vector <vector <T> >& w) {
    int n = w.size();
    T weight = 0;
    
    vector <int> C(n), R(n);
    for(int i=0; i<n; i++) { C[i] = i; R[i] = 0; }
    
    priority_queue <edge, vector <edge>, edgeCmp> E;
    
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(w[i][j] >= 0) {
                edge e;
                e.u = i; e.v = j; e.d = w[i][j];
                E.push(e);
            }
        
    while(Tree.size() < n-1 && !E.empty()) {
        edge cur = E.top(); E.pop();
        
        int uc = find(C, cur.u), vc = find(C, cur.v);
        if(uc != vc)
        {
        Tree.push_back(cur); weight += cur.d;
        
        if(R[uc] > R[vc]) C[vc] = uc;
        else if(R[vc] > R[uc]) C[uc] = vc;
        else { C[vc] = uc; R[uc]++; }
        }
    }
    
    return weight;
}

double dist(int x1, int y1, int x2, int y2) {
    return (sqrt(pow(x1-x2,2)+pow(y1-y2,2)));
}

int x[501],y[501];

int main() {
    int test, s, p;

    cin >> test;

    for (int t=0; t<test; t++) {
        cin >> s >> p;
        vector<vector<double> > graph(p, vector<double> (p,-1));
        for (int i=0; i<p; i++) {
            cin >> x[i] >> y[i];
        }

        for (int i=0; i<p; i++) {
            for (int j=i+1; j<p; j++) {
                graph[i][j] = dist(x[i],y[i],x[j],y[j]);
                graph[j][i] = graph[i][j];
            }
        }

        Kruskal(graph);
        // for (int i=0; i<Tree.size(); i++) cout << Tree[i].d << endl;
        cout << setprecision(2) << fixed << Tree[p-1-s].d << endl;
        Tree.clear();
    }


    return 0;
}