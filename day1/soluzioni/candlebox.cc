#include<bits/stdc++.h>
using namespace std;

int main() {
    int R, T, D;
    cin>>D>>R>>T;
    int i=3;
    while(true) {
        int ct = i*(i+1)/2 - 3;
        int cr = (i+D)*(i+D+1)/2 - 6;
        if(ct + cr == R+T) {
            cout<<R - cr<<endl;
            break;
        }
        i++;
    }
    return 0;
}