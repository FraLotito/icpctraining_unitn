#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

char cmap[MAXN][MAXN];
int parent[MAXN * MAXN];

int find (int x) {
    if (parent[x] == x) {
		return x;
	}

	//Path compression
    return (parent[x] = find(parent[x]));
}

void merge (int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
		parent[x] = y;
    }
}


int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    // Read input
    int r, c;
    cin >> r >> c;
    for (int i = 1; i<=r; i++) {
        for (int j = 1; j<=c; j++) {
            cin >> cmap[i][j];
            parent[MAXN * i + j] = MAXN * i + j;
        }
    }

    // Union-Find
    for (int i = 1; i<=r; i++) {
        for (int j = 1; j<=c; j++) {
            if (i < r && cmap[i][j] == cmap[i+1][j]) {
                merge(MAXN * i + j, MAXN * (i + 1) + j);
            }
            if (j < c && cmap[i][j] == cmap[i][j+1]) {
                merge(MAXN * i + j, MAXN * i + j + 1);
            }
        }
    }

    //Answer queries
    int n;
    cin >> n;
    for (int i = 0; i<n; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        if (find(MAXN * r1 + c1) == find(MAXN * r2 + c2)) {
            if (cmap[r1][c1] == '1') {
                cout << "decimal" << endl;
            } else {
                cout << "binary" << endl;
            }
        } else {
            cout << "neither" << endl;
        }
    }
}