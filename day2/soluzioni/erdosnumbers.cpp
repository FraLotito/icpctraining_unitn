#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> d;
vector<string> name;

vector<string> split(string str, char delimiter) {
  vector<string> internal;
  stringstream ss(str); // Turn the string into a stream.
  string tok;
 
  while(getline(ss, tok, delimiter)) {
    internal.push_back(tok);
  }
 
  return internal;
}

int main() {
    string line;

    unordered_map<string,vector<string> > graph;

    // Read stupid input
    while (getline(cin,line)) {
        vector<string> edges = split(line,' ');
        name.push_back(edges[0]);
        d[edges[0]] = -1;
        for (int i=1; i<edges.size(); i++) {
            d[edges[i]] = -1;
            graph[edges[0]].push_back(edges[i]);
            graph[edges[i]].push_back(edges[0]);
        }
    }

    queue<string> q;
    q.push("PAUL_ERDOS");

    d["PAUL_ERDOS"] = 0;

    while (!q.empty()) {
        string u = q.front();
        q.pop();

        for (int i=0; i<graph[u].size(); i++) {
            string v = graph[u][i];
            if (d[v] < 0) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    } 

    for (int i=0; i<name.size(); i++) {
        cout << name[i] << " ";
        if (d[name[i]] < 0) {
            cout << "no-connection" << endl;
        } else {
            cout << d[name[i]] << endl;
        }
    }

    return 0;
}