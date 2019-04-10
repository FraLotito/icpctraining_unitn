#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define MAXN 5000010
using namespace std;

long long ft[MAXN+1];

long long prefix_sum(size_t k) {
	long long ans = 0;
	for (; k > 0; k -= lsb(k)) {
		ans += ft[k];
	}
	return ans;
}

long long sum(size_t a, size_t b) {
	return prefix_sum(b) - prefix_sum(a - 1);
}

void update(size_t k, int delta) {
	for (; k <= MAXN; k += lsb(k)) {
		ft[k] += delta;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int q, n;
    scanf("%d %d", &n, &q);

    for (int i = 0; i<q; i++) {
        char op;
        int a, b;
        scanf("%*c%c", &op);
        if (op == '+') {
            scanf("%d %d", &a, &b);
            update(a + 1, b);
        } else {
            scanf("%d", &a);
            if (a == 0) {
                printf("0\n");
            } else {
                printf("%lld\n", prefix_sum(a));
            }
        }
    }
}