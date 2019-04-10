#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define mp make_pair
using namespace std;

using ll = long long;
using ii = pair<int, int>;
const int INF = (int)10e9;

vector<int> g[100005];
int dp[100005];

int N, M;

stack<int> ts;
bool vis[100005];

void dfs(int n) {
    if(!vis[n]) {
        vis[n] = true;
        for(int i = 0; i < g[n].size(); i++) dfs(g[n][i]);
        ts.push(n);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    for(int i = 1; i <= N; i++) {
        if(!vis[i]) dfs(i);
    }

    while(!ts.empty()) {
        int n = ts.top();
        for(int i = 0;i < g[n].size(); i++) dp[g[n][i]] = max(dp[g[n][i]], dp[n] + 1);
        ts.pop();
    }

    int res = 0;
    for(int i = 0; i <= N; i++) res = max(res, dp[i]);
    cout<<res<<endl;

    return 0;
}
