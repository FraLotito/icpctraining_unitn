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

double dist(double x1, double y1, double x2, double y2) {
    return (sqrt(pow(x1-x2,2)+pow(y1-y2,2)));
}

double x[1001],y[1001];

int main() {
    int test, n;

    cin >> test;

    for (int t=0; t<test; t++) {
        cin >> n;
        vector<vector<double> > graph(n, vector<double> (n,-1));
        for (int i=0; i<n; i++) {
            cin >> x[i] >> y[i];
        }

        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                graph[i][j] = dist(x[i],y[i],x[j],y[j]);
                graph[j][i] = graph[i][j];
            }
        }

        cout << fixed << setprecision(2) << Kruskal(graph) << endl;
        if (t < test - 1) cout << endl;
        Tree.clear();
    }


    return 0;
}