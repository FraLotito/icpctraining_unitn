#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define mp make_pair
using namespace std;

using ll = long long;
using ii = pair<int, int>;
const int INF = (int)10e9;
int N, W;
ll dp[105][100005];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> W;
    vector<int> w(N), v(N);
    for(int i = 0; i < N; i++) {
        cin>>w[i]>>v[i];
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= W; j++) {
            if(i == 0) { if(j >= w[i]) dp[i][j] = v[i];}
            else if(j - w[i] >= 0) dp[i][j] = max(v[i] + dp[i-1][j-w[i]], dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout<<dp[N-1][W]<<endl;

    return 0;
}
