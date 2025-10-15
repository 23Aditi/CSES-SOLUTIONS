#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<long long> vec;
    for(int i = 0 ; i < n ; i++){
        long long x;
        cin >> x;
        vec.push_back(x);
    }
    long long curr = vec[0];
    long long ans = vec[0];
    for(int i = 1 ; i < n ; i++){
        curr = max(vec[i],vec[i]+curr); // either start a new subarray or add in the present
        ans = max(ans,curr); //maximum of past sum and present sum
    }
    cout << ans << endl;
}
