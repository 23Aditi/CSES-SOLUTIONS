#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------
   Problem: Towers (CSES)
--------------------------------------------
You are given n cubes in a certain order. You need to build towers.
Rules:
1. A cube can be placed on top of another cube only if it is smaller.
2. You can start a new tower at any time.
Goal:
Minimize the total number of towers formed.

--------------------------------------------
   Approach:
--------------------------------------------
1. Use a multiset to keep track of the current **top cubes** of all towers.
   - multiset is used because it **automatically keeps elements sorted**.
   - This allows us to efficiently find where to place a new cube.

2. For each cube x in the given order:
   a) Find the **first tower** whose top cube is strictly greater than x:
      - Use `upper_bound(x)` on the multiset.
      - This returns an iterator to the smallest top > x.
   b) If such a tower exists, we **replace its top** with x:
      - Remove the old top using `erase(it)`.
      - Insert x as the new top.
   c) If no such tower exists, start a new tower:
      - Simply insert x into the multiset.

3. At the end, the **number of towers** is equal to the number of elements in the multiset:
   - Each element represents the top cube of a tower.

--------------------------------------------
   Key Points:
--------------------------------------------
- Greedy idea: always place a cube on the leftmost suitable tower.
- Using multiset ensures O(log n) insertion, deletion, and upper_bound operations.
- This guarantees **minimum number of towers**.
- Time Complexity: O(n log n)
- Space Complexity: O(n)
--------------------------------------------
*/

int main(){
    int n;
    cin >> n;
    int ct = 0;
    multiset<int> vec;
    for(int i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        auto it = vec.upper_bound(x);
        if(it!= vec.end()){
            vec.erase(it);
        }
        vec.insert(x);    
    }
    cout << vec.size() << endl;
}