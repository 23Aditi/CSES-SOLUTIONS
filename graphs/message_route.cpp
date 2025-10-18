#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& adj, vector<bool>& visited, vector<int>& parent, int s){
    queue<int> q;
    q.push(s);
    visited[s]=1;
    while(!q.empty()){
        int n = q.front();
        q.pop();
        for(int i : adj[n]){
            if(!visited[i]){
                visited[i]=1;
                q.push(i);
                parent[i]=n;
            }
        }
    }
}


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
    // undirected graph
    vector<bool> visited(n+1);
    vector<int> parent(n+1,-1);
    bfs(adj,visited,parent,1); // only one bfs call ! 

    if(visited[n]==0){
        cout << "IMPOSSIBLE"<<endl; return 0;
    }
    vector<int> path;
    for(int curr = n ; curr != -1 ; curr = parent[curr]){
        path.push_back(curr);
    }
    reverse(path.begin(),path.end());
    cout << path.size() << endl;
    for(auto i : path){
        cout << i << " ";
    }
}

