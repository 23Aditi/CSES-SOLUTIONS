#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, x;
    cin >> n >> x;
    vector<long long> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    long long sum = 0;
    long long ct = 0;
    long long j = 0;
    for(int i = 0 ; i < n ; i++){
        sum += arr[i];
        while(sum>x){
            sum-=arr[j];
            j++;
        }
        if(sum==x){
            ct++;
        }
    }
    cout << ct << endl;
}

