#include <bits/stdc++.h>
using namespace std;

/*


### HOW TO SOLVE A DP PROBLEM?
1.  Think about subproblems or states/parameters.
  dp[k] = min coins to get a sum of k  
2.  Think about the relationship between smaller subproblems to compute the bigger problem (transition/relation).
   dp[0]=0 
3.  Identify where the above relation does not work (trivial/base case).
    dp[k]= min(dp[k],dp[k-c1]+1); where c1 = coin 1 and c varies from 1 to n
4.  Determine the final state or the bigger subproblem to solve.
    dp[x]

*/



void func(vector<int>& coins, int n , int x){
    vector<int> sum(x+1,1e9);
    sum[0]=0;
    for(int i = 1 ; i <=x ; i++){
        for(int j = 0 ; j < n ; j++){
            if(coins[j]<=i){
                sum[i]=min(sum[i],1+sum[i-coins[j]]);
            }            
        }
    }
    int y = sum[x]==1e9?-1:sum[x];
    cout << y << endl;
}

int main(){
    int n , x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0 ; i < n ; i++){
        cin >> coins[i];
    }
    func(coins,n,x);
}


