#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int N, B;
map<string, int> m;
int id;

typedef struct {
    int b, c, p;
} edge;

int c[10002], p[10002];
pair<int, int> memo[10002][10002];

vector<edge> v[10002];
bool vis[10002];
vector<int> topsort;
bool zeros[10002];

void dfs(int n) {
    if(!vis[n]) {
        vis[n] = true;
        for(int i=0;i<v[n].size();i++) {
            zeros[v[n][i].b] = false;
            dfs(v[n][i].b);
        }
        topsort.push_back(n);
    }
}

void topological_sort() {
    fill(vis, vis+10002, false);
    fill(zeros, zeros+10002, true);
    topsort.clear();
    for(int i=0;i<id;i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }
    reverse(topsort.begin(), topsort.end());
}

pair<int, int> solve(int B, int pos) {
    if(memo[B][pos].first != -1) return memo[B][pos]; 
    if(pos >= 0) {
        if(B >= c[pos]) {
            pair<int, int> taken = solve(B - c[pos], pos-1);
            pair<int, int> not_taken = solve(B, pos-1);
            if(p[pos] + taken.first > not_taken.first) {
                memo[B][pos].first = p[pos] + taken.first;
                memo[B][pos].second = c[pos] + taken.second;
            } else {
                memo[B][pos] = not_taken;
            }
            return memo[B][pos];
        }
        else {
            memo[B][pos] = solve(B, pos-1);
            return memo[B][pos];
        }
    } else return make_pair(0,0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>B>>N) {
        m.clear();
        id = 0;
        for(int i=0;i<N;i++) {
            string a,b,c; int d,e;
            cin>>a>>b>>c>>d>>e;
            if(m.find(b) == m.end()) {
                m[b] = id++;
            }
            if(m.find(a) == m.end()) {
                m[a] = id++;
            }
            edge tmp = {m[a], d, e};
            v[m[b]].push_back(tmp);
        }
        topological_sort();
        fill(vis, vis+id, false);
        queue<int> q;
        for(int i=0;i<topsort.size();i++)q.push(topsort[i]);
        fill(c, c+id, 1<<30);
        fill(p, p+id, 0);
        for(int i=0;i<id;i++) {
            if(zeros[i]) {
                c[i] = 0;
            }
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            if(!vis[node]) {
                vis[node] = true;
                for(int i=0;i<v[node].size();i++) {
                    if(c[v[node][i].b] > c[node] + v[node][i].c) {
                        c[v[node][i].b] = c[node] + v[node][i].c;
                        p[v[node][i].b] = p[node] + v[node][i].p;
                    } else if(c[v[node][i].b] == c[node] + v[node][i].c) {
                        p[v[node][i].b] = max(p[v[node][i].b], p[node] + v[node][i].p);
                    }  
                }
            }
        }

        for(int i=0;i<10002;i++) {
            for(int j=0;j<id;j++) {
                memo[i][j].first = -1;
                memo[i][j].second = 0;
            }
        }
        pair<int, int> res = solve(B, id-1);
        cout<<res.first<<endl;
        cout<<res.second<<endl;      
    }
}