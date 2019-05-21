//https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&Itemid=99999999&category=655&page=show_problem&problem=4967

#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<ctime>

using namespace std;

int main() {
    srand((unsigned)time(NULL));
    int N;
    while(cin >> N) {
        int P;
        cin >> P;
        vector<long long> x(N), y(N);
        for(int i=0;i<N;i++) {
            cin>>x[i]>>y[i];
        }
        bool found = false;
        if(N == 1) found = true;
        else {
            int cont = 0;
            while(!found && cont < 1000){
                int p1 = random() % N;
                int p2;
                do {
                    p2 = random() % N;
                } while(p1 == p2);
                int res = 0;
                for(int i=0;i<N;i++) {
                    //meglio evitare le divisioni
                    if( (y[i] - y[p1]) * (x[p2]-x[p1]) == (x[i]-x[p1]) * (y[p2] - y[p1]) ){
                            res++;
                        }
                }
                if(res*100 >= P*N) found = true;
                cont++;
            }
        }

        if(!found) cout<<"impossible"<<endl;
        else cout<<"possible"<<endl;

    }
    return 0;
}
