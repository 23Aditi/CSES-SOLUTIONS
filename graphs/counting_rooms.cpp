#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<char>>& matrix,vector<vector<bool>>& visited,int i , int j){
    int n = matrix.size();
    int m = matrix[0].size();
    queue<pair<int,int>> q;
    visited[i][j]=1;
    q.push({i,j});
    vector<int> row = {0 , 1 , 0 , -1};
    vector<int> col = {1 , 0 , -1 , 0};
    while(!q.empty()){
        auto p = q.front();
        int x = p.first;
        int y = p.second;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int newx = x + row[i];
            int newy = y + col[i];
            if(newx>=0 && newx< n && newy>=0 && newy<m && !visited[newx][newy] && matrix[newx][newy]=='.'){
                visited[newx][newy]=1;
                q.push({newx,newy});
            }
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<char>> matrix(n, vector<char>(m));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            char c;
            cin >> c;
            matrix[i][j]=c;
        }
    }
    vector<vector<bool>> visited(n,vector<bool>(m,0));
    int ct = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(!visited[i][j] && matrix[i][j]=='.'){
                bfs(matrix,visited,i,j);
                ct++;
            }
        }
    }
    cout << ct << endl;
}
