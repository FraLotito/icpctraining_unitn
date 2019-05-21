//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4896

#include<iostream>
using namespace std;
int N;
string s[10];
int first[30];
int set[30];
int v[30];
int vis[10];
string lettere;
int res;

void solve(int pos) {
    if(pos == lettere.length()) {

        //controllo che la somma sia corretta
        int target = 0;
        for(int i=0;i<s[N-1].length();i++) {
            target = target*10 + v[s[N-1][i]-'A'];
        }


        int sum = 0;
        for(int i=0;i<N-1;i++) {
            int tmp = 0;
            for(int j=0;j<s[i].length();j++) {
                tmp = tmp * 10 + v[s[i][j]-'A'];
            }
            sum += tmp;
            if(sum > target) break;
        }


        if(sum == target) {
            res++;
            //cout<<"SUM: "<<sum<<endl;
            //cout<<"TARGET: "<<target<<endl;
        }
    } else {

        //genero tutte le assegnazioni possibili
        for(int i=0;i<10;i++) {
            if(first[lettere[pos]-'A'] != 1 || i != 0) {
                if(vis[i]==0) {
                    vis[i] = 1;
                    v[lettere[pos]-'A'] = i;
                    solve(pos+1);
                    vis[i] = 0;
                }
            }
        }
    }
}

int main() {
    while(cin>>N) {
        res = 0;
        for(int i=0;i<30;i++) {
            first[i] = 0;
            set[i] = 0;
            v[i] = 0;
        }
        for(int i=0;i<10;i++)vis[i] = 0;
        lettere = "";
        for(int i=0;i<N;i++) {
            cin>>s[i];
            //identifico prima lettera
            first[s[i][0] - 'A'] = 1;
            //creo un set delle lettere usate
            for(int j=0;j<s[i].length();j++) set[s[i][j] - 'A'] = 1;
        }

        //creo stringa con le lettere usate
        for(int i=0;i<30;i++) if(set[i] == 1) lettere = lettere + char(i+'A');

        //risolvo
        solve(0);
        cout<<res<<endl;
    }
    return 0;
}
