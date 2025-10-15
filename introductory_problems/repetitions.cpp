#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int ct = 1;
    int ans = 1;
    int n = s.size();
    for(int i = 1 ; i < n ; i++){
        if(s[i]==s[i-1]){
            ct++;
            ans = max(ct,ans);
        }else{
            ct = 1;
        }
    }
    cout << ans << endl;
}

