#include <bits/stdc++.h>

using namespace std;

int n,m;

char sky[102][102];
bool visited[102][102];

void dfs(int x, int y) {
    visited[x][y] = true;

    if (sky[x-1][y] == '-' && !visited[x-1][y]) {
        dfs(x-1,y);
    }

    if (sky[x+1][y] == '-' && !visited[x+1][y]) {
        dfs(x+1,y);
    }

    if (sky[x][y-1] == '-' && !visited[x][y-1]) {
        dfs(x,y-1);
    }

    if (sky[x][y+1] == '-' && !visited[x][y+1]) {
        dfs(x,y+1);
    }
}

int main() {
    int t = 0;
    while (cin >> n >> m) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                visited[i][j] = false;
                cin >> sky[i][j];
            }
        }

        for (int i=0; i<=m; i++) {
            sky[0][i] = '#';
            sky[n+1][i] = '#';
        }
        for (int i=0; i<=n; i++) {
            sky[i][0] = '#';
            sky[i][m+1] = '#';
        }
        /*
        for (int i=0; i<=n+1; i++) {
            for (int j=0; j<=m+1; j++) {
                cout << sky[i][j];
            }
            cout << endl;
        }
        cout << endl;
        */
        int count = 0; 
        for (int i=1; i<=n; i++) {
            for (int j=0; j<=m; j++) {
                if (sky[i][j] == '-' && !visited[i][j]) {
                    count++;
                    dfs(i,j);
                }
            }
        }
        cout << "Case " << ++t << ": " << count << endl; 
    }

    return 0;
}