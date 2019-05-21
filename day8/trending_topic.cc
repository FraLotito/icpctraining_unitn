#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

vector< map<string, int> > m(7);
vector< pair<string, int> > sorted;
map<string, int> total;

bool cmp(pair<string, int> a, pair<string, int> b) {
    if(a.second == b.second) {
        return a.first < b.first;
    } else return a.second > b.second;
} 

int main() {
    string in;
    int day = -1;
    while(cin>>in) {
        if(in.compare("<text>") == 0) {
            day = (day + 1) % 7;
            m[day].clear();
        }
        else if(in.compare("<top") == 0) {
            int n;
            cin>>n;
            string garbage;
            cin>>garbage;
            total.clear();
            for(int d=0;d<7;d++) {
                for(map<string, int>::iterator i = m[d].begin(); i != m[d].end(); i++) {
                    if(total[i->first]) total[i->first]+= i->second;
                    else total[i->first] = i->second;
                }
            }
            sorted.clear();
            for(map<string, int>::iterator i = total.begin(); i != total.end(); i++) sorted.push_back(make_pair(i->first, i->second));
            sort(sorted.begin(), sorted.end(), cmp);
            cout<<"<top "<<n<<">"<<endl;
            int c = 0;
            if(sorted.size() < 0) continue;
            int prev = sorted[0].second;
            int printed = 0;
            for(int i=0;i<sorted.size();i++) {
                if(printed < n) {
                    cout<<sorted[i].first<<" "<<sorted[i].second<<endl;
                    prev = sorted[i].second;
                    printed++;
                }
                else {
                    if(prev == sorted[i].second) {
                        cout<<sorted[i].first<<" "<<sorted[i].second<<endl;
                    }
                }
            }
            cout<<"</top>"<<endl;

        } else if(in.compare("</text>") != 0 && in.length() >= 4) {
            if(m[day][in]) {
                m[day][in] += 1;
            } else {
                m[day][in] = 1;
            }
        }
    }
}
