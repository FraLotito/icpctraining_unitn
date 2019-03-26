#include <bits/stdc++.h>

using namespace std;

int n,m;
int gold;
char dungeon[51][51];
bool visited[51][51];

bool trap(int x, int y) {
    return dungeon[x-1][y] == 'T' || dungeon[x+1][y] == 'T' || dungeon[x][y-1] == 'T' || dungeon[x][y+1] == 'T';
}

void floodFill(int x, int y) {
    visited[x][y] = true;
    if (dungeon[x][y] == 'G') gold++;
    if (trap(x,y)) return;

    if (dungeon[x-1][y] != '#' && !visited[x-1][y]) {
        floodFill(x-1,y);
    }

    if (dungeon[x+1][y] != '#' && !visited[x+1][y]) {
        floodFill(x+1,y);
    }

    if (dungeon[x][y-1] != '#' && !visited[x][y-1]) {
        floodFill(x,y-1);
    }

    if (dungeon[x][y+1] != '#' && !visited[x][y+1]) {
        floodFill(x,y+1);
    }
}

int main() {
    while (cin >> m >> n) {
        gold = 0;
        int px,py;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> dungeon[i][j];
                visited[i][j] = false;
                if (dungeon[i][j] == 'P') {
                    px = i; py = j;
                } 
            }
        }
        
        floodFill(px,py);
        cout << gold << endl;
    }
    return 0;
}