#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> vec(n);
    long long moves = 0;
    for(int i = 0 ; i < n ; i++){
        cin >> vec[i];
    }
    for(int i = 1 ; i < n ; i++){
        if(vec[i-1]>vec[i]){
            moves += (vec[i-1]-vec[i]);
            vec[i] = vec[i-1];
        }
    }
    cout << moves << endl;
}
