#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<bool> vec(n+1,0);
    vec[0]=1;
    for(int i = 0 ; i < n-1 ; i++){
        int x;
        cin >> x;
        vec[x]=1;
    }
    for(int i = 1 ; i <= n ; i++){
        if(vec[i]==0){
            cout << i << endl;
        }
    }

}

