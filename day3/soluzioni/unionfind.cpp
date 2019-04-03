#include <iostream>

using namespace std;

int p[1000001];
int r[1000001] = { 0 };

int find(int a) {
    if (p[a] == a) {
        return a;
    }
    return (p[a] = find(p[a])); // Compressione dei cammini
}

void merge(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa == pb) {
        return;
    }
    // Euristiche sul rango
    if (r[pa] < r[pb]) { // Swap pa and pb
        int tmp = pa;
        pa = pb;
        pb = tmp;
    }
    p[pb] = pa;
    if (r[pa] == r[pb]) {
        r[pa]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,q;
    scanf("%d", &n);
    scanf("%d", &q);
    for (int i=0; i<n; i++) {
        p[i] = i;
    }
    int a,b;
    char op;
    for (int i=0; i<q; i++) {
        getchar();
        scanf("%c", &op);
        scanf("%d", &a);
        scanf("%d", &b);
        if (op == '=') {
            merge(a,b);
        } else {
            if (find(a) == find(b)) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
    }
    return 0;
}