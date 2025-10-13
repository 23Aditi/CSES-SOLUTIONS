#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------
   Problem: Stick Lengths (CSES)
--------------------------------------------
Given n sticks of various lengths, you need to make all sticks equal in length.
In one operation, you can increase or decrease the length of a stick by 1 unit.
The goal is to minimize the total cost (sum of changes).

--------------------------------------------
   Approach:
--------------------------------------------
1. Read n and the stick lengths.
2. The optimal target length to minimize total absolute difference 
   is the **median** of all lengths.
   - For an even number of sticks, both middle values give nearly same result,
     so we check both and take the smaller total cost.
3. Compute the total cost by summing |x - median|.
4. Output the minimum cost.

--------------------------------------------
   Why Median?
--------------------------------------------
Mathematically, the sum of absolute differences |x - a_i| is minimized when 
x = median(a_i). This is a key property used in many "minimize total distance"
or "equalize elements" problems.

--------------------------------------------
   Time Complexity: O(n log n)
   - Sorting the vector dominates the runtime.
   Space Complexity: O(n)
--------------------------------------------
*/


int main(){
    int n;
    cin >> n ;
    vector<long long> vec;
    for(int i = 0 ; i < n ; i++){
        long long x;
        cin >> x;
        vec.push_back(x);
    }
    long long cost1 = 0,cost2 = 0;
    sort(vec.begin(),vec.end());
    long long len1 = vec[(n)/2];
    long long len2 = vec[(n+1)/2];
    for(auto x : vec){
        cost1 += abs(x-len1);
        cost2 += abs(x-len2);
    }
    cout << min(cost1,cost2) << endl;

}