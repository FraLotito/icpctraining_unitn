#include <bits/stdc++.h>
using namespace std;

set<string> family;
unordered_map<string,vector<string> > graph;
unordered_set<string> visited;

bool hillibilly, paradox;
void dfs(string u, string s) {
    visited.emplace(u);
    for (string v : graph[u]) {
        if (visited.count(v) != 0) {
            hillibilly = true;
            paradox |= (s.compare(v) == 0);
        } else {
            dfs(v,s);
        }
    }
} 

int main() {
    string u,v,begat;
    bool first = true;
    while (cin >> u) {
        graph.clear();
        visited.clear();
        family.clear();
        vector<string> ppl;
        while (u.compare("done") != 0) {
            cin >> begat >> v;
            graph[v].push_back(u); // v is parent of u
            if (family.count(v) == 0) { family.emplace(v); ppl.push_back(v); }
            if (family.count(u) == 0) { family.emplace(u); ppl.push_back(u); }
            cin >> u;
        }
        sort(ppl.begin(), ppl.end());
        if (!first) cout << endl; first = false;
        for (int i=0; i<ppl.size(); i++) {
            visited.clear();
            paradox = hillibilly = false;
            dfs(ppl[i],ppl[i]);
            if (paradox)
                cout << ppl[i] << " paradox" << endl; 
            else if (hillibilly)
                cout << ppl[i] << " hillbilly" << endl;
        }
    }

    return 0;
}