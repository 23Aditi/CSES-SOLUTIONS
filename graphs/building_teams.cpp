#include <bits/stdc++.h>
using namespace std;
// check bipartite graph


int main(){
    int n , m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i = 0 ; i < m ; i++){
        int a , b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> color(n+1,0);

    for(int s = 1 ; s<= n ; s++){
        if(color[s]==0){
            queue<int> q;
        q.push(s);
        color[s]=1;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            for(auto i : adj[t]){
                if(color[i]==color[t]){
                    cout << "IMPOSSIBLE\n";
                    return 0;
                }else if(color[i]==0){
                    color[i]=color[t]==1?2:1;
                    q.push(i);
                }
            }
        }
        }
    }
    for(int i = 1 ; i<=n ; i++){
        cout << color[i] << " ";
    }

}

