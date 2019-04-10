#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int n; 
    while (cin >> n) {
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;

        int op, x;
        bool isStack = true, isQueue = true, isPQueue = true;
        for (int i=0; i<n; i++) {
            cin >> op >> x;
            if (op == 1) {
                if (isStack) s.push(x);
                if (isQueue) q.push(x);
                if (isPQueue) pq.push(x);
            } else {
                if (isStack && !s.empty() && s.top() == x) {
                    s.pop();
                } else {
                    isStack = false;
                }
                if (isQueue && !q.empty() && q.front() == x) {
                    q.pop();
                } else {
                    isQueue = false;
                }
                if (isPQueue && !pq.empty() && pq.top() == x) {
                    pq.pop();
                } else {
                    isPQueue = false;
                }
            }
        }
        if (!isQueue && !isStack && !isPQueue) {
            cout << "impossible" << endl;
        } else if (isQueue && !isStack && !isPQueue) {
            cout << "queue" << endl;
        } else if (!isQueue && isStack && !isPQueue) {
            cout << "stack" << endl;
        } else if (!isQueue && !isStack && isPQueue) {
            cout << "priority queue" << endl;
        } else {
            cout << "not sure" << endl;
        }
    }
    return 0;   
}