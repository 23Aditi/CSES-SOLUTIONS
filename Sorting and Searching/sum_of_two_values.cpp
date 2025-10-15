#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    int x;
    cin >> x;
    vector<pair<int,int>> vec;
    for(int i = 0 ; i < n ; i++){
        int y;
        cin >> y;
        vec.push_back({y,i+1});
    }
    sort(vec.begin(),vec.end());
    int i = 0 , j = n - 1;
    while(i<j){
        if(vec[i].first+vec[j].first == x){
            cout << min(vec[i].second,vec[j].second) << " " << max(vec[i].second,vec[j].second);
            return 0;
        }else if(vec[i].first + vec[j].first > x){
            j--;
        }else{
            i++;
        }
    } 
    cout << "IMPOSSIBLE" << "\n";
}