#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long a , b;
        cin >> a >> b;
        if(a==0 && b==0){
            cout << "YES" << endl;continue;
        }
        if(a==0 || b==0){
            cout << "NO"<< endl;continue;
        }
        /*SIMULATING THE STEPS GIVES TLE FOR 10^9*/
        // while(a>0 && b>0){
        //     if(a==b || b>a){
        //         a-=1; b-=2;
        //     }else{
        //         a-=2;b-=1;
        //     }
        // }
        // if(a==0 && b==0){
        //     cout << "YES" << endl;continue;
        // }
        // cout << "NO" << endl;
        if(a>b) swap(a,b);
        /*bigger pile has twice or less than twice no of coins in smaller
        reason : coins are removed in 1:2 or 2:1 pattern*/
        if(b<=2*a && (a+b)%3==0){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    
}