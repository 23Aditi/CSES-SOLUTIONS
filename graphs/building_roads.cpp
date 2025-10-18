#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj , vector<bool>& visited, int s){
    visited[s]=1; // marking as true
    // operation
    // performing dfs for adj nodes
    for(auto i : adj[s]){
        if(!visited[i]){
            dfs(adj,visited,i);
        }
    }

}


int main(){
    int n , m;
    cin >> n >>m;
    vector<vector<int>> adj(n+1);
    for(int i = 1 ; i <= m ; i++){
        int a , b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> visited(n+1,0);
    vector<int> components;
    for(int i = 1 ; i <= n ; i++){
        if(visited[i]==0){
            dfs(adj,visited,i);
            components.push_back(i);
        }
    }
    cout << (int)components.size() - 1 << endl; 
    for(int i = 1 ; i<(int)components.size() ; i++){
        cout << components[i-1] << " " << components[i] << endl;
    }
}


