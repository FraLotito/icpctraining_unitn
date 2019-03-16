#include<bits/stdc++.h>
using namespace std;

int N, B;
int main() {
    while(cin>>N>>B) {
        priority_queue< pair<int, pair<int, int> > > v;
        if(N == -1) break;
        for(int i=0;i<N;i++) {
            int a; cin>>a;
            v.push(make_pair(a, make_pair(a, 1)));
        }
        B-=N;
        for(int i=0;i<B;i++) {
            pair<int, pair<int, int> > t = v.top();
            v.pop();
            int d = t.second.first / (t.second.second + 1);
            if(t.second.first % (t.second.second + 1) != 0) d++;
            v.push(make_pair(d, make_pair(t.second.first, t.second.second + 1)));
        }
        cout<<v.top().first<<endl;
    }
}