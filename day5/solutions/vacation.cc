//https://atcoder.jp/contests/dp/tasks/dp_c

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define mp make_pair
using namespace std;

using ll = long long;
using ii = pair<int, int>;
const int INF = (int)10e9;
int dp[3][100005];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;
    vector<int> a(N), b(N), c(N);
    for(int i = 0; i < N; i++) {
        cin>>a[i]>>b[i]>>c[i];
    }

    dp[0][0] = a[0];
    dp[1][0] = b[0];
    dp[2][0] = c[0];
    for(int i = 1; i < N; i++) {
        dp[0][i] = a[i] + max(dp[1][i-1], dp[2][i-1]);
        dp[1][i] = b[i] + max(dp[0][i-1], dp[2][i-1]);
        dp[2][i] = c[i] + max(dp[0][i-1], dp[1][i-1]);
    }
    cout << max(max(dp[0][N-1], dp[1][N-1]), dp[2][N-1]) <<endl;

    return 0;
}
