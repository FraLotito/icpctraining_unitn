#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int parent[2*MAXN];
int pcount[2*MAXN];
long psum[2*MAXN];	// Unsigned int should also be ok

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

        pcount[y] += pcount[x];
        psum[y] += psum[x];
    }
}

void move (int x, int y) {
    int x_root = find(x);
    int y_root = find(y);
    if (x_root != y_root) {
        parent[x] = y_root;

		pcount[y_root]++;
        pcount[x_root]--;
        psum[y_root] += x;
        psum[x_root] -= x;
    }
}

int main () {
    int N, M;
    while (cin >> N >> M) {
		// Init set
		for (int i=1; i <= N; i++) {
			parent[i] = MAXN + i;
			parent[MAXN + i] = MAXN + i;
			pcount[MAXN + i] = 1;
			psum[MAXN + i] = i;
		}

		// Read commands
        for (int i = 0; i < M; i++) {
			int c, p, q;
            cin >> c;
			switch (c) {
				case 1:
					cin >> p >> q;
					merge(p, q);
					break;
				case 2:
					cin >> p >> q;
					move(p, q);
					break;
				case 3:
					cin >> p;
					cout << pcount[find(p)] << " " << psum[find(p)] << endl;
					break;
			}
        }
    }
}

